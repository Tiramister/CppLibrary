#pragma once

#include "../Tools/heap_alias.hpp"
#include "graph.hpp"

#include <tuple>
#include <limits>

template <class Cost>
std::vector<Cost> dijkstra(const Graph<Cost>& graph, int s) {
    constexpr Cost INF = std::numeric_limits<Cost>::max();

    std::vector<Cost> dist(graph.size(), INF);
    dist[s] = 0;
    MinHeap<std::pair<Cost, int>> que;
    que.emplace(0, s);

    while (!que.empty()) {
        int v;
        Cost d;
        std::tie(d, v) = que.top();
        que.pop();
        if (d > dist[v]) continue;

        for (const auto& e : graph[v]) {
            if (dist[e.dst] <= dist[v] + e.cost) continue;
            dist[e.dst] = dist[v] + e.cost;
            que.emplace(dist[e.dst], e.dst);
        }
    }

    return dist;
}
