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


# :heavy_check_mark: Verify/centroid_decomposition_diameter.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/centroid_decomposition_diameter.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 23:11:18+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/centroid_decomposition.cpp.html">Graph/centroid_decomposition.cpp</a>
* :heavy_check_mark: <a href="../../library/Graph/graph.cpp.html">Graph/graph.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A"

#include "../Graph/centroid_decomposition.cpp"

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

int main() {
    int n;
    std::cin >> n;

    Graph<int> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u].emplace_back(u, v, w);
        graph[v].emplace_back(v, u, w);
    }

    Centroid<int> cent(graph);

    int ans = 0;
    std::queue<int> cents;
    cents.push(0);

    std::vector<int> dist(n);
    while (!cents.empty()) {
        int r = cents.front();
        cents.pop();
        r = cent.find(r);
        cent.deleted[r] = true;

        std::vector<int> fars({0, 0});
        for (auto e : graph[r]) {
            if (cent.deleted[e.dst]) continue;
            cents.push(e.dst);

            // BFS
            std::queue<std::pair<int, int>> que;
            que.emplace(e.dst, -1);
            dist[e.dst] = e.cost;

            int far = 0;
            while (!que.empty()) {
                int v, p;
                std::tie(v, p) = que.front();
                que.pop();
                far = std::max(far, dist[v]);

                for (auto f : graph[v]) {
                    if (f.dst == p || cent.deleted[f.dst]) continue;
                    dist[f.dst] = dist[v] + f.cost;
                    que.emplace(f.dst, v);
                }
            }
            fars.push_back(far);
        }

        std::sort(fars.rbegin(), fars.rend());
        if (fars.size() >= 2) ans = std::max(ans, fars[0] + fars[1]);
    }

    std::cout << ans << "\n";
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/centroid_decomposition_diameter.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A"

#line 2 "Graph/centroid_decomposition.cpp"

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
#line 4 "Graph/centroid_decomposition.cpp"

template <class Cost = int>
struct Centroid {
    Graph<Cost> graph;
    std::vector<bool> deleted;
    std::vector<int> sz;

    explicit Centroid(const Graph<Cost>& graph)
        : graph(graph), deleted(graph.size(), false), sz(graph.size()) {}

    int szdfs(int v, int p = -1) {
        sz[v] = 1;
        for (auto e : graph[v]) {
            if (e.dst == p || deleted[e.dst]) continue;
            sz[v] += szdfs(e.dst, v);
        }
        return sz[v];
    }

    int find(int v) {
        int n = szdfs(v);

        int p = -1;
        while (true) {
            int nxt = -1;
            for (auto e : graph[v]) {
                if (e.dst == p || deleted[e.dst]) continue;
                if (nxt == -1 || sz[e.dst] > sz[nxt]) nxt = e.dst;
            }

            if (nxt == -1 || sz[nxt] <= n / 2) return v;
            p = v;
            v = nxt;
        }
    }
};
#line 4 "Verify/centroid_decomposition_diameter.test.cpp"

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

int main() {
    int n;
    std::cin >> n;

    Graph<int> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u].emplace_back(u, v, w);
        graph[v].emplace_back(v, u, w);
    }

    Centroid<int> cent(graph);

    int ans = 0;
    std::queue<int> cents;
    cents.push(0);

    std::vector<int> dist(n);
    while (!cents.empty()) {
        int r = cents.front();
        cents.pop();
        r = cent.find(r);
        cent.deleted[r] = true;

        std::vector<int> fars({0, 0});
        for (auto e : graph[r]) {
            if (cent.deleted[e.dst]) continue;
            cents.push(e.dst);

            // BFS
            std::queue<std::pair<int, int>> que;
            que.emplace(e.dst, -1);
            dist[e.dst] = e.cost;

            int far = 0;
            while (!que.empty()) {
                int v, p;
                std::tie(v, p) = que.front();
                que.pop();
                far = std::max(far, dist[v]);

                for (auto f : graph[v]) {
                    if (f.dst == p || cent.deleted[f.dst]) continue;
                    dist[f.dst] = dist[v] + f.cost;
                    que.emplace(f.dst, v);
                }
            }
            fars.push_back(far);
        }

        std::sort(fars.rbegin(), fars.rend());
        if (fars.size() >= 2) ans = std::max(ans, fars[0] + fars[1]);
    }

    std::cout << ans << "\n";
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

