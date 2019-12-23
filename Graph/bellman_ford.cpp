#ifndef __guard__
#define __guard__
#include "graph.cpp"
#undef __guard__
#endif

#include <vector>
#include <limits>

template <class Cost>
std::vector<Cost> bellman_ford(const Graph<Cost>& graph, int s) {
    constexpr Cost INF = std::numeric_limits<Cost>::max();

    int n = graph.size();
    std::vector<Cost> dist(n, INF);
    dist[s] = 0;

    for (int t = 0; t < n; ++t) {
        bool update = false;
        for (int v = 0; v < n; ++v) {
            for (const auto& e : graph[v]) {
                if (dist[v] != INF && dist[e.dst] > dist[v] + e.cost) {
                    dist[e.dst] = dist[v] + e.cost;
                    update = true;
                }
            }
        }

        if (!update) break;
        if (t == n - 1) {
            // if there is a negative cycle, return empty array
            return std::vector<Cost>();
        }
    }
    return dist;
}
