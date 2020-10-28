#pragma once

#include <vector>

struct UnionFind {
    std::vector<int> par;
    int gnum;

    explicit UnionFind(int n) : par(n, -1), gnum(n) {}

    int find(int v) {
        return (par[v] < 0) ? v : (par[v] = find(par[v]));
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;

        if (par[u] > par[v]) std::swap(u, v);
        par[u] += par[v];
        par[v] = u;
        --gnum;
    }

    bool same(int u, int v) { return find(u) == find(v); }
    bool ispar(int v) { return par[v] < 0; }
    int size(int v) { return -par[find(v)]; }
};
