---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/centroid_decomposition_diameter.test.cpp
    title: Verify/centroid_decomposition_diameter.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/centroid_decomposition.hpp\"\n\n#line 2 \"Graph/graph.hpp\"\
    \n\n#include <vector>\n\ntemplate <class Cost = int>\nstruct Edge {\n    int src,\
    \ dst;\n    Cost cost;\n\n    Edge() = default;\n    Edge(int src, int dst, Cost\
    \ cost = 1)\n        : src(src), dst(dst), cost(cost){};\n\n    bool operator<(const\
    \ Edge<Cost>& e) const { return cost < e.cost; }\n    bool operator>(const Edge<Cost>&\
    \ e) const { return cost > e.cost; }\n};\n\ntemplate <class Cost = int>\nstruct\
    \ Graph : public std::vector<std::vector<Edge<Cost>>> {\n    Graph(int n = 0)\
    \ : std::vector<std::vector<Edge<Cost>>>(n) {}\n\n    void span(bool direct, int\
    \ src, int dst, Cost cost = 1) {\n        (*this)[src].emplace_back(src, dst,\
    \ cost);\n        if (!direct) (*this)[dst].emplace_back(dst, src, cost);\n  \
    \  }\n};\n#line 4 \"Graph/centroid_decomposition.hpp\"\n\ntemplate <class Cost\
    \ = int>\nstruct Centroid {\n    Graph<Cost> graph;\n    std::vector<bool> deleted;\n\
    \    std::vector<int> sz;\n\n    explicit Centroid(const Graph<Cost>& graph)\n\
    \        : graph(graph), deleted(graph.size(), false), sz(graph.size()) {}\n\n\
    \    int szdfs(int v, int p = -1) {\n        sz[v] = 1;\n        for (auto e :\
    \ graph[v]) {\n            if (e.dst == p || deleted[e.dst]) continue;\n     \
    \       sz[v] += szdfs(e.dst, v);\n        }\n        return sz[v];\n    }\n\n\
    \    int find(int v) {\n        int n = szdfs(v);\n\n        int p = -1;\n   \
    \     while (true) {\n            int nxt = -1;\n            for (auto e : graph[v])\
    \ {\n                if (e.dst == p || deleted[e.dst]) continue;\n           \
    \     if (nxt == -1 || sz[e.dst] > sz[nxt]) nxt = e.dst;\n            }\n\n  \
    \          if (nxt == -1 || sz[nxt] <= n / 2) return v;\n            p = v;\n\
    \            v = nxt;\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include \"../Graph/graph.hpp\"\n\ntemplate <class Cost =\
    \ int>\nstruct Centroid {\n    Graph<Cost> graph;\n    std::vector<bool> deleted;\n\
    \    std::vector<int> sz;\n\n    explicit Centroid(const Graph<Cost>& graph)\n\
    \        : graph(graph), deleted(graph.size(), false), sz(graph.size()) {}\n\n\
    \    int szdfs(int v, int p = -1) {\n        sz[v] = 1;\n        for (auto e :\
    \ graph[v]) {\n            if (e.dst == p || deleted[e.dst]) continue;\n     \
    \       sz[v] += szdfs(e.dst, v);\n        }\n        return sz[v];\n    }\n\n\
    \    int find(int v) {\n        int n = szdfs(v);\n\n        int p = -1;\n   \
    \     while (true) {\n            int nxt = -1;\n            for (auto e : graph[v])\
    \ {\n                if (e.dst == p || deleted[e.dst]) continue;\n           \
    \     if (nxt == -1 || sz[e.dst] > sz[nxt]) nxt = e.dst;\n            }\n\n  \
    \          if (nxt == -1 || sz[nxt] <= n / 2) return v;\n            p = v;\n\
    \            v = nxt;\n        }\n    }\n};\n"
  dependsOn:
  - Graph/graph.hpp
  isVerificationFile: false
  path: Graph/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2020-10-13 21:34:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/centroid_decomposition_diameter.test.cpp
documentation_of: Graph/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/Graph/centroid_decomposition.hpp
- /library/Graph/centroid_decomposition.hpp.html
title: Graph/centroid_decomposition.hpp
---
