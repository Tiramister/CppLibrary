#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_4_C"
#define ERROR 0.00001

#include "../../Geometry/geometry.hpp"

#include <iostream>
#include <iomanip>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);

    int n;
    std::cin >> n;

    geo::Polygon g(n);
    for (auto& p : g) std::cin >> p;

    int q;
    std::cin >> q;
    while (q--) {
        geo::Segment s;
        std::cin >> s;
        std::cout << geo::convex_cut(g, s).area() << "\n";
    }

    return 0;
}
