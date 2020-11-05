#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

namespace geo {

using Real = long double;
constexpr Real EPS = 1e-10;

int cmp(Real a, Real b) {
    return std::abs(a - b) < EPS ? 0
           : a > b               ? 1
                                 : -1;
}

/* -------------------- Point -------------------- */
struct Point {
    Real x, y;

    explicit Point(Real x = 0, Real y = 0) : x(x), y(y) {}
    static Point polar(Real r, Real theta) { return Point(std::cos(theta), std::sin(theta)) * r; }

    Point operator-() const { return Point(-x, -y); }

    Point operator+(const Point& p) const { return Point(*this) += p; }
    Point operator-(const Point& p) const { return Point(*this) -= p; }
    Point& operator+=(const Point& p) {
        x += p.x, y += p.y;
        return *this;
    }
    Point& operator-=(const Point& p) {
        x -= p.x, y -= p.y;
        return *this;
    }

    Point operator*(Real k) const { return Point(*this) *= k; }
    Point& operator*=(Real k) {
        x *= k, y *= k;
        return *this;
    }

    bool operator==(const Point& p) const { return cmp(x, p.x) == 0 && cmp(y, p.y) == 0; }
    bool operator!=(const Point& p) const { return !(*this == p); }
    bool operator<(const Point& p) const { return cmp(x, p.x) < 0 ||
                                                  (cmp(x, p.x) == 0 && cmp(y, p.y) < 0); }
    bool operator>(const Point& p) const { return cmp(x, p.x) > 0 ||
                                                  (cmp(x, p.x) == 0 && cmp(y, p.y) > 0); }

    Real norm() const { return x * x + y * y; }
    Real abs() const { return std::hypot(x, y); }
    Real arg() const { return std::atan2(y, x); }

    Point rotate(Real theta) const {
        return Point(x * std::cos(theta) - y * std::sin(theta),
                     x * std::sin(theta) + y * std::cos(theta));
    }

    friend std::istream& operator>>(std::istream& is, Point& p) {
        return is >> p.x >> p.y;
    }
};

Real dist(const Point& p, const Point& q) { return (p - q).abs(); }
Real dot(const Point& p, const Point& q) { return p.x * q.x + p.y * q.y; }
Real cross(const Point& p, const Point& q) { return p.x * q.y - p.y * q.x; }

/* -------------------- Segment -------------------- */
struct Segment {
    Point p, q;

    explicit Segment(const Point& p = Point(), const Point& q = Point()) : p(p), q(q) {}

    Real norm() const { return (p - q).norm(); }
    Real length() const { return (p - q).abs(); }

    Point diff() const { return q - p; }

    friend std::istream& operator>>(std::istream& is, Segment& s) {
        return is >> s.p >> s.q;
    }
};

bool orthogonal(const Segment& s, const Segment& t) {
    return cmp(dot(s.diff(), t.diff()), 0) == 0;
}

bool parallel(const Segment& s, const Segment& t) {
    return cmp(cross(s.diff(), t.diff()), 0) == 0;
}

Point proj(const Segment& s, const Point& p) {
    Real ratio = dot(s.diff(), p - s.p) / s.norm();
    return s.p + s.diff() * ratio;
}

Point refl(const Segment& s, const Point& p) {
    auto t = proj(s, p);
    return t + (t - p);
}

// position of a point relative to a segment
enum Position {
    ON_SEGMENT = 0,
    COUNTER_CLOCKWISE = 1,
    CLOCKWISE = -1,
    ONLINE_FRONT = 2,
    ONLINE_BACK = -2
};

Position pos(const Segment& s, const Point& p) {
    auto t = Segment(s.p, p);

    auto c = cross(s.diff(), t.diff());
    if (cmp(c, 0) != 0) {
        return cmp(c, 0) > 0 ? COUNTER_CLOCKWISE : CLOCKWISE;
    }

    auto d = dot(s.diff(), t.diff());
    if (cmp(d, 0) < 0) return ONLINE_BACK;

    return cmp(t.length(), s.length()) > 0 ? ONLINE_FRONT : ON_SEGMENT;
}

// end: contain ends of segments
bool intersect(const Segment& s, const Segment& t, bool end) {
    return pos(s, t.p) * pos(s, t.q) < end &&
           pos(t, s.p) * pos(t, s.q) < end;
}

Point intersection(const Segment& s, const Segment& t) {
    auto c1 = cross(t.diff(), s.diff());
    auto c2 = cross(t.diff(), s.p - t.p);
    return s.p + s.diff() * (-c2 / c1);
}

Real dist(const Segment& s, const Point& p) {
    auto q = proj(s, p);
    if (pos(s, q) == ON_SEGMENT) return dist(p, q);
    return std::min(dist(p, s.p), dist(p, s.q));
}

Real dist(const Segment& s, const Segment& t) {
    if (intersect(s, t, true)) return 0;
    return std::min({dist(s, t.p), dist(s, t.q),
                     dist(t, s.p), dist(t, s.q)});
}

/* -------------------- Polygon -------------------- */
struct Polygon : public std::vector<Point> {
    explicit Polygon(int n = 0) : std::vector<Point>(n) {}

