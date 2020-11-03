#pragma once

#include "../Tools/heap_alias.hpp"
#include "graph.hpp"

template <class Cost>
std::vector<Cost> dijkstra(const Graph<Cost>& graph, int s) {
    std::vector<Cost> dist(graph.size(), -1);
    dist[s] = 0;
    MinHeap<std::pair<Cost, int>> que;
    que.emplace(0, s);

    while (!que.empty()) {
        auto [d, v] = que.top();
        que.pop();
        if (d > dist[v]) continue;

        for (const auto& e : graph[v]) {
            if (dist[e.dst] != -1 &&
                dist[e.dst] <= dist[v] + e.cost) continue;
            dist[e.dst] = dist[v] + e.cost;
            que.emplace(dist[e.dst], e.dst);
        }
    }

    return dist;
}
