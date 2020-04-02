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


# :heavy_check_mark: Verify/dinic.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/dinic.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 23:11:18+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/dinic.cpp.html">Graph/dinic.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A"

#include "../Graph/dinic.cpp"

#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    MaxFlow<int, true> mf(n);
    while (m--) {
        int u, v, c;
        std::cin >> u >> v >> c;
        mf.span(u, v, c);
    }

    std::cout << mf.exec(0, n - 1) << "\n";
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/dinic.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A"

#line 2 "Graph/dinic.cpp"

#include <vector>
#include <queue>
#include <limits>

template <class Cap, bool isDirect>
struct MaxFlow {
    struct Edge {
        int src, dst;
        Cap cap;
        Edge(int src, int dst, Cap cap)
            : src(src), dst(dst), cap(cap){};
    };

    using Edges = std::vector<Edge>;
    using Graph = std::vector<std::vector<int>>;

    Edges edges;
    Graph graph;
    std::vector<int> dist, iter;

    explicit MaxFlow(int n)
        : graph(n), dist(n), iter(n) {}

    void span(int u, int v, Cap cap) {
        graph[u].push_back(edges.size());
        edges.emplace_back(u, v, cap);

        graph[v].push_back(edges.size());
        edges.emplace_back(v, u, (isDirect ? 0 : cap));
    }

    void bfs(int s) {
        std::fill(dist.begin(), dist.end(), -1);
        dist[s] = 0;
        std::queue<int> que;
        que.push(s);

        while (!que.empty()) {
            int v = que.front();
            que.pop();

            for (int eidx : graph[v]) {
                const auto& edge = edges[eidx];

                if (edge.cap > 0 && dist[edge.dst] < 0) {
                    dist[edge.dst] = dist[v] + 1;
                    que.push(edge.dst);
                }
            }
        }
    }

    int dfs(int v, int g, Cap f) {
        if (v == g) return f;

        for (int& itr = iter[v]; itr < (int)graph[v].size(); ++itr) {
            int eidx = graph[v][itr];
            auto& edge = edges[eidx];

            if (edge.cap > 0 && dist[v] < dist[edge.dst]) {
                Cap df = dfs(edge.dst, g, std::min(f, edge.cap));

                if (df > 0) {
                    edge.cap -= df;
                    auto& redge = edges[eidx ^ 1];
                    redge.cap += df;
                    return df;
                }
            }
        }
        return 0;
    }

    Cap exec(int s, int g) {
        const Cap INF = std::numeric_limits<Cap>::max();

        Cap ret = 0;
        while (true) {
            bfs(s);
            if (dist[g] < 0) return ret;

            std::fill(iter.begin(), iter.end(), 0);
            while (true) {
                Cap flow = dfs(s, g, INF);
                if (flow == 0) break;
                ret += flow;
            }
        }
    }
};
#line 4 "Verify/dinic.test.cpp"

#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    MaxFlow<int, true> mf(n);
    while (m--) {
        int u, v, c;
        std::cin >> u >> v >> c;
        mf.span(u, v, c);
    }

    std::cout << mf.exec(0, n - 1) << "\n";
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

