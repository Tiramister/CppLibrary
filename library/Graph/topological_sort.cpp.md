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


# :heavy_check_mark: Graph/topological_sort.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/topological_sort.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 22:58:51+09:00




## Depends on

* :heavy_check_mark: <a href="graph.cpp.html">Graph/graph.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/topological_sort.test.cpp.html">Verify/topological_sort.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "graph.cpp"

#include <algorithm>

template <class Cost = int>
struct TopologicalSort {
    Graph<Cost> graph;
    std::vector<bool> visited;
    std::vector<int> order, id;

    explicit TopologicalSort(const Graph<Cost>& graph)
        : graph(graph), visited(graph.size(), false), id(graph.size()) {
        for (int v = 0; v < (int)graph.size(); ++v) dfs(v);
        std::reverse(order.begin(), order.end());

        for (int i = 0; i < (int)graph.size(); ++i) id[order[i]] = i;
    }

    void dfs(int v) {
        if (visited[v]) return;
        visited[v] = true;
        for (const auto& e : graph[v]) dfs(e.dst);
        order.push_back(v);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Graph/topological_sort.cpp"

#line 2 "Graph/graph.cpp"

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
using Graph = std::vector<std::vector<Edge<Cost>>>;
#line 4 "Graph/topological_sort.cpp"

#include <algorithm>

template <class Cost = int>
struct TopologicalSort {
    Graph<Cost> graph;
    std::vector<bool> visited;
    std::vector<int> order, id;

    explicit TopologicalSort(const Graph<Cost>& graph)
        : graph(graph), visited(graph.size(), false), id(graph.size()) {
        for (int v = 0; v < (int)graph.size(); ++v) dfs(v);
        std::reverse(order.begin(), order.end());

        for (int i = 0; i < (int)graph.size(); ++i) id[order[i]] = i;
    }

    void dfs(int v) {
        if (visited[v]) return;
        visited[v] = true;
        for (const auto& e : graph[v]) dfs(e.dst);
        order.push_back(v);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

