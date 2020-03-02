#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B"

#define __guard__
#include "../Misc/heap_alias.cpp"
#include "../Graph/min_cost_flow.cpp"
#undef __guard__

#include <iostream>

int main() {
    int n, m, f;
    std::cin >> n >> m >> f;

    MinCostFlow<int, int> mcf(n);
    while (m--) {
        int u, v, c, d;
        std::cin >> u >> v >> c >> d;
        mcf.span(u, v, c, d);
    }
    std::cout << mcf.exec(0, n - 1, f) << std::endl;
    return 0;
}
