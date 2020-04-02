#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../Graph/dijkstra.cpp"

#include <iostream>

constexpr int INF = std::numeric_limits<int>::max();

int main() {
    int n, m, s;
    std::cin >> n >> m >> s;

    Graph<int> graph(n);
    while (m--) {
        int u, v, d;
        std::cin >> u >> v >> d;
        graph[u].emplace_back(u, v, d);
    }

    auto dist = dijkstra(graph, s);
    for (auto d : dist) {
        if (d == INF) {
            std::cout << "INF";
        } else {
            std::cout << d;
        }
        std::cout << "\n";
    }
    return 0;
}
