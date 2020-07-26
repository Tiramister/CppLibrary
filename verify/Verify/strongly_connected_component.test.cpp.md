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


# :heavy_check_mark: Verify/strongly_connected_component.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/strongly_connected_component.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 22:31:04+09:00


* see: <a href="https://judge.yosupo.jp/problem/scc">https://judge.yosupo.jp/problem/scc</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/graph.hpp.html">Graph/graph.hpp</a>
* :heavy_check_mark: <a href="../../library/Graph/strongly_connected_component.hpp.html">Graph/strongly_connected_component.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../Graph/strongly_connected_component.hpp"

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

    StronglyConnectedComponents scc(graph);

    std::cout << scc.groups.size() << std::endl;
    for (auto& g : scc.groups) {
        std::cout << g.size();
        for (auto v : g) std::cout << ' ' << v;
        std::cout << "\n";
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/strongly_connected_component.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#line 2 "Graph/strongly_connected_component.hpp"

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
#line 4 "Graph/strongly_connected_component.hpp"

#line 6 "Graph/strongly_connected_component.hpp"

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
#line 4 "Verify/strongly_connected_component.test.cpp"

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

    StronglyConnectedComponents scc(graph);

    std::cout << scc.groups.size() << std::endl;
    for (auto& g : scc.groups) {
        std::cout << g.size();
        for (auto v : g) std::cout << ' ' << v;
        std::cout << "\n";
    }

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

