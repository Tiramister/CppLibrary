#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_A"

#include "../../Geometry/geometry.hpp"

#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    geo::Circle a, b;
    std::cin >> a >> b;
    std::cout << geo::intersect(a, b) << "\n";

    return 0;
}
