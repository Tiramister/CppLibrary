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


# :x: Verify/topological_sort.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/topological_sort.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 22:31:04+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B</a>


## Depends on

* :question: <a href="../../library/Graph/graph.hpp.html">Graph/graph.hpp</a>
* :x: <a href="../../library/Graph/topological_sort.hpp.html">Graph/topological_sort.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B"

#include "../Graph/topological_sort.hpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    Graph<> graph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        graph.span(true, u, v);
    }

    TopologicalSort<> ts(graph);
    for (int v : ts.order) std::cout << v << "\n";

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/topological_sort.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B"

#line 2 "Graph/topological_sort.hpp"

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
#line 4 "Graph/topological_sort.hpp"

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
#line 4 "Verify/topological_sort.test.cpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    Graph<> graph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        graph.span(true, u, v);
    }

    TopologicalSort<> ts(graph);
    for (int v : ts.order) std::cout << v << "\n";

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

