#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_2_D"
#define ERROR 0.00000001

#include "../../Geometry/geometry.hpp"

#include <iostream>
#include <iomanip>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);

    int q;
    std::cin >> q;
    while (q--) {
        geo::Segment s, t;
        std::cin >> s >> t;
        std::cout << geo::dist(s, t) << "\n";
    }

    return 0;
}
