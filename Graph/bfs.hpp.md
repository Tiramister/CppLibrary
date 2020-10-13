---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/diameter.hpp
    title: Graph/diameter.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/diameter.test.cpp
    title: Verify/diameter.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/bfs.hpp\"\n\n#line 2 \"Graph/graph.hpp\"\n\n#include\
    \ <vector>\n\ntemplate <class Cost = int>\nstruct Edge {\n    int src, dst;\n\
    \    Cost cost;\n\n    Edge() = default;\n    Edge(int src, int dst, Cost cost\
    \ = 1)\n        : src(src), dst(dst), cost(cost){};\n\n    bool operator<(const\
    \ Edge<Cost>& e) const { return cost < e.cost; }\n    bool operator>(const Edge<Cost>&\
    \ e) const { return cost > e.cost; }\n};\n\ntemplate <class Cost = int>\nstruct\
    \ Graph : public std::vector<std::vector<Edge<Cost>>> {\n    Graph(int n = 0)\
    \ : std::vector<std::vector<Edge<Cost>>>(n) {}\n\n    void span(bool direct, int\
    \ src, int dst, Cost cost = 1) {\n        (*this)[src].emplace_back(src, dst,\
    \ cost);\n        if (!direct) (*this)[dst].emplace_back(dst, src, cost);\n  \
    \  }\n};\n#line 4 \"Graph/bfs.hpp\"\n\n#include <queue>\n\ntemplate <class Cost>\n\
    std::vector<int> bfs(const Graph<Cost>& graph, int s) {\n    std::vector<Cost>\
    \ dist(graph.size(), -1);\n    dist[s] = 0;\n    std::queue<int> que;\n    que.push(s);\n\
    \n    while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \n        for (const auto& e : graph[v]) {\n            if (dist[e.dst] != -1)\
    \ continue;\n            dist[e.dst] = dist[v] + e.cost;\n            que.push(e.dst);\n\
    \        }\n    }\n\n    return dist;\n}\n"
  code: "#pragma once\n\n#include \"graph.hpp\"\n\n#include <queue>\n\ntemplate <class\
    \ Cost>\nstd::vector<int> bfs(const Graph<Cost>& graph, int s) {\n    std::vector<Cost>\
    \ dist(graph.size(), -1);\n    dist[s] = 0;\n    std::queue<int> que;\n    que.push(s);\n\
    \n    while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \n        for (const auto& e : graph[v]) {\n            if (dist[e.dst] != -1)\
    \ continue;\n            dist[e.dst] = dist[v] + e.cost;\n            que.push(e.dst);\n\
    \        }\n    }\n\n    return dist;\n}\n"
  dependsOn:
  - Graph/graph.hpp
  isVerificationFile: false
  path: Graph/bfs.hpp
  requiredBy:
  - Graph/diameter.hpp
  timestamp: '2020-10-13 21:34:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/diameter.test.cpp
documentation_of: Graph/bfs.hpp
layout: document
redirect_from:
- /library/Graph/bfs.hpp
- /library/Graph/bfs.hpp.html
title: Graph/bfs.hpp
---
