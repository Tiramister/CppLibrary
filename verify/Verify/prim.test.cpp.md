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


# :heavy_check_mark: Verify/prim.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/prim.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 23:11:18+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/graph.cpp.html">Graph/graph.cpp</a>
* :heavy_check_mark: <a href="../../library/Graph/prim.cpp.html">Graph/prim.cpp</a>
* :heavy_check_mark: <a href="../../library/Tools/heap_alias.cpp.html">Tools/heap_alias.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A"

#include "../Graph/prim.cpp"

#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    Graph<int> graph(n);
    while (m--) {
        int u, v, d;
        std::cin >> u >> v >> d;
        graph[u].emplace_back(u, v, d);
        graph[v].emplace_back(v, u, d);
    }

    std::cout << prim(graph) << "\n";
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/prim.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A"

#line 2 "Graph/prim.cpp"

#line 2 "Tools/heap_alias.cpp"

#include <queue>

template <class T>
using MaxHeap = std::priority_queue<T>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
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
#line 5 "Graph/prim.cpp"

#line 7 "Graph/prim.cpp"

template <class Cost, class Cap = int>
Cost prim(const Graph<Cost>& graph) {
    std::vector<bool> used(graph.size(), false);
    used[0] = true;

    MinHeap<Edge<Cost>> heap;
    for (const auto& e : graph[0]) {
        heap.push(e);
    }

    Cost sum = 0;
    while (!heap.empty()) {
        auto e = heap.top();
        heap.pop();
        if (used[e.dst]) continue;

        sum += e.cost;
        used[e.dst] = true;
        for (const auto& se : graph[e.dst]) {
            heap.push(se);
        }
    }
    return sum;
}
#line 4 "Verify/prim.test.cpp"

#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    Graph<int> graph(n);
    while (m--) {
        int u, v, d;
        std::cin >> u >> v >> d;
        graph[u].emplace_back(u, v, d);
        graph[v].emplace_back(v, u, d);
    }

    std::cout << prim(graph) << "\n";
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
