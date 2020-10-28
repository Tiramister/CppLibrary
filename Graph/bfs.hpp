#pragma once

#include "graph.hpp"

#include <queue>

template <class Cost>
std::vector<Cost> bfs(const Graph<Cost>& graph, int s) {
    std::vector<Cost> dist(graph.size(), -1);
    dist[s] = 0;
    std::queue<int> que;
    que.push(s);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (const auto& e : graph[v]) {
            if (dist[e.dst] != -1) continue;
            dist[e.dst] = dist[v] + e.cost;
            que.push(e.dst);
        }
    }

    return dist;
}
