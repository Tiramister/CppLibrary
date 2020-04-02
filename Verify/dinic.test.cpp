#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A"

#include "../Graph/dinic.cpp"

#include <iostream>

int main() {
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
