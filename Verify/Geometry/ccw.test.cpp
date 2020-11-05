#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/all/CGL_1_C"

#include "../../Geometry/geometry.hpp"

#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    geo::Segment s;
    std::cin >> s;

    int t;
    std::cin >> t;
    while (t--) {
        geo::Point p;
        std::cin >> p;
        auto q = geo::pos(s, p);

        std::string ans;
        switch (q) {
            case geo::COUNTER_CLOCKWISE: {
                ans = "COUNTER_CLOCKWISE";
                break;
            }
            case geo::CLOCKWISE: {
                ans = "CLOCKWISE";
                break;
            }
            case geo::ONLINE_BACK: {
                ans = "ONLINE_BACK";
                break;
            }
            case geo::ONLINE_FRONT: {
                ans = "ONLINE_FRONT";
                break;
            }
            case geo::ON_SEGMENT: {
                ans = "ON_SEGMENT";
                break;
            }
        }

        std::cout << ans << "\n";
    }

    return 0;
}
