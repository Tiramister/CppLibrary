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


# :heavy_check_mark: Graph/min_cost_flow.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/min_cost_flow.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-29 02:01:29+09:00




## Depends on

* :heavy_check_mark: <a href="../Misc/heap_alias.cpp.html">Misc/heap_alias.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/min_cost_flow.test.cpp.html">Verify/min_cost_flow.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef __guard__
#define __guard__
#include "../Misc/heap_alias.cpp"
#undef __guard__
#endif

#include <vector>
#include <tuple>
#include <queue>
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
    std::vector<Cost> dist, pot;
    std::vector<int> rev;

    const Cost INF = std::numeric_limits<Cost>::max() / 2;

    explicit MinCostFlow(int n) : graph(n), dist(n), pot(n), rev(n) {}

    void span(int u, int v, Cap cap, Cost cost) {
        graph[u].push_back(edges.size());
        edges.emplace_back(u, v, cap, cost);

        graph[v].push_back(edges.size());
        edges.emplace_back(v, u, 0, -cost);
    }

    void dijkstra(int s) {
        std::fill(dist.begin(), dist.end(), INF);
        dist[s] = 0;
        MinHeap<std::pair<Cost, int>> heap;
        heap.emplace(0, s);

        while (!heap.empty()) {
            int u;
            Cost d;
            std::tie(d, u) = heap.top();
            heap.pop();
            if (d > dist[u]) continue;

            for (auto eidx : graph[u]) {
                const auto& edge = edges[eidx];
                int v = edge.dst;

                if (edge.cap > 0 &&
                    dist[u] < INF &&
                    dist[v] > dist[u] + edge.cost + pot[u] - pot[v]) {
                    dist[v] = dist[u] + edge.cost + pot[u] - pot[v];
                    rev[v] = eidx;
                    heap.emplace(dist[v], v);
                }
            }
        }
    }

    Cost exec(int s, int g, Cap flow) {
        Cost ret = 0;
        std::fill(pot.begin(), pot.end(), 0);

        while (flow > 0) {
            dijkstra(s);
            if (dist[g] == INF) break;

            for (int v = 0; v < (int)graph.size(); ++v) {
                pot[v] = std::min(pot[v] + dist[v], INF);
            }

            Cap f = flow;
            int v = g;
            while (v != s) {
                const auto& edge = edges[rev[v]];
                f = std::min(f, edge.cap);
                v = edge.src;
            }

            flow -= f;
            ret += f * pot[g];

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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 123, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: Graph/min_cost_flow.cpp: line 6: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

