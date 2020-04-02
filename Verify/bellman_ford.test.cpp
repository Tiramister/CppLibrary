#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include "../Graph/bellman_ford.cpp"

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

    auto dist = bellman_ford(graph, s);
    if (dist.empty()) {
        std::cout << "NEGATIVE CYCLE" << std::endl;
        return 0;
    }
    for (int d : dist) {
        if (d == INF) {
            std::cout << "INF" << std::endl;
        } else {
            std::cout << d << std::endl;
        }
    }
    return 0;
}
