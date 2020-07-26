---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: Graph/level_ancestor.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/level_ancestor.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 22:31:04+09:00




## Depends on

* :question: <a href="graph.hpp.html">Graph/graph.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/level_ancestor.test.cpp.html">Verify/level_ancestor.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "graph.hpp"

template <class Cost = int>
struct LevelAncestor {
    Graph<Cost> tree;
    std::vector<std::vector<int>> par;
    std::vector<int> depth;
    std::vector<Cost> cdepth;
    int kmax;

    void dfs(int v, int p = -1, int d = 0, Cost c = 0) {
        par[v][0] = p;
        depth[v] = d;
        cdepth[v] = c;

        for (const auto& e : tree[v]) {
            if (e.dst == p) continue;
            dfs(e.dst, v, d + 1, c + e.cost);
        }
    }

    LevelAncestor(const Graph<Cost>& tree, int root)
        : tree(tree), par(tree.size()), depth(tree.size(), -1), cdepth(tree.size()) {
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

    int dist(int u, int v) const {
        int p = lca(u, v);
        return depth[u] + depth[v] - depth[p] * 2;
    }

    Cost cdist(int u, int v) const {
        int p = lca(u, v);
        return cdepth[u] + cdepth[v] - cdepth[p] * 2;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Graph/level_ancestor.hpp"

#line 2 "Graph/graph.hpp"

#include <vector>

template <class Cost = int>
struct Edge {
    int src, dst;
    Cost cost;
    Edge(int src = -1, int dst = -1, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return this->cost > e.cost; }
};

template <class Cost = int>
using Edges = std::vector<Edge<Cost>>;

template <class Cost = int>
struct Graph {
    std::vector<std::vector<Edge<Cost>>> graph;

    Graph(int n = 0) : graph(n) {}

    void span(bool direct, int src, int dst, Cost cost = 1) {
        graph[src].emplace_back(src, dst, cost);
        if (!direct) graph[dst].emplace_back(dst, src, cost);
    }

    int size() const { return graph.size(); }
    void clear() { graph.clear(); }
    void resize(int n) { graph.resize(n); }

    std::vector<Edge<Cost>>& operator[](int v) { return graph[v]; }
    std::vector<Edge<Cost>> operator[](int v) const { return graph[v]; }
};
#line 4 "Graph/level_ancestor.hpp"

template <class Cost = int>
struct LevelAncestor {
    Graph<Cost> tree;
    std::vector<std::vector<int>> par;
    std::vector<int> depth;
    std::vector<Cost> cdepth;
    int kmax;

    void dfs(int v, int p = -1, int d = 0, Cost c = 0) {
        par[v][0] = p;
        depth[v] = d;
        cdepth[v] = c;

        for (const auto& e : tree[v]) {
            if (e.dst == p) continue;
            dfs(e.dst, v, d + 1, c + e.cost);
        }
    }

    LevelAncestor(const Graph<Cost>& tree, int root)
        : tree(tree), par(tree.size()), depth(tree.size(), -1), cdepth(tree.size()) {
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

    int dist(int u, int v) const {
        int p = lca(u, v);
        return depth[u] + depth[v] - depth[p] * 2;
    }

    Cost cdist(int u, int v) const {
        int p = lca(u, v);
        return cdepth[u] + cdepth[v] - cdepth[p] * 2;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

