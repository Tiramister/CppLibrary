#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "../Graph/two_sat.cpp"

#include <iostream>
#include <cmath>
#include <string>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

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
        std::cout << "0\n";
    }

    return 0;
}