    Real area() const {
        Real sum = 0;
        for (int i = 0; i < (int)size(); ++i) {
            sum += cross((*this)[i], (*this)[(i + 1) % size()]);
        }
        return sum / 2;
    }

    bool isconvex() const {
        for (int i = 0; i < (int)size(); ++i) {
            if (pos(Segment((*this)[i], (*this)[(i + 1) % size()]),
                    (*this)[(i + 2) % size()]) == CLOCKWISE) return false;
        }
        return true;
    }
};

// position of a point relative to a polygon
enum Contain {
    OUT,
    ON,
    IN
};

Contain contain(const Polygon& g, const Point& p) {
    bool in = false;
    for (int i = 0; i < (int)g.size(); ++i) {
        if (pos(Segment(g[i], g[(i + 1) % g.size()]), p) == ON_SEGMENT) return ON;

        auto a = g[i] - p, b = g[(i + 1) % g.size()] - p;
        if (a > b) std::swap(a, b);

        if (cmp(a.x, 0) <= 0 &&
            cmp(b.x, 0) > 0 &&
            cmp(cross(a, b), 0) < 0) in = !in;
    }
    return in ? IN : OUT;
}

// linear: choose colinear points
Polygon convexhull(Polygon& g, bool linear) {
    std::sort(g.begin(), g.end());
    int n = g.size();

    Polygon h(n * 2);
    int k = 0;

    for (int i = 0; i < n; ++i) {
        while (k >= 2 &&
               cmp(cross(h[k - 1] - h[k - 2], g[i] - h[k - 2]), 0) < !linear) {
            --k;
        }
        h[k++] = g[i];
    }

    int t = k + 1;
    for (int i = n - 2; i >= 0; --i) {
        while (k >= t &&
               cmp(cross(h[k - 1] - h[k - 2], g[i] - h[k - 2]), 0) < !linear) {
            --k;
        }
        h[k++] = g[i];
    }

    h.resize(k - 1);
    h.shrink_to_fit();
    return h;
}

// g must be convex
Real diameter(const Polygon& g) {
    Real ret = 0;
    int j = 0;
    for (int i = 0; i < (int)g.size(); ++i) {
        while (j < (int)g.size() - 1 &&
               cmp(dist(g[i], g[j + 1]), dist(g[i], g[j])) > 0) ++j;
        ret = std::max(ret, dist(g[i], g[j]));
    }
    return ret;
}

// left side, g must be convex
Polygon convex_cut(const Polygon& g, const Segment& s) {
    Polygon h;
    for (int i = 0; i < (int)g.size(); ++i) {
        if (pos(s, g[i]) != CLOCKWISE) h.push_back(g[i]);

        Segment t(g[i], g[(i + 1) % g.size()]);
        if (pos(s, t.p) * pos(s, t.q) == -1) {
            h.push_back(intersection(s, t));
        }
    }
    return h;
}

bool intersect(const Polygon& g, const Segment& s) {
    auto area = convex_cut(g, s).area();
    return cmp(area, 0) == 0 || cmp(area, g.area()) == 0;
}

}  // namespace geo
