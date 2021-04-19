---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/articulation_points.test.cpp
    title: Verify/articulation_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/bridges.test.cpp
    title: Verify/bridges.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/lowlink.hpp\"\n\n#line 2 \"Graph/graph.hpp\"\n\n#include\
    \ <vector>\n\ntemplate <class Cost = int>\nstruct Edge {\n    int src, dst;\n\
    \    Cost cost;\n\n    Edge() = default;\n    Edge(int src, int dst, Cost cost\
    \ = 1)\n        : src(src), dst(dst), cost(cost){};\n\n    bool operator<(const\
    \ Edge<Cost>& e) const { return cost < e.cost; }\n    bool operator>(const Edge<Cost>&\
    \ e) const { return cost > e.cost; }\n};\n\ntemplate <class Cost = int>\nstruct\
    \ Graph : public std::vector<std::vector<Edge<Cost>>> {\n    using std::vector<std::vector<Edge<Cost>>>::vector;\n\
    \n    void span(bool direct, int src, int dst, Cost cost = 1) {\n        (*this)[src].emplace_back(src,\
    \ dst, cost);\n        if (!direct) (*this)[dst].emplace_back(dst, src, cost);\n\
    \    }\n};\n#line 4 \"Graph/lowlink.hpp\"\n\ntemplate <class Cost = int>\nstruct\
    \ Lowlink {\n    Graph<Cost> graph;\n    int time;\n    std::vector<int> order,\
    \ low;\n\n    std::vector<int> artics;\n    std::vector<Edge<Cost>> bridges;\n\
    \n    explicit Lowlink(const Graph<Cost>& graph)\n        : graph(graph), order(graph.size(),\
    \ -1), low(graph.size(), graph.size()) {\n        time = 0;\n        for (int\
    \ v = 0; v < (int)graph.size(); ++v) {\n            if (order[v] < 0) dfs(v, -1);\n\
    \        }\n    }\n\n    void dfs(int v, int r) {\n        order[v] = low[v] =\
    \ time++;\n        int deg = 0;\n        bool is_artic = false;\n\n        for\
    \ (auto e : graph[v]) {\n            if (order[e.dst] < 0) {\n               \
    \ ++deg;\n                dfs(e.dst, e.src);\n                low[e.src] = std::min(low[e.src],\
    \ low[e.dst]);\n\n                if (order[e.src] <= low[e.dst]) is_artic = true;\n\
    \                if (order[e.src] < low[e.dst]) bridges.push_back(e);\n      \
    \      } else if (e.dst != r) {\n                low[e.src] = std::min(low[e.src],\
    \ order[e.dst]);\n            }\n        }\n\n        if (r < 0) is_artic = (deg\
    \ > 1);\n        if (is_artic) artics.push_back(v);\n    }\n};\n"
  code: "#pragma once\n\n#include \"graph.hpp\"\n\ntemplate <class Cost = int>\nstruct\
    \ Lowlink {\n    Graph<Cost> graph;\n    int time;\n    std::vector<int> order,\
    \ low;\n\n    std::vector<int> artics;\n    std::vector<Edge<Cost>> bridges;\n\
    \n    explicit Lowlink(const Graph<Cost>& graph)\n        : graph(graph), order(graph.size(),\
    \ -1), low(graph.size(), graph.size()) {\n        time = 0;\n        for (int\
    \ v = 0; v < (int)graph.size(); ++v) {\n            if (order[v] < 0) dfs(v, -1);\n\
    \        }\n    }\n\n    void dfs(int v, int r) {\n        order[v] = low[v] =\
    \ time++;\n        int deg = 0;\n        bool is_artic = false;\n\n        for\
    \ (auto e : graph[v]) {\n            if (order[e.dst] < 0) {\n               \
    \ ++deg;\n                dfs(e.dst, e.src);\n                low[e.src] = std::min(low[e.src],\
    \ low[e.dst]);\n\n                if (order[e.src] <= low[e.dst]) is_artic = true;\n\
    \                if (order[e.src] < low[e.dst]) bridges.push_back(e);\n      \
    \      } else if (e.dst != r) {\n                low[e.src] = std::min(low[e.src],\
    \ order[e.dst]);\n            }\n        }\n\n        if (r < 0) is_artic = (deg\
    \ > 1);\n        if (is_artic) artics.push_back(v);\n    }\n};\n"
  dependsOn:
  - Graph/graph.hpp
  isVerificationFile: false
  path: Graph/lowlink.hpp
  requiredBy: []
  timestamp: '2020-11-05 12:15:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/articulation_points.test.cpp
  - Verify/bridges.test.cpp
documentation_of: Graph/lowlink.hpp
layout: document
redirect_from:
- /library/Graph/lowlink.hpp
- /library/Graph/lowlink.hpp.html
title: Graph/lowlink.hpp
---
