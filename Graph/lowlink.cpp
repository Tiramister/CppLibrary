#pragma once

#include "graph.cpp"

template <class Cost = int>
struct Lowlink {
    Graph<Cost> graph;
    int time;
    std::vector<int> order, low;

    std::vector<int> artics;
    std::vector<Edge<Cost>> bridges;

    explicit Lowlink(const Graph<Cost>& graph)
        : graph(graph), order(graph.size(), -1), low(graph.size(), graph.size()) {
        time = 0;
        for (int v = 0; v < (int)graph.size(); ++v) {
            if (order[v] < 0) dfs(v, -1);
        }
    }

    void dfs(int v, int r) {
        order[v] = low[v] = time++;
        int deg = 0;
        bool is_artic = false;

        for (auto e : graph[v]) {
            if (order[e.dst] < 0) {
                ++deg;
                dfs(e.dst, e.src);
                low[e.src] = std::min(low[e.src], low[e.dst]);

                if (order[e.src] <= low[e.dst]) is_artic = true;
                if (order[e.src] < low[e.dst]) bridges.push_back(e);
            } else if (e.dst != r) {
                low[e.src] = std::min(low[e.src], order[e.dst]);
            }
        }

        if (r < 0) is_artic = (deg > 1);
        if (is_artic) artics.push_back(v);
    }
};
