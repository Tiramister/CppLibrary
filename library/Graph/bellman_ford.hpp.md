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


# :heavy_check_mark: Graph/bellman_ford.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/bellman_ford.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 22:31:04+09:00




## Depends on

* :question: <a href="graph.hpp.html">Graph/graph.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/bellman_ford.test.cpp.html">Verify/bellman_ford.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "graph.hpp"

#include <vector>
#include <limits>

template <class Cost>
std::vector<Cost> bellman_ford(const Graph<Cost>& graph, int s) {
    constexpr Cost INF = std::numeric_limits<Cost>::max();

    int n = graph.size();
    std::vector<Cost> dist(n, INF);
    dist[s] = 0;

    for (int t = 0; t < n; ++t) {
        bool update = false;
        for (int v = 0; v < n; ++v) {
            for (const auto& e : graph[v]) {
                if (dist[v] != INF && dist[e.dst] > dist[v] + e.cost) {
                    dist[e.dst] = dist[v] + e.cost;
                    update = true;
                }
            }
        }

        if (!update) break;
        if (t == n - 1) {
            // if there is a negative cycle, return empty array
            return std::vector<Cost>();
        }
    }
    return dist;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Graph/bellman_ford.hpp"

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
#line 4 "Graph/bellman_ford.hpp"

#line 6 "Graph/bellman_ford.hpp"
#include <limits>

template <class Cost>
std::vector<Cost> bellman_ford(const Graph<Cost>& graph, int s) {
    constexpr Cost INF = std::numeric_limits<Cost>::max();

    int n = graph.size();
    std::vector<Cost> dist(n, INF);
    dist[s] = 0;

    for (int t = 0; t < n; ++t) {
        bool update = false;
        for (int v = 0; v < n; ++v) {
            for (const auto& e : graph[v]) {
                if (dist[v] != INF && dist[e.dst] > dist[v] + e.cost) {
                    dist[e.dst] = dist[v] + e.cost;
                    update = true;
                }
            }
        }

        if (!update) break;
        if (t == n - 1) {
            // if there is a negative cycle, return empty array
            return std::vector<Cost>();
        }
    }
    return dist;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

