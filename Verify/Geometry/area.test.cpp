#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_3_A"

#include "../../Geometry/geometry.hpp"

#include <iostream>
#include <iomanip>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(1);

    int n;
    std::cin >> n;

    geo::Polygon g(n);
    for (auto& p : g) std::cin >> p;
    std::cout << g.area() << "\n";

    return 0;
}
