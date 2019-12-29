#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B"

#define __guard__
#include "../Graph/graph.cpp"
#include "../Graph/topological_sort.cpp"
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

    TopologicalSort<> ts(graph);
    for (int v : ts.order) {
        std::cout << v << std::endl;
    }
    return 0;
}
