---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/primal_dual.hpp
    title: Graph/primal_dual.hpp
  - icon: ':heavy_check_mark:'
    path: Tools/heap_alias.hpp
    title: Tools/heap_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B
  bundledCode: "#line 1 \"Verify/primal_dual.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B\"\
    \n\n#line 2 \"Tools/heap_alias.hpp\"\n\n#include <queue>\n\ntemplate <class T>\n\
    using MaxHeap = std::priority_queue<T>;\ntemplate <class T>\nusing MinHeap = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n#line 2 \"Graph/primal_dual.hpp\"\n\n#include\
    \ <vector>\n#include <tuple>\n#include <limits>\n\ntemplate <class Cap, class\
    \ Cost>\nstruct MinCostFlow {\n    struct Edge {\n        int src, dst;\n    \
    \    Cap cap;\n        Cost cost;\n        Edge(int src, int dst, Cap cap, Cost\
    \ cost)\n            : src(src), dst(dst), cap(cap), cost(cost){};\n    };\n\n\
    \    using Edges = std::vector<Edge>;\n    using Graph = std::vector<std::vector<int>>;\n\
    \n    Edges edges;\n    Graph graph;\n    std::vector<Cost> dist, pot;\n    std::vector<int>\
    \ rev;\n\n    const Cost INF = std::numeric_limits<Cost>::max() / 2;\n\n    explicit\
    \ MinCostFlow(int n) : graph(n), dist(n), pot(n), rev(n) {}\n\n    void span(int\
    \ u, int v, Cap cap, Cost cost) {\n        graph[u].push_back(edges.size());\n\
    \        edges.emplace_back(u, v, cap, cost);\n\n        graph[v].push_back(edges.size());\n\
    \        edges.emplace_back(v, u, 0, -cost);\n    }\n\n    void dijkstra(int s)\
    \ {\n        std::fill(dist.begin(), dist.end(), INF);\n        dist[s] = 0;\n\
    \        MinHeap<std::pair<Cost, int>> heap;\n        heap.emplace(0, s);\n\n\
    \        while (!heap.empty()) {\n            int u;\n            Cost d;\n  \
    \          std::tie(d, u) = heap.top();\n            heap.pop();\n           \
    \ if (d > dist[u]) continue;\n\n            for (auto eidx : graph[u]) {\n   \
    \             const auto& edge = edges[eidx];\n                int v = edge.dst;\n\
    \n                if (edge.cap > 0 &&\n                    dist[u] < INF &&\n\
    \                    dist[v] > dist[u] + edge.cost + pot[u] - pot[v]) {\n    \
    \                dist[v] = dist[u] + edge.cost + pot[u] - pot[v];\n          \
    \          rev[v] = eidx;\n                    heap.emplace(dist[v], v);\n   \
    \             }\n            }\n        }\n    }\n\n    Cost exec(int s, int g,\
    \ Cap flow) {\n        Cost ret = 0;\n        std::fill(pot.begin(), pot.end(),\
    \ 0);\n\n        while (flow > 0) {\n            dijkstra(s);\n            if\
    \ (dist[g] == INF) break;\n\n            for (int v = 0; v < (int)graph.size();\
    \ ++v) {\n                pot[v] = std::min(pot[v] + dist[v], INF);\n        \
    \    }\n\n            Cap f = flow;\n            int v = g;\n            while\
    \ (v != s) {\n                const auto& edge = edges[rev[v]];\n            \
    \    f = std::min(f, edge.cap);\n                v = edge.src;\n            }\n\
    \n            flow -= f;\n            ret += f * pot[g];\n\n            v = g;\n\
    \            while (v != s) {\n                auto& edge = edges[rev[v]];\n \
    \               auto& redge = edges[rev[v] ^ 1];\n                edge.cap -=\
    \ f;\n                redge.cap += f;\n                v = edge.src;\n       \
    \     }\n        }\n        return (flow > 0 ? -1 : ret);\n    }\n};\n#line 4\
    \ \"Verify/primal_dual.test.cpp\"\n\n#include <iostream>\n\nint main() {\n   \
    \ std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n    int n, m, f;\n\
    \    std::cin >> n >> m >> f;\n\n    MinCostFlow<int, int> mcf(n);\n    while\
    \ (m--) {\n        int u, v, c, d;\n        std::cin >> u >> v >> c >> d;\n  \
    \      mcf.span(u, v, c, d);\n    }\n\n    std::cout << mcf.exec(0, n - 1, f)\
    \ << \"\\n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B\"\
    \n\n#include \"../Graph/primal_dual.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n    int n,\
    \ m, f;\n    std::cin >> n >> m >> f;\n\n    MinCostFlow<int, int> mcf(n);\n \
    \   while (m--) {\n        int u, v, c, d;\n        std::cin >> u >> v >> c >>\
    \ d;\n        mcf.span(u, v, c, d);\n    }\n\n    std::cout << mcf.exec(0, n -\
    \ 1, f) << \"\\n\";\n    return 0;\n}\n"
  dependsOn:
  - Graph/primal_dual.hpp
  - Tools/heap_alias.hpp
  isVerificationFile: true
  path: Verify/primal_dual.test.cpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/primal_dual.test.cpp
layout: document
redirect_from:
- /verify/Verify/primal_dual.test.cpp
- /verify/Verify/primal_dual.test.cpp.html
title: Verify/primal_dual.test.cpp
---
