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


# :heavy_check_mark: Verify/bridges.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/bridges.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 22:04:26+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/graph.cpp.html">Graph/graph.cpp</a>
* :heavy_check_mark: <a href="../../library/Graph/lowlink.cpp.html">Graph/lowlink.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B"

#include "../Graph/lowlink.cpp"

#include <iostream>
#include <algorithm>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    Graph<> graph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        graph.span(false, u, v);
    }

    Lowlink<> ll(graph);

    std::vector<std::pair<int, int>> ans;

    for (auto& e : ll.bridges) {
        if (e.src > e.dst) std::swap(e.src, e.dst);
        ans.emplace_back(e.src, e.dst);
    }
    std::sort(ans.begin(), ans.end());

    for (const auto& p : ans) {
        std::cout << p.first << ' ' << p.second << "\n";
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/bridges.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B"

#line 2 "Graph/lowlink.cpp"

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
struct Graph {
    std::vector<std::vector<Edge<Cost>>> graph;

    Graph(int n = 0) : graph(n) {}

    void span(bool direct, int src, int dst, Cost cost = 1) {
        graph[src].emplace_back(src, dst, cost);
        if (!direct) graph[dst].emplace_back(dst, src, cost);
    }

    std::vector<Edge<Cost>>& operator[](int v) { return graph[v]; }
    std::vector<Edge<Cost>> operator[](int v) const { return graph[v]; }

    int size() const { return graph.size(); }
};
#line 4 "Graph/lowlink.cpp"

template <class Cost = int>
struct Lowlink {
    Graph<Cost> graph;
    int time;
    std::vector<int> order, low;

    std::vector<int> artics;
    std::vector<Edge<Cost>> bridges;

    explicit Lowlink(const Graph<Cost>& graph)
        : graph(graph), order(graph.size(), -1), low(graph.size(), graph.size()) {
        time = 0;
        for (int v = 0; v < (int)graph.size(); ++v) {
            if (order[v] < 0) dfs(v, -1);
        }
    }

    void dfs(int v, int r) {
        order[v] = low[v] = time++;
        int deg = 0;
        bool is_artic = false;

        for (auto e : graph[v]) {
            if (order[e.dst] < 0) {
                ++deg;
                dfs(e.dst, e.src);
                low[e.src] = std::min(low[e.src], low[e.dst]);

                if (order[e.src] <= low[e.dst]) is_artic = true;
                if (order[e.src] < low[e.dst]) bridges.push_back(e);
            } else if (e.dst != r) {
                low[e.src] = std::min(low[e.src], order[e.dst]);
            }
        }

        if (r < 0) is_artic = (deg > 1);
        if (is_artic) artics.push_back(v);
    }
};
#line 4 "Verify/bridges.test.cpp"

#include <iostream>
#include <algorithm>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    Graph<> graph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        graph.span(false, u, v);
    }

    Lowlink<> ll(graph);

    std::vector<std::pair<int, int>> ans;

    for (auto& e : ll.bridges) {
        if (e.src > e.dst) std::swap(e.src, e.dst);
        ans.emplace_back(e.src, e.dst);
    }
    std::sort(ans.begin(), ans.end());

    for (const auto& p : ans) {
        std::cout << p.first << ' ' << p.second << "\n";
    }

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

