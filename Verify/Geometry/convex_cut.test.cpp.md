---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Geometry/geometry.hpp
    title: Geometry/geometry.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_C
  bundledCode: "#line 1 \"Verify/Geometry/convex_cut.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_C\"\n#define\
    \ ERROR 0.00001\n\n#line 2 \"Geometry/geometry.hpp\"\n\n#include <iostream>\n\
    #include <algorithm>\n#include <vector>\n#include <cmath>\n\nnamespace geo {\n\
    \nusing Real = long double;\nconstexpr Real EPS = 1e-10;\nconstexpr Real PI =\
    \ 3.14159265358979323846L;\n\nint cmp(Real a, Real b) {\n    return std::abs(a\
    \ - b) < EPS ? 0\n           : a > b               ? 1\n                     \
    \            : -1;\n}\n\n/* -------------------- Point -------------------- */\n\
    struct Point {\n    Real x, y;\n\n    explicit Point(Real x = 0, Real y = 0) :\
    \ x(x), y(y) {}\n\n    Point operator-() const { return Point(-x, -y); }\n\n \
    \   Point operator+(const Point& p) const { return Point(*this) += p; }\n    Point\
    \ operator-(const Point& p) const { return Point(*this) -= p; }\n    Point& operator+=(const\
    \ Point& p) {\n        x += p.x, y += p.y;\n        return *this;\n    }\n   \
    \ Point& operator-=(const Point& p) {\n        x -= p.x, y -= p.y;\n        return\
    \ *this;\n    }\n\n    Point operator*(Real k) const { return Point(*this) *=\
    \ k; }\n    Point& operator*=(Real k) {\n        x *= k, y *= k;\n        return\
    \ *this;\n    }\n\n    bool operator==(const Point& p) const { return cmp(x, p.x)\
    \ == 0 && cmp(y, p.y) == 0; }\n    bool operator!=(const Point& p) const { return\
    \ !(*this == p); }\n    bool operator<(const Point& p) const { return cmp(x, p.x)\
    \ < 0 ||\n                                                  (cmp(x, p.x) == 0\
    \ && cmp(y, p.y) < 0); }\n    bool operator>(const Point& p) const { return cmp(x,\
    \ p.x) > 0 ||\n                                                  (cmp(x, p.x)\
    \ == 0 && cmp(y, p.y) > 0); }\n\n    Real norm() const { return x * x + y * y;\
    \ }\n    Real abs() const { return std::hypot(x, y); }\n    Real arg() const {\
    \ return std::atan2(y, x); }\n\n    Point rotate(Real theta) const {\n       \
    \ return Point(x * std::cos(theta) - y * std::sin(theta),\n                  \
    \   x * std::sin(theta) + y * std::cos(theta));\n    }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, Point& p) {\n        return is >> p.x >> p.y;\n\
    \    }\n};\n\nPoint polar(Real r, Real theta) { return Point(std::cos(theta),\
    \ std::sin(theta)) * r; }\nReal dist(const Point& p, const Point& q) { return\
    \ (p - q).abs(); }\nReal dot(const Point& p, const Point& q) { return p.x * q.x\
    \ + p.y * q.y; }\nReal cross(const Point& p, const Point& q) { return p.x * q.y\
    \ - p.y * q.x; }\n\n/* -------------------- Segment -------------------- */\n\
    struct Segment {\n    Point p, q;\n\n    explicit Segment(const Point& p = Point(),\
    \ const Point& q = Point()) : p(p), q(q) {}\n\n    Real norm() const { return\
    \ (p - q).norm(); }\n    Real length() const { return (p - q).abs(); }\n\n   \
    \ Point diff() const { return q - p; }\n\n    friend std::istream& operator>>(std::istream&\
    \ is, Segment& s) {\n        return is >> s.p >> s.q;\n    }\n};\n\nbool orthogonal(const\
    \ Segment& s, const Segment& t) {\n    return cmp(dot(s.diff(), t.diff()), 0)\
    \ == 0;\n}\n\nbool parallel(const Segment& s, const Segment& t) {\n    return\
    \ cmp(cross(s.diff(), t.diff()), 0) == 0;\n}\n\nPoint proj(const Segment& s, const\
    \ Point& p) {\n    Real ratio = dot(s.diff(), p - s.p) / s.norm();\n    return\
    \ s.p + s.diff() * ratio;\n}\n\nPoint refl(const Segment& s, const Point& p) {\n\
    \    auto t = proj(s, p);\n    return t + (t - p);\n}\n\n// position of a point\
    \ relative to a segment\nenum Position {\n    ON_SEGMENT = 0,\n    COUNTER_CLOCKWISE\
    \ = 1,\n    CLOCKWISE = -1,\n    ONLINE_FRONT = 2,\n    ONLINE_BACK = -2\n};\n\
    \nPosition pos(const Segment& s, const Point& p) {\n    auto t = Segment(s.p,\
    \ p);\n\n    auto c = cross(s.diff(), t.diff());\n    if (cmp(c, 0) != 0) {\n\
    \        return cmp(c, 0) > 0 ? COUNTER_CLOCKWISE : CLOCKWISE;\n    }\n\n    auto\
    \ d = dot(s.diff(), t.diff());\n    if (cmp(d, 0) < 0) return ONLINE_BACK;\n\n\
    \    return cmp(t.length(), s.length()) > 0 ? ONLINE_FRONT : ON_SEGMENT;\n}\n\n\
    // end: contain ends of segments\nbool intersect(const Segment& s, const Segment&\
    \ t, bool end) {\n    return pos(s, t.p) * pos(s, t.q) < end &&\n           pos(t,\
    \ s.p) * pos(t, s.q) < end;\n}\n\nPoint crosspoint(const Segment& s, const Segment&\
    \ t) {\n    auto c1 = cross(t.diff(), s.diff());\n    auto c2 = cross(t.diff(),\
    \ s.p - t.p);\n    return s.p + s.diff() * (-c2 / c1);\n}\n\nReal dist(const Segment&\
    \ s, const Point& p) {\n    auto q = proj(s, p);\n    if (pos(s, q) == ON_SEGMENT)\
    \ return dist(p, q);\n    return std::min(dist(p, s.p), dist(p, s.q));\n}\n\n\
    Real dist(const Segment& s, const Segment& t) {\n    if (intersect(s, t, true))\
    \ return 0;\n    return std::min({dist(s, t.p), dist(s, t.q),\n              \
    \       dist(t, s.p), dist(t, s.q)});\n}\n\n/* -------------------- Polygon --------------------\
    \ */\nstruct Polygon : public std::vector<Point> {\n    using std::vector<Point>::vector;\n\
    \n    explicit Polygon(int n = 0) : std::vector<Point>(n) {}\n\n    // requirement:\
    \ vertices are aligned in counter-clockwise order\n    Real area() const {\n \
    \       Real sum = 0;\n        for (int i = 0; i < (int)size(); ++i) {\n     \
    \       sum += cross((*this)[i], (*this)[(i + 1) % size()]);\n        }\n    \
    \    return sum / 2;\n    }\n\n    bool isconvex() const {\n        for (int i\
    \ = 0; i < (int)size(); ++i) {\n            if (pos(Segment((*this)[i], (*this)[(i\
    \ + 1) % size()]),\n                    (*this)[(i + 2) % size()]) == CLOCKWISE)\
    \ return false;\n        }\n        return true;\n    }\n};\n\n// position of\
    \ a point relative to a polygon\nenum Contain {\n    OUT,\n    ON,\n    IN\n};\n\
    \nContain contain(const Polygon& g, const Point& p) {\n    bool in = false;\n\
    \    for (int i = 0; i < (int)g.size(); ++i) {\n        if (pos(Segment(g[i],\
    \ g[(i + 1) % g.size()]), p) == ON_SEGMENT) return ON;\n\n        auto a = g[i]\
    \ - p, b = g[(i + 1) % g.size()] - p;\n        if (a > b) std::swap(a, b);\n\n\
    \        if (cmp(a.x, 0) <= 0 &&\n            cmp(b.x, 0) > 0 &&\n           \
    \ cmp(cross(a, b), 0) < 0) in = !in;\n    }\n    return in ? IN : OUT;\n}\n\n\
    // linear: choose colinear points\nPolygon convexhull(Polygon& g, bool linear)\
    \ {\n    std::sort(g.begin(), g.end());\n    int n = g.size();\n\n    Polygon\
    \ h(n * 2);\n    int k = 0;\n\n    for (int i = 0; i < n; ++i) {\n        while\
    \ (k >= 2 &&\n               cmp(cross(h[k - 1] - h[k - 2], g[i] - h[k - 2]),\
    \ 0) < !linear) {\n            --k;\n        }\n        h[k++] = g[i];\n    }\n\
    \n    int t = k + 1;\n    for (int i = n - 2; i >= 0; --i) {\n        while (k\
    \ >= t &&\n               cmp(cross(h[k - 1] - h[k - 2], g[i] - h[k - 2]), 0)\
    \ < !linear) {\n            --k;\n        }\n        h[k++] = g[i];\n    }\n\n\
    \    h.resize(k - 1);\n    h.shrink_to_fit();\n    return h;\n}\n\n// requirement:\
    \ g is convex\nReal diameter(const Polygon& g) {\n    Real ret = 0;\n    int j\
    \ = 0;\n    for (int i = 0; i < (int)g.size(); ++i) {\n        while (j < (int)g.size()\
    \ - 1 &&\n               cmp(dist(g[i], g[j + 1]), dist(g[i], g[j])) > 0) ++j;\n\
    \        ret = std::max(ret, dist(g[i], g[j]));\n    }\n    return ret;\n}\n\n\
    // left side\n// requirement: g is convex\nPolygon convex_cut(const Polygon& g,\
    \ const Segment& s) {\n    Polygon h;\n    for (int i = 0; i < (int)g.size();\
    \ ++i) {\n        if (pos(s, g[i]) != CLOCKWISE) h.push_back(g[i]);\n\n      \
    \  Segment t(g[i], g[(i + 1) % g.size()]);\n        if (pos(s, t.p) * pos(s, t.q)\
    \ == -1) {\n            h.push_back(crosspoint(s, t));\n        }\n    }\n   \
    \ return h;\n}\n\n// requirement: g is convex\nbool intersect(const Polygon& g,\
    \ const Segment& s) {\n    auto area = convex_cut(g, s).area();\n    return cmp(area,\
    \ 0) == 0 || cmp(area, g.area()) == 0;\n}\n\n/* -------------------- Circle --------------------\
    \ */\n\nstruct Circle {\n    Point p;\n    Real r;\n    explicit Circle(const\
    \ Point& p = Point(), Real r = 0) : p(p), r(r) {}\n\n    // center -> radius\n\
    \    friend std::istream& operator>>(std::istream& is, Circle& a) {\n        return\
    \ is >> a.p >> a.r;\n    }\n};\n\n// the number of common tangents\n// requirement:\
    \ a != b\nint intersect(const Circle& a, const Circle& b) {\n    auto d = dist(a.p,\
    \ b.p);\n\n    return cmp(d, a.r + b.r) > 0              ? 4\n           : cmp(d,\
    \ a.r + b.r) == 0           ? 3\n           : cmp(d, std::abs(a.r - b.r)) > 0\
    \  ? 2\n           : cmp(d, std::abs(a.r - b.r)) == 0 ? 1\n                  \
    \                            : 0;\n}\n\n// s is treated as a line\nstd::vector<Point>\
    \ crosspoint(const Circle& a, const Segment& s) {\n    std::vector<Point> ps;\n\
    \n    auto d = dist(proj(s, a.p), a.p);\n    if (cmp(d, a.r) == 0) {\n       \
    \ ps.push_back(proj(s, a.p));\n\n    } else if (cmp(d, a.r) < 0) {\n        auto\
    \ p = proj(s, a.p);\n        auto v = s.q - s.p;\n        v *= std::sqrt(a.r *\
    \ a.r - d * d) / v.abs();\n\n        ps.push_back(p + v);\n        ps.push_back(p\
    \ - v);\n    }\n    return ps;\n}\n\n// requirement: a != b\nstd::vector<Point>\
    \ crosspoint(const Circle& a, const Circle& b) {\n    std::vector<Point> ps;\n\
    \n    auto c = intersect(a, b);\n    if (c == 0 || c == 4) return ps;\n\n    auto\
    \ d = dist(a.p, b.p);\n    auto theta = std::acos((a.r * a.r + d * d - b.r * b.r)\
    \ / (a.r * d * 2));\n    auto phi = (b.p - a.p).arg();\n\n    ps.push_back(a.p\
    \ + polar(a.r, phi + theta));\n    if (c == 2) ps.push_back(a.p + polar(a.r, phi\
    \ - theta));\n\n    return ps;\n}\n\n}  // namespace geo\n#line 5 \"Verify/Geometry/convex_cut.test.cpp\"\
    \n\n#line 7 \"Verify/Geometry/convex_cut.test.cpp\"\n#include <iomanip>\n\nint\
    \ main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    std::cout << std::fixed << std::setprecision(10);\n\n    int n;\n    std::cin\
    \ >> n;\n\n    geo::Polygon g(n);\n    for (auto& p : g) std::cin >> p;\n\n  \
    \  int q;\n    std::cin >> q;\n    while (q--) {\n        geo::Segment s;\n  \
    \      std::cin >> s;\n        std::cout << geo::convex_cut(g, s).area() << \"\
    \\n\";\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_C\"\
    \n#define ERROR 0.00001\n\n#include \"../../Geometry/geometry.hpp\"\n\n#include\
    \ <iostream>\n#include <iomanip>\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    std::cout << std::fixed << std::setprecision(10);\n\
    \n    int n;\n    std::cin >> n;\n\n    geo::Polygon g(n);\n    for (auto& p :\
    \ g) std::cin >> p;\n\n    int q;\n    std::cin >> q;\n    while (q--) {\n   \
    \     geo::Segment s;\n        std::cin >> s;\n        std::cout << geo::convex_cut(g,\
    \ s).area() << \"\\n\";\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - Geometry/geometry.hpp
  isVerificationFile: true
  path: Verify/Geometry/convex_cut.test.cpp
  requiredBy: []
  timestamp: '2020-11-05 15:24:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/Geometry/convex_cut.test.cpp
layout: document
redirect_from:
- /verify/Verify/Geometry/convex_cut.test.cpp
- /verify/Verify/Geometry/convex_cut.test.cpp.html
title: Verify/Geometry/convex_cut.test.cpp
---
