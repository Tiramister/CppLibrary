#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#define __guard__
#include "../graph.cpp"
#include "../strongly_connected_component.cpp"
#undef __guard__

#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    Graph<> graph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        graph[u].emplace_back(u, v);
    }

    StronglyConnectedComponents scc(graph);
    std::cout << scc.groups.size() << std::endl;
    for (auto& g : scc.groups) {
        std::cout << g.size();
        for (auto v : g) {
            std::cout << ' ' << v;
        }
        std::cout << std::endl;
    }
    return 0;
}
