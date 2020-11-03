#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B"

#include "../Graph/min_cost_flow.hpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m, flim;
    std::cin >> n >> m >> flim;

    MinCostFlow<int, int> mcf(n);
    while (m--) {
        int u, v, c, d;
        std::cin >> u >> v >> c >> d;
        mcf.span(u, v, c, d);
    }

    auto [f, c] = mcf.flow(0, n - 1, flim);
    std::cout << (f == flim ? c : -1) << "\n";
    return 0;
}
