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


# :heavy_check_mark: Graph/strongly_connected_component.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/strongly_connected_component.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 22:58:51+09:00




## Depends on

* :heavy_check_mark: <a href="graph.cpp.html">Graph/graph.cpp</a>


## Required by

* :heavy_check_mark: <a href="two_sat.cpp.html">Graph/two_sat.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/strongly_connected_component.test.cpp.html">Verify/strongly_connected_component.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Verify/two_sat.test.cpp.html">Verify/two_sat.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "graph.cpp"

#include <algorithm>
#include <vector>

template <class Cost = int>
struct StronglyConnectedComponents {
    Graph<Cost> graph, rgraph;
    std::vector<bool> visited;
    std::vector<int> stk;

    // id[v] = 頂点vはgroups[id[v]]に属する
    std::vector<int> id;
    std::vector<std::vector<int>> groups;

    explicit StronglyConnectedComponents(const Graph<Cost>& g)
        : graph(g), visited(graph.size(), false), id(graph.size(), -1) {
        revinit();

        for (int v = 0; v < (int)graph.size(); ++v) dfs(v);

        while (!stk.empty()) {
            int v = stk.back();
            stk.pop_back();
            if (id[v] < 0) {
                groups.emplace_back();
                rdfs(v);
            }
        }
    }

    void revinit() {
        rgraph = Graph<Cost>(graph.size());
        for (int v = 0; v < (int)graph.size(); ++v) {
            for (const auto& e : graph[v]) {
                rgraph[e.dst].emplace_back(e.dst, v, e.cost);
            }
        }
    }

    void dfs(int v) {
        if (visited[v]) return;
        visited[v] = true;
        for (const auto& e : graph[v]) dfs(e.dst);
        stk.push_back(v);
    }

    void rdfs(int v) {
        if (id[v] >= 0) return;
        id[v] = groups.size() - 1;
        groups.back().push_back(v);
        for (const auto& e : rgraph[v]) rdfs(e.dst);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Graph/strongly_connected_component.cpp"

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
#line 4 "Graph/strongly_connected_component.cpp"

#include <algorithm>
#line 7 "Graph/strongly_connected_component.cpp"

template <class Cost = int>
struct StronglyConnectedComponents {
    Graph<Cost> graph, rgraph;
    std::vector<bool> visited;
    std::vector<int> stk;

    // id[v] = 頂点vはgroups[id[v]]に属する
    std::vector<int> id;
    std::vector<std::vector<int>> groups;

    explicit StronglyConnectedComponents(const Graph<Cost>& g)
        : graph(g), visited(graph.size(), false), id(graph.size(), -1) {
        revinit();

        for (int v = 0; v < (int)graph.size(); ++v) dfs(v);

        while (!stk.empty()) {
            int v = stk.back();
            stk.pop_back();
            if (id[v] < 0) {
                groups.emplace_back();
                rdfs(v);
            }
        }
    }

    void revinit() {
        rgraph = Graph<Cost>(graph.size());
        for (int v = 0; v < (int)graph.size(); ++v) {
            for (const auto& e : graph[v]) {
                rgraph[e.dst].emplace_back(e.dst, v, e.cost);
            }
        }
    }

    void dfs(int v) {
        if (visited[v]) return;
        visited[v] = true;
        for (const auto& e : graph[v]) dfs(e.dst);
        stk.push_back(v);
    }

    void rdfs(int v) {
        if (id[v] >= 0) return;
        id[v] = groups.size() - 1;
        groups.back().push_back(v);
        for (const auto& e : rgraph[v]) rdfs(e.dst);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
