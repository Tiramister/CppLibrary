#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_A"

#include "../../Geometry/geometry.hpp"

#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    geo::Polygon g(n);
    for (auto& p : g) std::cin >> p;

    auto h = geo::convexhull(g, true);
    std::cout << h.size() << "\n";

    int s = 0;
    for (int i = 1; i < (int)h.size(); ++i) {
        if (geo::cmp(h[i].y, h[s].y) < 0 ||
            (geo::cmp(h[i].y, h[s].y) == 0 &&
             geo::cmp(h[i].x, h[s].x) < 0)) s = i;
    }

    for (int i = 0; i < (int)h.size(); ++i) {
        auto p = h[(s + i) % h.size()];
        std::cout << p.x << " " << p.y << "\n";
    }

    return 0;
}
