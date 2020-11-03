---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/topological_sort.test.cpp
    title: Verify/topological_sort.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/topological_sort.hpp\"\n\n#line 2 \"Graph/graph.hpp\"\
    \n\n#include <vector>\n\ntemplate <class Cost = int>\nstruct Edge {\n    int src,\
    \ dst;\n    Cost cost;\n\n    Edge() = default;\n    Edge(int src, int dst, Cost\
    \ cost = 1)\n        : src(src), dst(dst), cost(cost){};\n\n    bool operator<(const\
    \ Edge<Cost>& e) const { return cost < e.cost; }\n    bool operator>(const Edge<Cost>&\
    \ e) const { return cost > e.cost; }\n};\n\ntemplate <class Cost = int>\nstruct\
    \ Graph : public std::vector<std::vector<Edge<Cost>>> {\n    Graph(int n = 0)\
    \ : std::vector<std::vector<Edge<Cost>>>(n) {}\n\n    void span(bool direct, int\
    \ src, int dst, Cost cost = 1) {\n        (*this)[src].emplace_back(src, dst,\
    \ cost);\n        if (!direct) (*this)[dst].emplace_back(dst, src, cost);\n  \
    \  }\n};\n#line 4 \"Graph/topological_sort.hpp\"\n\n#include <algorithm>\n\ntemplate\
    \ <class Cost = int>\nstruct TopologicalSort {\n    Graph<Cost> graph;\n    std::vector<bool>\
    \ visited;\n    std::vector<int> vs, id;\n\n    explicit TopologicalSort(const\
    \ Graph<Cost>& graph)\n        : graph(graph), visited(graph.size(), false), id(graph.size())\
    \ {\n        for (int v = 0; v < (int)graph.size(); ++v) dfs(v);\n        std::reverse(vs.begin(),\
    \ vs.end());\n\n        for (int i = 0; i < (int)graph.size(); ++i) id[vs[i]]\
    \ = i;\n    }\n\n    void dfs(int v) {\n        if (visited[v]) return;\n    \
    \    visited[v] = true;\n        for (const auto& e : graph[v]) dfs(e.dst);\n\
    \        vs.push_back(v);\n    }\n};\n"
  code: "#pragma once\n\n#include \"graph.hpp\"\n\n#include <algorithm>\n\ntemplate\
    \ <class Cost = int>\nstruct TopologicalSort {\n    Graph<Cost> graph;\n    std::vector<bool>\
    \ visited;\n    std::vector<int> vs, id;\n\n    explicit TopologicalSort(const\
    \ Graph<Cost>& graph)\n        : graph(graph), visited(graph.size(), false), id(graph.size())\
    \ {\n        for (int v = 0; v < (int)graph.size(); ++v) dfs(v);\n        std::reverse(vs.begin(),\
    \ vs.end());\n\n        for (int i = 0; i < (int)graph.size(); ++i) id[vs[i]]\
    \ = i;\n    }\n\n    void dfs(int v) {\n        if (visited[v]) return;\n    \
    \    visited[v] = true;\n        for (const auto& e : graph[v]) dfs(e.dst);\n\
    \        vs.push_back(v);\n    }\n};\n"
  dependsOn:
  - Graph/graph.hpp
  isVerificationFile: false
  path: Graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2020-11-03 10:05:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/topological_sort.test.cpp
documentation_of: Graph/topological_sort.hpp
layout: document
redirect_from:
- /library/Graph/topological_sort.hpp
- /library/Graph/topological_sort.hpp.html
title: Graph/topological_sort.hpp
---
