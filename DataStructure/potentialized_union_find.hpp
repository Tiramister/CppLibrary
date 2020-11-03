#pragma once

#include <vector>

template <class Dist>
struct PotentializedUnionFind {
    std::vector<int> par;
    std::vector<Dist> dist;  // A[par[v]] - A[v] = dist[v]
    int gnum;

    explicit PotentializedUnionFind(int n)
        : par(n, -1), dist(n, 0), gnum(n) {}

    int find(int v) {
        if (par[v] < 0) {
            return v;
        } else {
            auto p = find(par[v]);
            dist[v] += dist[par[v]];
            return par[v] = p;
        }
    }

    // A[u] - A[v] = d
    void unite(int u, int v, Dist d) {
        auto pu = find(u), pv = find(v);
        d += dist[u];
        d -= dist[v];
        u = pu, v = pv;
        if (u == v) return;

        if (par[u] > par[v]) {
            std::swap(u, v);
            d = -d;
        }

        par[u] += par[v];
        par[v] = u;
        dist[v] = d;
        --gnum;
    }

    // A[u] - A[v]
    Dist diff(int u, int v) {
        find(u), find(v);
        return dist[v] - dist[u];
    }

    bool same(int u, int v) { return find(u) == find(v); }
    bool ispar(int v) { return v == find(v); }
    int size(int v) { return -par[find(v)]; }
};
