#pragma once

#include <numeric>
#include <vector>

template <class Dist>
struct WeightedUnionFind {
    std::vector<int> par, sz;
    std::vector<Dist> dist;  // A[par[v]] - A[v] = dist[v]
    int gnum;

    explicit WeightedUnionFind(int n)
        : par(n), sz(n, 1), dist(n, 0), gnum(n) {
        std::iota(par.begin(), par.end(), 0);
    }

    int find(int v) {
        if (par[v] == v) {
            return v;
        } else {
            int p = find(par[v]);
            dist[v] += dist[par[v]];
            return par[v] = p;
        }
    }

    // A[u] - A[v] = d
    void unite(int u, int v, Dist d) {
        find(u), find(v);
        d += dist[u];
        d -= dist[v];
        u = par[u], v = par[v];
        if (u == v) return;

        if (sz[u] < sz[v]) {
            std::swap(u, v);
            d = -d;
        }

        sz[u] += sz[v];
        par[v] = u;
        dist[v] = d;
        --gnum;
    }

    // A[v] - A[u]
    Dist diff(int u, int v) {
        find(u), find(v);
        return dist[u] - dist[v];
    }

    bool same(int u, int v) { return find(u) == find(v); }
    bool ispar(int v) { return v == find(v); }
    int size(int v) { return sz[find(v)]; }
};
