#pragma once

#include "graph.cpp"

template <class Cost>
struct LevelAncestor {
    Graph<Cost> tree;
    std::vector<std::vector<int>> par;
    std::vector<int> depth;
    int kmax;

    void dfs(int v, int p = -1, int d = 0) {
        par[v][0] = p;
        depth[v] = d;

        for (const auto& e : tree[v]) {
            if (e.dst == p) continue;
            dfs(e.dst, v, d + 1);
        }
    }

    LevelAncestor(const Graph<Cost>& tree, int root)
        : tree(tree), par(tree.size()), depth(tree.size(), -1) {
        kmax = 0;
        while ((1 << kmax) < (int)tree.size()) ++kmax;
        for (auto& v : par) v.resize(kmax + 1);

        dfs(root);

        for (int k = 1; k <= kmax; ++k) {
            for (int v = 0; v < tree.size(); ++v) {
                int p = par[v][k - 1];
                par[v][k] = (p == -1 ? -1 : par[p][k - 1]);
            }
        }
    }

    int climb(int v, int d) const {
        for (int k = kmax; k >= 0 && v != -1; --k) {
            if ((1 << k) > d) continue;

            v = par[v][k];
            d -= (1 << k);
        }
        return v;
    }

    int lca(int u, int v) const {
        if (depth[u] < depth[v]) std::swap(u, v);

        if (depth[u] > depth[v]) {
            u = climb(u, depth[u] - depth[v]);
        }

        if (u == v) return u;

        for (int k = kmax; k >= 0; --k) {
            if (par[u][k] != par[v][k]) {
                u = par[u][k];
                v = par[v][k];
            }
        }
        return par[u][0];
    }
};
