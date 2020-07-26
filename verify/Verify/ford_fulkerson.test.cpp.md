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


# :heavy_check_mark: Verify/ford_fulkerson.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/ford_fulkerson.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 22:31:04+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/ford_fulkerson.hpp.html">Graph/ford_fulkerson.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A"

#include "../Graph/ford_fulkerson.hpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    MaxFlow<int, true> mf(n);
    while (m--) {
        int u, v, c;
        std::cin >> u >> v >> c;
        mf.span(u, v, c);
    }

    std::cout << mf.exec(0, n - 1) << "\n";
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/ford_fulkerson.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A"

#line 2 "Graph/ford_fulkerson.hpp"

#include <vector>
#include <limits>

template <class Cap, bool isDirect>
struct MaxFlow {
    struct Edge {
        int src, dst;
        Cap cap;
        Edge(int src, int dst, Cap cap)
            : src(src), dst(dst), cap(cap){};
    };

    using Edges = std::vector<Edge>;
    using Graph = std::vector<std::vector<int>>;

    Edges edges;
    Graph graph;
    std::vector<bool> visited;

    explicit MaxFlow(int n)
        : graph(n), visited(n) {}

    void span(int u, int v, Cap cap) {
        graph[u].push_back(edges.size());
        edges.emplace_back(u, v, cap);

        graph[v].push_back(edges.size());
        edges.emplace_back(v, u, (isDirect ? 0 : cap));
    }

    int dfs(int v, int g, Cap f) {
        if (v == g) return f;

        visited[v] = true;
        for (auto eidx : graph[v]) {
            auto& edge = edges[eidx];

            if (edge.cap > 0 && !visited[edge.dst]) {
                Cap df = dfs(edge.dst, g, std::min(f, edge.cap));

                if (df > 0) {
                    edge.cap -= df;
                    auto& redge = edges[eidx ^ 1];
                    redge.cap += df;
                    return df;
                }
            }
        }
        return 0;
    }

    Cap exec(int s, int g) {
        constexpr Cap INF = std::numeric_limits<Cap>::max();

        Cap ret = 0;
        while (true) {
            std::fill(visited.begin(), visited.end(), false);
            Cap flow = dfs(s, g, INF);
            if (flow == 0) return ret;
            ret += flow;
        }
    }
};
#line 4 "Verify/ford_fulkerson.test.cpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    MaxFlow<int, true> mf(n);
    while (m--) {
        int u, v, c;
        std::cin >> u >> v >> c;
        mf.span(u, v, c);
    }

    std::cout << mf.exec(0, n - 1) << "\n";
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

