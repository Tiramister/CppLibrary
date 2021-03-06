#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_7_D"
#define ERROR 0.000001

#include "../../Geometry/geometry.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);

    geo::Circle a;
    std::cin >> a;

    int t;
    std::cin >> t;
    while (t--) {
        geo::Segment s;
        std::cin >> s;

        auto ps = geo::crosspoint(a, s);
        if (ps.size() == 1) ps.push_back(ps.front());
        std::sort(ps.begin(), ps.end());
        for (auto p : ps) std::cout << p.x << " " << p.y << " ";
        std::cout << "\n";
    }

    return 0;
}
