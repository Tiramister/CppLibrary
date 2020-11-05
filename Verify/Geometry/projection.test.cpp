#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_A"
#define ERROR 0.00000001

#include "../../Geometry/geometry.hpp"

#include <iostream>
#include <iomanip>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);

    geo::Segment s;
    std::cin >> s;

    int t;
    std::cin >> t;
    while (t--) {
        geo::Point p;
        std::cin >> p;
        auto q = geo::proj(s, p);
        std::cout << q.x << " " << q.y << "\n";
    }

    return 0;
}
