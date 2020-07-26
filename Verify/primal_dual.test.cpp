#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B"

#include "../Graph/primal_dual.hpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m, f;
    std::cin >> n >> m >> f;

    MinCostFlow<int, int> mcf(n);
    while (m--) {
        int u, v, c, d;
        std::cin >> u >> v >> c >> d;
        mcf.span(u, v, c, d);
    }

    std::cout << mcf.exec(0, n - 1, f) << "\n";
    return 0;
}
