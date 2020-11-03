#pragma once

#include "graph.hpp"

#include <vector>

template <class Cost>
struct HeavyLightDecomposition {
    // indexing
    // v: a vertex in original graph
    // i: assigned label of a vertex

    Graph<Cost> graph;
    std::vector<int> id, vs;  // id: v -> i, vs: i -> v
    std::vector<int> par, sz, head, dep, out;
    // these are all v-indexed
    // in equals to id
    int time;

    explicit HeavyLightDecomposition(const Graph<Cost>& graph)
        : graph(graph),
          id(graph.size()),
          vs(graph.size()),
          par(graph.size()),
          sz(graph.size()),
          head(graph.size()),
          dep(graph.size()),
          out(graph.size()),
          time(0) {
        dfs_sz(0, -1, 0);
        head[0] = 0;
        dfs_hld(0, -1);
    }

    void dfs_sz(int v, int p, int d) {
        par[v] = p;
        sz[v] = 1;
        dep[v] = d;

        if (graph[v].front().dst == p) {
            std::swap(graph[v].front(), graph[v].back());
        }

        for (auto& e : graph[v]) {
            if (e.dst == p) continue;

            dfs_sz(e.dst, v, d + 1);
            sz[v] += sz[e.dst];

            // heavy edge first
            if (sz[graph[v].front().dst] < sz[e.dst]) {
                std::swap(graph[v].front(), e);
            }
        }
    }

    void dfs_hld(int v, int p) {
        id[v] = time++;
        vs[id[v]] = v;

        bool first = true;
        for (auto e : graph[v]) {
            if (e.dst == p) continue;

            head[e.dst] = (first ? head[v] : e.dst);
            first = false;
            dfs_hld(e.dst, v);
        }

        out[v] = time;
    }

    int lca(int u, int v) {
        while (true) {
            if (id[u] > id[v]) std::swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }

    int dist(int u, int v) {
        return dep[u] + dep[v] - dep[lca(u, v)] * 2;
    }

    std::vector<std::pair<int, int>> path(int u, int v, bool is_edge) {
        std::vector<std::pair<int, int>> segs;

        while (true) {
            if (id[u] > id[v]) std::swap(u, v);

            if (head[u] == head[v]) {
                // when edge path, the lca has to be excluded
                segs.emplace_back(id[u] + is_edge, id[v] + 1);
                return segs;
            }

            segs.emplace_back(id[head[v]], id[v] + 1);
            v = par[head[v]];
        }
    }

    std::pair<int, int> subtree(int v, bool is_edge) {
        // when edge path, the root has to be excluded
        return {id[v] + is_edge, out[v]};
    }
};
