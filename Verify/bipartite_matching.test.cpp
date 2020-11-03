#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../Graph/bipartite_matching.hpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m, k;
    std::cin >> n >> m >> k;

    BipartiteMatching bm(n, m);
    while (k--) {
        int u, v;
        std::cin >> u >> v;
        bm.span(u, v);
    }

    auto match = bm.matching();

    std::cout << match.size() << "\n";
    for (auto [u, v] : match) {
        std::cout << u << " " << v << "\n";
    }
    return 0;
}
