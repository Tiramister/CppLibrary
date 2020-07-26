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


# :heavy_check_mark: Verify/union_find.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/union_find.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 22:31:04+09:00


* see: <a href="https://judge.yosupo.jp/problem/unionfind">https://judge.yosupo.jp/problem/unionfind</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/union_find.hpp.html">DataStructure/union_find.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../DataStructure/union_find.hpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    UnionFind uf(n);
    while (q--) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            uf.unite(u, v);
        } else {
            std::cout << uf.same(u, v) << "\n";
        }
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/union_find.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#line 2 "DataStructure/union_find.hpp"

#include <numeric>
#include <vector>

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
#line 4 "Verify/union_find.test.cpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    UnionFind uf(n);
    while (q--) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            uf.unite(u, v);
        } else {
            std::cout << uf.same(u, v) << "\n";
        }
    }

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

