#pragma once

#include "graph.hpp"

#include <algorithm>

template <class Cost = int>
struct TopologicalSort {
    Graph<Cost> graph;
    std::vector<bool> visited;
    std::vector<int> vs, id;

    explicit TopologicalSort(const Graph<Cost>& graph)
        : graph(graph), visited(graph.size(), false), id(graph.size()) {
        for (int v = 0; v < (int)graph.size(); ++v) dfs(v);
        std::reverse(vs.begin(), vs.end());

        for (int i = 0; i < (int)graph.size(); ++i) id[vs[i]] = i;
    }

    void dfs(int v) {
        if (visited[v]) return;
        visited[v] = true;
        for (const auto& e : graph[v]) dfs(e.dst);
        vs.push_back(v);
    }
};
