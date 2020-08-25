#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../Graph/dijkstra.hpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m, s;
    std::cin >> n >> m >> s;

    Graph<int> graph(n);
    while (m--) {
        int u, v, d;
        std::cin >> u >> v >> d;
        graph.span(true, u, v, d);
    }

    auto dist = dijkstra(graph, s);
    for (auto d : dist) {
        if (d == -1) {
            std::cout << "INF";
        } else {
            std::cout << d;
        }
        std::cout << "\n";
    }

    return 0;
}
