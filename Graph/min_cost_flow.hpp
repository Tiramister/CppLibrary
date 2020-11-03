#pragma once

#include <vector>
#include <limits>

template <class Cap, class Cost>
struct MinCostFlow {
    struct Edge {
        int src, dst;
        Cap cap;
        Cost cost;
        Edge(int src, int dst, Cap cap, Cost cost)
            : src(src), dst(dst), cap(cap), cost(cost){};
    };

    std::vector<Edge> edges;
    std::vector<std::vector<int>> graph;

    std::vector<Cost> dist;
    std::vector<int> rev;

    const Cost INF = std::numeric_limits<Cost>::max() / 2;

    explicit MinCostFlow(int n) : graph(n), dist(n), rev(n) {}

    void span(int u, int v, Cap cap, Cost cost) {
        graph[u].push_back(edges.size());
        edges.emplace_back(u, v, cap, cost);

        graph[v].push_back(edges.size());
        edges.emplace_back(v, u, 0, -cost);
    }

    void bellman_ford(int s) {
        std::fill(dist.begin(), dist.end(), INF);
        dist[s] = 0;

        bool update = true;
        while (update) {
            update = false;

            for (int eidx = 0; eidx < (int)edges.size(); ++eidx) {
                const auto& edge = edges[eidx];
                int u = edge.src, v = edge.dst;

                if (edge.cap > 0 && dist[u] < INF &&
                    dist[v] > dist[u] + edge.cost) {
                    dist[v] = dist[u] + edge.cost;
                    rev[v] = eidx;
                    update = true;
                }
            }
        }
    }

    std::pair<Cap, Cost> flow(int s, int g, Cap flow_limit) {
        Cap fsum = 0;
        Cost csum = 0;

        while (flow_limit > 0) {
            bellman_ford(s);
            if (dist[g] == INF) break;

            Cap f = flow_limit;
            int v = g;
            while (v != s) {
                const auto& edge = edges[rev[v]];
                f = std::min(f, edge.cap);
                v = edge.src;
            }

            flow_limit -= f;
            fsum += f;
            csum += f * dist[g];

            v = g;
            while (v != s) {
                auto& edge = edges[rev[v]];
                auto& redge = edges[rev[v] ^ 1];
                edge.cap -= f;
                redge.cap += f;
                v = edge.src;
            }
        }
        return {fsum, csum};
    }

    std::pair<Cap, Cost> flow(int s, int g) {
        return flow(s, g, std::numeric_limits<Cap>::max());
    }
};
