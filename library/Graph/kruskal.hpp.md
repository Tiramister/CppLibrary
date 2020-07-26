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


# :heavy_check_mark: Graph/kruskal.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/kruskal.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 22:31:04+09:00




## Depends on

* :question: <a href="../DataStructure/union_find.hpp.html">DataStructure/union_find.hpp</a>
* :question: <a href="graph.hpp.html">Graph/graph.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/kruskal.test.cpp.html">Verify/kruskal.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "graph.hpp"
#include "../DataStructure/union_find.hpp"

#include <algorithm>

template <class Cost>
Cost kruskal(int vnum, std::vector<Edge<Cost>>& edges) {
    std::sort(edges.begin(), edges.end(),
              [](const auto& lhs, const auto& rhs) { return lhs.cost < rhs.cost; });

    UnionFind uf(vnum);
    Cost sum = 0;
    for (const auto& e : edges) {
        if (uf.same(e.src, e.dst)) continue;
        sum += e.cost;
        uf.unite(e.src, e.dst);
    }
    return sum;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Graph/kruskal.hpp"

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
#line 2 "DataStructure/union_find.hpp"

#include <numeric>
#line 5 "DataStructure/union_find.hpp"

struct UnionFind {
    std::vector<int> par, sz;
    int gnum;

    explicit UnionFind(int n)
        : par(n), sz(n, 1), gnum(n) {
        std::iota(par.begin(), par.end(), 0);
    }

    int find(int v) {
        return (par[v] == v) ? v : (par[v] = find(par[v]));
    }

    void unite(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;

        if (sz[u] < sz[v]) std::swap(u, v);
        sz[u] += sz[v];
        par[v] = u;
        --gnum;
    }

    bool same(int u, int v) { return find(u) == find(v); }
    bool ispar(int v) { return v == find(v); }
    int size(int v) { return sz[find(v)]; }
};
#line 5 "Graph/kruskal.hpp"

#include <algorithm>

template <class Cost>
Cost kruskal(int vnum, std::vector<Edge<Cost>>& edges) {
    std::sort(edges.begin(), edges.end(),
              [](const auto& lhs, const auto& rhs) { return lhs.cost < rhs.cost; });

    UnionFind uf(vnum);
    Cost sum = 0;
    for (const auto& e : edges) {
        if (uf.same(e.src, e.dst)) continue;
        sum += e.cost;
        uf.unite(e.src, e.dst);
    }
    return sum;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

