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


# :heavy_check_mark: Verify/two_sat.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/two_sat.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-20 22:04:26+09:00


* see: <a href="https://judge.yosupo.jp/problem/two_sat">https://judge.yosupo.jp/problem/two_sat</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/graph.cpp.html">Graph/graph.cpp</a>
* :heavy_check_mark: <a href="../../library/Graph/strongly_connected_component.cpp.html">Graph/strongly_connected_component.cpp</a>
* :heavy_check_mark: <a href="../../library/Graph/two_sat.cpp.html">Graph/two_sat.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "../Graph/two_sat.cpp"

#include <iostream>
#include <cmath>
#include <string>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    std::string tmp;
    int n, m;
    std::cin >> tmp >> tmp >> n >> m;

    TwoSat ts(n);
    while (m--) {
        int x, y;
        std::cin >> x >> y >> tmp;
        ts.span(std::abs(x) - 1, x > 0, std::abs(y) - 1, y > 0);
    }

    auto assign = ts.exec();
    if (assign.empty()) {
        std::cout << "s UNSATISFIABLE" << std::endl;

    } else {
        std::cout << "s SATISFIABLE" << std::endl;

        std::cout << "v ";
        for (int x = 1; x <= n; ++x) {
            std::cout << (assign[x - 1] ? x : -x) << " ";
        }
        std::cout << "0\n";
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/two_sat.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#line 2 "Graph/two_sat.cpp"

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
#line 2 "Graph/strongly_connected_component.cpp"

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
#line 5 "Graph/two_sat.cpp"

struct TwoSat {
    int vnum;
    Graph<> graph;

    explicit TwoSat(int n) : vnum(n), graph(n * 2) {}

    // t=1 <=> true
    int enc(int x, bool t) {
        return x + (t ? vnum : 0);
    }

    // [tx]x V [ty]y
    void span(int x, bool tx, int y, bool ty) {
        graph[enc(x, !tx)].emplace_back(enc(x, !tx), enc(y, ty));
        graph[enc(y, !ty)].emplace_back(enc(y, !ty), enc(x, tx));
    }

    // if unsatisfiable, return an empty vector
    std::vector<bool> exec() {
        StronglyConnectedComponents scc(graph);

        std::vector<bool> assign(vnum);
        for (int x = 0; x < vnum; ++x) {
            int fid = scc.id[enc(x, false)],
                tid = scc.id[enc(x, true)];

            if (fid == tid) {
                return std::vector<bool>();
            } else {
                assign[x] = (fid < tid);
            }
        }
        return assign;
    }
};
#line 4 "Verify/two_sat.test.cpp"

#include <iostream>
#include <cmath>
#include <string>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    std::string tmp;
    int n, m;
    std::cin >> tmp >> tmp >> n >> m;

    TwoSat ts(n);
    while (m--) {
        int x, y;
        std::cin >> x >> y >> tmp;
        ts.span(std::abs(x) - 1, x > 0, std::abs(y) - 1, y > 0);
    }

    auto assign = ts.exec();
    if (assign.empty()) {
        std::cout << "s UNSATISFIABLE" << std::endl;

    } else {
        std::cout << "s SATISFIABLE" << std::endl;

        std::cout << "v ";
        for (int x = 1; x <= n; ++x) {
            std::cout << (assign[x - 1] ? x : -x) << " ";
        }
        std::cout << "0\n";
    }

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

