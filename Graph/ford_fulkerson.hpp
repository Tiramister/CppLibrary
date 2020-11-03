#pragma once

#include <vector>
#include <limits>

template <class Cap, bool isDirect>
struct MaxFlow {
    struct Edge {
        int src, dst;
        Cap cap;
        Edge(int src, int dst, Cap cap)
            : src(src), dst(dst), cap(cap){};
    };

    std::vector<Edge> edges;
    std::vector<std::vector<int>> graph;
    std::vector<bool> visited;

    explicit MaxFlow(int n) : graph(n), visited(n) {}

    void span(int u, int v, Cap cap) {
        graph[u].push_back(edges.size());
        edges.emplace_back(u, v, cap);

        graph[v].push_back(edges.size());
        edges.emplace_back(v, u, (isDirect ? 0 : cap));
    }

    Cap dfs(int v, int g, Cap f) {
        if (v == g) return f;

        visited[v] = true;
        for (auto eidx : graph[v]) {
            auto& edge = edges[eidx];

            if (edge.cap > 0 && !visited[edge.dst]) {
                auto df = dfs(edge.dst, g, std::min(f, edge.cap));

                if (df > 0) {
                    edge.cap -= df;
                    auto& redge = edges[eidx ^ 1];
                    redge.cap += df;
                    return df;
                }
            }
        }
        return 0;
    }

    Cap flow(int s, int g) {
        constexpr Cap INF = std::numeric_limits<Cap>::max();

        Cap ret = 0;
        while (true) {
            std::fill(visited.begin(), visited.end(), false);
            Cap f = dfs(s, g, INF);
            if (f == 0) return ret;
            ret += f;
        }
    }
};
