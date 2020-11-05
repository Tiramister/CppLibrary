#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_A"

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

        std::cout << (geo::parallel(s, t)     ? 2
                      : geo::orthogonal(s, t) ? 1
                                              : 0)
                  << "\n";
    }

    return 0;
}
