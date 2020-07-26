#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include "../Graph/bellman_ford.hpp"

#include <iostream>

constexpr int INF = std::numeric_limits<int>::max();

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

    auto dist = bellman_ford(graph, s);
    if (dist.empty()) {
        std::cout << "NEGATIVE CYCLE\n";
        return 0;
    }

    for (int d : dist) {
        if (d == INF) {
            std::cout << "INF";
        } else {
            std::cout << d;
        }
        std::cout << "\n";
    }
    return 0;
}
