#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_B"

#include "../../Geometry/geometry.hpp"

#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int q;
    std::cin >> q;
    while (q--) {
        geo::Segment s, t;
        std::cin >> s >> t;
        std::cout << geo::intersect(s, t, true) << "\n";
    }

    return 0;
}
