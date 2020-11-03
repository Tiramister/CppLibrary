#pragma once

#include <vector>
#include <queue>
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
    std::vector<int> dist, iter;

    explicit MaxFlow(int n) : graph(n), dist(n), iter(n) {}

    void span(int u, int v, Cap cap) {
        graph[u].push_back(edges.size());
        edges.emplace_back(u, v, cap);

        graph[v].push_back(edges.size());
        edges.emplace_back(v, u, (isDirect ? 0 : cap));
    }

    void bfs(int s) {
        std::fill(dist.begin(), dist.end(), -1);
        dist[s] = 0;
        std::queue<int> que;
        que.push(s);

        while (!que.empty()) {
            auto v = que.front();
            que.pop();

            for (auto eidx : graph[v]) {
                const auto& edge = edges[eidx];

                if (edge.cap > 0 && dist[edge.dst] == -1) {
                    dist[edge.dst] = dist[v] + 1;
                    que.push(edge.dst);
                }
            }
        }
    }

    Cap dfs(int v, int g, Cap f) {
        if (v == g) return f;

        for (auto& itr = iter[v]; itr < (int)graph[v].size(); ++itr) {
            auto eidx = graph[v][itr];
            auto& edge = edges[eidx];

            if (edge.cap > 0 && dist[v] < dist[edge.dst]) {
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
        const Cap INF = std::numeric_limits<Cap>::max();

        Cap ret = 0;
        while (true) {
            bfs(s);
            if (dist[g] < 0) return ret;

            std::fill(iter.begin(), iter.end(), 0);
            while (true) {
                Cap f = dfs(s, g, INF);
                if (f == 0) break;
                ret += f;
            }
        }
    }
};
