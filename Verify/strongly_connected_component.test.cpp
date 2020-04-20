#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../Graph/strongly_connected_component.cpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    Graph<> graph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        graph.span(true, u, v);
    }

    StronglyConnectedComponents scc(graph);

    std::cout << scc.groups.size() << std::endl;
    for (auto& g : scc.groups) {
        std::cout << g.size();
        for (auto v : g) std::cout << ' ' << v;
        std::cout << "\n";
    }

    return 0;
}
