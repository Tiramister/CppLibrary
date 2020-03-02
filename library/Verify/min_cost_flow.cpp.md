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


# :warning: Verify/min_cost_flow.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/min_cost_flow.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-03 05:19:20+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B</a>


## Depends on

* :heavy_check_mark: <a href="../Graph/min_cost_flow.cpp.html">Graph/min_cost_flow.cpp</a>
* :heavy_check_mark: <a href="../Misc/heap_alias.cpp.html">Misc/heap_alias.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B"

#define __guard__
#include "../Misc/heap_alias.cpp"
#include "../Graph/min_cost_flow.cpp"
#undef __guard__

#include <iostream>

int main() {
    int n, m, f;
    std::cin >> n >> m >> f;

    MinCostFlow<int, int> mcf(n);
    while (m--) {
        int u, v, c, d;
        std::cin >> u >> v >> c >> d;
        mcf.span(u, v, c, d);
    }
    std::cout << mcf.exec(0, n - 1, f) << std::endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/min_cost_flow.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B"

#define __guard__
#line 1 "Verify/../Misc/heap_alias.cpp"
#include <queue>

template <class T>
using MaxHeap = std::priority_queue<T>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 1 "Verify/../Graph/min_cost_flow.cpp"
#include <vector>
#include <limits>

template <class Cap, class Cost>
struct MinCostFlow {
    struct Edge {
        int src, dst;
        Cap cap;
        Cost cost;
        Edge(int src, int dst, Cap cap, Cost cost)
            : src(src), dst(dst), cap(cap), cost(cost){};
    };

    using Edges = std::vector<Edge>;
    using Graph = std::vector<std::vector<int>>;

    Edges edges;
    Graph graph;
    std::vector<Cost> dist;
    std::vector<int> rev;

    const Cost INF = std::numeric_limits<Cost>::max() / 2;

    explicit MinCostFlow(int n) : graph(n), dist(n), rev(n) {}

    void span(int u, int v, Cap cap, Cost cost) {
        graph[u].push_back(edges.size());
        edges.emplace_back(u, v, cap, cost);

        graph[v].push_back(edges.size());
        edges.emplace_back(v, u, 0, -cost);
    }

    void bellman_ford(int s) {
        std::fill(dist.begin(), dist.end(), INF);
        dist[s] = 0;

        for (int i = 0; i < (int)graph.size(); ++i) {
            for (int eidx = 0; eidx < (int)edges.size(); ++eidx) {
                const auto& edge = edges[eidx];
                int u = edge.src, v = edge.dst;

                if (edge.cap > 0 &&
                    dist[u] < INF &&
                    dist[v] > dist[u] + edge.cost) {
                    dist[v] = dist[u] + edge.cost;
                    rev[v] = eidx;
                }
            }
        }
    }

    Cost exec(int s, int g, Cap flow) {
        Cost ret = 0;

        while (flow > 0) {
            bellman_ford(s);
            if (dist[g] == INF) break;

            Cap f = flow;
            int v = g;
            while (v != s) {
                const auto& edge = edges[rev[v]];
                f = std::min(f, edge.cap);
                v = edge.src;
            }

            flow -= f;
            ret += f * dist[g];

            v = g;
            while (v != s) {
                auto& edge = edges[rev[v]];
                auto& redge = edges[rev[v] ^ 1];
                edge.cap -= f;
                redge.cap += f;
                v = edge.src;
            }
        }
        return (flow > 0 ? -1 : ret);
    }
};
#line 6 "Verify/min_cost_flow.cpp"
#undef __guard__

#include <iostream>

int main() {
    int n, m, f;
    std::cin >> n >> m >> f;

    MinCostFlow<int, int> mcf(n);
    while (m--) {
        int u, v, c, d;
        std::cin >> u >> v >> c >> d;
        mcf.span(u, v, c, d);
    }
    std::cout << mcf.exec(0, n - 1, f) << std::endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

