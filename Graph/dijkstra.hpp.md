---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: Tools/heap_alias.hpp
    title: Tools/heap_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/dijkstra.test.cpp
    title: Verify/dijkstra.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/dijkstra.hpp\"\n\n#line 2 \"Tools/heap_alias.hpp\"\
    \n\n#include <queue>\n\ntemplate <class T>\nusing MaxHeap = std::priority_queue<T>;\n\
    template <class T>\nusing MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\
    #line 2 \"Graph/graph.hpp\"\n\n#include <vector>\n\ntemplate <class Cost = int>\n\
    struct Edge {\n    int src, dst;\n    Cost cost;\n\n    Edge() = default;\n  \
    \  Edge(int src, int dst, Cost cost = 1)\n        : src(src), dst(dst), cost(cost){};\n\
    \n    bool operator<(const Edge<Cost>& e) const { return cost < e.cost; }\n  \
    \  bool operator>(const Edge<Cost>& e) const { return cost > e.cost; }\n};\n\n\
    template <class Cost = int>\nstruct Graph : public std::vector<std::vector<Edge<Cost>>>\
    \ {\n    using std::vector<std::vector<Edge<Cost>>>::vector;\n\n    void span(bool\
    \ direct, int src, int dst, Cost cost = 1) {\n        (*this)[src].emplace_back(src,\
    \ dst, cost);\n        if (!direct) (*this)[dst].emplace_back(dst, src, cost);\n\
    \    }\n};\n#line 5 \"Graph/dijkstra.hpp\"\n\ntemplate <class Cost>\nstd::vector<Cost>\
    \ dijkstra(const Graph<Cost>& graph, int s) {\n    std::vector<Cost> dist(graph.size(),\
    \ -1);\n    dist[s] = 0;\n    MinHeap<std::pair<Cost, int>> que;\n    que.emplace(0,\
    \ s);\n\n    while (!que.empty()) {\n        auto [d, v] = que.top();\n      \
    \  que.pop();\n        if (d > dist[v]) continue;\n\n        for (const auto&\
    \ e : graph[v]) {\n            if (dist[e.dst] != -1 &&\n                dist[e.dst]\
    \ <= dist[v] + e.cost) continue;\n            dist[e.dst] = dist[v] + e.cost;\n\
    \            que.emplace(dist[e.dst], e.dst);\n        }\n    }\n\n    return\
    \ dist;\n}\n"
  code: "#pragma once\n\n#include \"../Tools/heap_alias.hpp\"\n#include \"graph.hpp\"\
    \n\ntemplate <class Cost>\nstd::vector<Cost> dijkstra(const Graph<Cost>& graph,\
    \ int s) {\n    std::vector<Cost> dist(graph.size(), -1);\n    dist[s] = 0;\n\
    \    MinHeap<std::pair<Cost, int>> que;\n    que.emplace(0, s);\n\n    while (!que.empty())\
    \ {\n        auto [d, v] = que.top();\n        que.pop();\n        if (d > dist[v])\
    \ continue;\n\n        for (const auto& e : graph[v]) {\n            if (dist[e.dst]\
    \ != -1 &&\n                dist[e.dst] <= dist[v] + e.cost) continue;\n     \
    \       dist[e.dst] = dist[v] + e.cost;\n            que.emplace(dist[e.dst],\
    \ e.dst);\n        }\n    }\n\n    return dist;\n}\n"
  dependsOn:
  - Tools/heap_alias.hpp
  - Graph/graph.hpp
  isVerificationFile: false
  path: Graph/dijkstra.hpp
  requiredBy: []
  timestamp: '2020-11-05 12:15:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/dijkstra.test.cpp
documentation_of: Graph/dijkstra.hpp
layout: document
redirect_from:
- /library/Graph/dijkstra.hpp
- /library/Graph/dijkstra.hpp.html
title: Graph/dijkstra.hpp
---
