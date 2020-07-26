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


# :warning: DataStructure/potentialized_union_find.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/potentialized_union_find.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 22:31:04+09:00




## Required by

* :warning: <a href="../Verify/potentialized_union_find.cpp.html">Verify/potentialized_union_find.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <numeric>
#include <vector>

template <class Dist>
struct PotentializedUnionFind {
    std::vector<int> par, sz;
    std::vector<Dist> dist;  // A[par[v]] - A[v] = dist[v]
    int gnum;

    explicit PotentializedUnionFind(int n)
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "DataStructure/potentialized_union_find.hpp"

#include <numeric>
#include <vector>

template <class Dist>
struct PotentializedUnionFind {
    std::vector<int> par, sz;
    std::vector<Dist> dist;  // A[par[v]] - A[v] = dist[v]
    int gnum;

    explicit PotentializedUnionFind(int n)
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

