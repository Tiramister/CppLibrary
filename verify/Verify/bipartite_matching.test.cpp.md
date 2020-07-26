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


# :heavy_check_mark: Verify/bipartite_matching.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/bipartite_matching.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 22:31:04+09:00


* see: <a href="https://judge.yosupo.jp/problem/bipartitematching">https://judge.yosupo.jp/problem/bipartitematching</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/bipartite_matching.hpp.html">Graph/bipartite_matching.hpp</a>
* :heavy_check_mark: <a href="../../library/Graph/dinic.hpp.html">Graph/dinic.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../Graph/bipartite_matching.hpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m, k;
    std::cin >> n >> m >> k;

    BipartiteMatching bm(n, m);
    while (k--) {
        int u, v;
        std::cin >> u >> v;
        bm.span(u, v);
    }

    auto match = bm.matching();

    std::cout << match.size() << "\n";
    for (auto p : match) {
        std::cout << p.first << ' ' << p.second << "\n";
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/bipartite_matching.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#line 2 "Graph/bipartite_matching.hpp"

#line 2 "Graph/dinic.hpp"

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
#line 4 "Graph/bipartite_matching.hpp"

struct BipartiteMatching {
    MaxFlow<int, true> mf;
    int n, m, s, g;

    explicit BipartiteMatching(int n, int m)
        : mf(n + m + 2), n(n), m(m), s(n + m), g(n + m + 1) {
        for (int u = 0; u < n; ++u) {
            mf.span(s, enc(u, false), 1);
        }
        for (int v = 0; v < m; ++v) {
            mf.span(enc(v, true), g, 1);
        }
    }

    int enc(int v, bool side) const {
        return v + (side ? n : 0);
    }

    void span(int u, int v) {
        mf.span(enc(u, false), enc(v, true), 1);
    }

    int exec() { return mf.exec(s, g); }

    std::vector<std::pair<int, int>> matching() {
        mf.exec(s, g);

        std::vector<std::pair<int, int>> ret;
        for (auto e : mf.edges) {
            if (e.src < e.dst &&
                e.src < n && e.dst < n + m &&
                e.cap == 0) {
                ret.emplace_back(e.src, e.dst - n);
            }
        }
        return ret;
    }
};
#line 4 "Verify/bipartite_matching.test.cpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m, k;
    std::cin >> n >> m >> k;

    BipartiteMatching bm(n, m);
    while (k--) {
        int u, v;
        std::cin >> u >> v;
        bm.span(u, v);
    }

    auto match = bm.matching();

    std::cout << match.size() << "\n";
    for (auto p : match) {
        std::cout << p.first << ' ' << p.second << "\n";
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

