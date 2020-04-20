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


# :heavy_check_mark: Verify/bellman_ford.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/bellman_ford.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 22:04:26+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/bellman_ford.cpp.html">Graph/bellman_ford.cpp</a>
* :heavy_check_mark: <a href="../../library/Graph/graph.cpp.html">Graph/graph.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#include "../Graph/bellman_ford.cpp"

#include <iostream>

constexpr int INF = std::numeric_limits<int>::max();

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m, s;
    std::cin >> n >> m >> s;

    Graph<int> graph(n);
    while (m--) {
        int u, v, d;
        std::cin >> u >> v >> d;
        graph.span(true, u, v, d);
    }

    auto dist = bellman_ford(graph, s);
    if (dist.empty()) {
        std::cout << "NEGATIVE CYCLE\n";
        return 0;
    }

    for (int d : dist) {
        if (d == INF) {
            std::cout << "INF";
        } else {
            std::cout << d;
        }
        std::cout << "\n";
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/bellman_ford.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B"

#line 2 "Graph/bellman_ford.cpp"

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
#line 4 "Graph/bellman_ford.cpp"

#line 6 "Graph/bellman_ford.cpp"
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
#line 4 "Verify/bellman_ford.test.cpp"

#include <iostream>

constexpr int INF = std::numeric_limits<int>::max();

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m, s;
    std::cin >> n >> m >> s;

    Graph<int> graph(n);
    while (m--) {
        int u, v, d;
        std::cin >> u >> v >> d;
        graph.span(true, u, v, d);
    }

    auto dist = bellman_ford(graph, s);
    if (dist.empty()) {
        std::cout << "NEGATIVE CYCLE\n";
        return 0;
    }

    for (int d : dist) {
        if (d == INF) {
            std::cout << "INF";
        } else {
            std::cout << d;
        }
        std::cout << "\n";
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

