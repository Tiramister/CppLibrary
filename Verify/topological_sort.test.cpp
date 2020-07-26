#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B"

#include "../Graph/topological_sort.hpp"

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

    TopologicalSort<> ts(graph);
    for (int v : ts.order) std::cout << v << "\n";

    return 0;
}
