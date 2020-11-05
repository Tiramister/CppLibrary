#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_B"

#include "../../Geometry/geometry.hpp"

#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    geo::Polygon g(n);
    for (auto& p : g) std::cin >> p;
    std::cout << g.isconvex() << "\n";

    return 0;
}
