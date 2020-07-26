#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A"

#include "../Graph/dinic.hpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    MaxFlow<int, true> mf(n);
    while (m--) {
        int u, v, c;
        std::cin >> u >> v >> c;
        mf.span(u, v, c);
    }

    std::cout << mf.exec(0, n - 1) << "\n";
    return 0;
}
