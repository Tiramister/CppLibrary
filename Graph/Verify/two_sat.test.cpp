#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#ifndef __guard__
#define __guard__
#include "../graph.cpp"
#include "../strongly_connected_component.cpp"
#include "../two_sat.cpp"
#undef __guard__
#endif

#include <iostream>
#include <cmath>
#include <string>

int main() {
    std::string tmp;
    int n, m;
    std::cin >> tmp >> tmp >> n >> m;

    TwoSat ts(n);
    while (m--) {
        int x, y;
        std::cin >> x >> y >> tmp;
        ts.span(std::abs(x) - 1, x > 0, std::abs(y) - 1, y > 0);
    }

    auto assign = ts.exec();
    if (assign.empty()) {
        std::cout << "s UNSATISFIABLE" << std::endl;
    } else {
        std::cout << "s SATISFIABLE" << std::endl;
        std::cout << "v ";
        for (int x = 1; x <= n; ++x) {
            std::cout << (assign[x - 1] ? x : -x) << " ";
        }
        std::cout << "0" << std::endl;
    }
    return 0;
}