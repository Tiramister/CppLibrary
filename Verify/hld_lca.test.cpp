#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../Graph/heavy_light_decomposition.hpp"

#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    Graph<> graph(n);
    for (int v = 1; v < n; ++v) {
        int p;
        std::cin >> p;
        graph.span(false, p, v);
    }

    HeavyLightDecomposition hld(graph);

    while (q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << hld.lca(u, v) << "\n";
    }

    return 0;
}
