#pragma once

#include "graph.hpp"
#include "bfs.hpp"

#include <algorithm>

template <class Cost>
std::pair<int, std::pair<int, int>> diameter(const Graph<Cost>& graph) {
    int u, v;
    {
        auto dist = bfs(graph, 0);
        u = std::distance(dist.begin(),
                          std::max_element(dist.begin(), dist.end()));
    }

    auto dist = bfs(graph, u);
    v = std::distance(dist.begin(),
                      std::max_element(dist.begin(), dist.end()));

    return std::make_pair(dist[v], std::make_pair(u, v));
}
