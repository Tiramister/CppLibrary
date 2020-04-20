#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../Graph/graph.cpp"
#include "../Graph/level_ancestor.cpp"

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

    LevelAncestor la(graph, 0);

    while (q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << la.lca(u, v) << "\n";
    }

    return 0;
}
