---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/hld_lca.test.cpp
    title: Verify/hld_lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/hld_path.test.cpp
    title: Verify/hld_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/hld_subtree.test.cpp
    title: Verify/hld_subtree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/heavy_light_decomposition.hpp\"\n\n#line 2 \"Graph/graph.hpp\"\
    \n\n#include <vector>\n\ntemplate <class Cost = int>\nstruct Edge {\n    int src,\
    \ dst;\n    Cost cost;\n\n    Edge() = default;\n    Edge(int src, int dst, Cost\
    \ cost = 1)\n        : src(src), dst(dst), cost(cost){};\n\n    bool operator<(const\
    \ Edge<Cost>& e) const { return cost < e.cost; }\n    bool operator>(const Edge<Cost>&\
    \ e) const { return cost > e.cost; }\n};\n\ntemplate <class Cost = int>\nstruct\
    \ Graph : public std::vector<std::vector<Edge<Cost>>> {\n    using std::vector<std::vector<Edge<Cost>>>::vector;\n\
    \n    void span(bool direct, int src, int dst, Cost cost = 1) {\n        (*this)[src].emplace_back(src,\
    \ dst, cost);\n        if (!direct) (*this)[dst].emplace_back(dst, src, cost);\n\
    \    }\n};\n#line 4 \"Graph/heavy_light_decomposition.hpp\"\n\n#line 6 \"Graph/heavy_light_decomposition.hpp\"\
    \n\ntemplate <class Cost>\nstruct HeavyLightDecomposition {\n    // indexing\n\
    \    // v: a vertex in original graph\n    // i: assigned label of a vertex\n\n\
    \    Graph<Cost> graph;\n    std::vector<int> id, vs;  // id: v -> i, vs: i ->\
    \ v\n    std::vector<int> par, sz, head, dep, out;\n    // these are all v-indexed\n\
    \    // in equals to id\n    int time;\n\n    explicit HeavyLightDecomposition(const\
    \ Graph<Cost>& graph)\n        : graph(graph),\n          id(graph.size()),\n\
    \          vs(graph.size()),\n          par(graph.size()),\n          sz(graph.size()),\n\
    \          head(graph.size()),\n          dep(graph.size()),\n          out(graph.size()),\n\
    \          time(0) {\n        dfs_sz(0, -1, 0);\n        head[0] = 0;\n      \
    \  dfs_hld(0, -1);\n    }\n\n    void dfs_sz(int v, int p, int d) {\n        par[v]\
    \ = p;\n        sz[v] = 1;\n        dep[v] = d;\n\n        if (!graph[v].empty()\
    \ && graph[v].front().dst == p) {\n            std::swap(graph[v].front(), graph[v].back());\n\
    \        }\n\n        for (auto& e : graph[v]) {\n            if (e.dst == p)\
    \ continue;\n\n            dfs_sz(e.dst, v, d + 1);\n            sz[v] += sz[e.dst];\n\
    \n            // heavy edge first\n            if (sz[graph[v].front().dst] <\
    \ sz[e.dst]) {\n                std::swap(graph[v].front(), e);\n            }\n\
    \        }\n    }\n\n    void dfs_hld(int v, int p) {\n        id[v] = time++;\n\
    \        vs[id[v]] = v;\n\n        bool first = true;\n        for (auto e : graph[v])\
    \ {\n            if (e.dst == p) continue;\n\n            head[e.dst] = (first\
    \ ? head[v] : e.dst);\n            first = false;\n            dfs_hld(e.dst,\
    \ v);\n        }\n\n        out[v] = time;\n    }\n\n    int lca(int u, int v)\
    \ {\n        while (true) {\n            if (id[u] > id[v]) std::swap(u, v);\n\
    \            if (head[u] == head[v]) return u;\n            v = par[head[v]];\n\
    \        }\n    }\n\n    int dist(int u, int v) {\n        return dep[u] + dep[v]\
    \ - dep[lca(u, v)] * 2;\n    }\n\n    std::vector<std::pair<int, int>> path(int\
    \ u, int v, bool is_edge) {\n        std::vector<std::pair<int, int>> segs;\n\n\
    \        while (true) {\n            if (id[u] > id[v]) std::swap(u, v);\n\n \
    \           if (head[u] == head[v]) {\n                // when edge path, the\
    \ lca has to be excluded\n                segs.emplace_back(id[u] + is_edge, id[v]\
    \ + 1);\n                return segs;\n            }\n\n            segs.emplace_back(id[head[v]],\
    \ id[v] + 1);\n            v = par[head[v]];\n        }\n    }\n\n    std::pair<int,\
    \ int> subtree(int v, bool is_edge) {\n        // when edge path, the root has\
    \ to be excluded\n        return {id[v] + is_edge, out[v]};\n    }\n};\n"
  code: "#pragma once\n\n#include \"graph.hpp\"\n\n#include <vector>\n\ntemplate <class\
    \ Cost>\nstruct HeavyLightDecomposition {\n    // indexing\n    // v: a vertex\
    \ in original graph\n    // i: assigned label of a vertex\n\n    Graph<Cost> graph;\n\
    \    std::vector<int> id, vs;  // id: v -> i, vs: i -> v\n    std::vector<int>\
    \ par, sz, head, dep, out;\n    // these are all v-indexed\n    // in equals to\
    \ id\n    int time;\n\n    explicit HeavyLightDecomposition(const Graph<Cost>&\
    \ graph)\n        : graph(graph),\n          id(graph.size()),\n          vs(graph.size()),\n\
    \          par(graph.size()),\n          sz(graph.size()),\n          head(graph.size()),\n\
    \          dep(graph.size()),\n          out(graph.size()),\n          time(0)\
    \ {\n        dfs_sz(0, -1, 0);\n        head[0] = 0;\n        dfs_hld(0, -1);\n\
    \    }\n\n    void dfs_sz(int v, int p, int d) {\n        par[v] = p;\n      \
    \  sz[v] = 1;\n        dep[v] = d;\n\n        if (!graph[v].empty() && graph[v].front().dst\
    \ == p) {\n            std::swap(graph[v].front(), graph[v].back());\n       \
    \ }\n\n        for (auto& e : graph[v]) {\n            if (e.dst == p) continue;\n\
    \n            dfs_sz(e.dst, v, d + 1);\n            sz[v] += sz[e.dst];\n\n  \
    \          // heavy edge first\n            if (sz[graph[v].front().dst] < sz[e.dst])\
    \ {\n                std::swap(graph[v].front(), e);\n            }\n        }\n\
    \    }\n\n    void dfs_hld(int v, int p) {\n        id[v] = time++;\n        vs[id[v]]\
    \ = v;\n\n        bool first = true;\n        for (auto e : graph[v]) {\n    \
    \        if (e.dst == p) continue;\n\n            head[e.dst] = (first ? head[v]\
    \ : e.dst);\n            first = false;\n            dfs_hld(e.dst, v);\n    \
    \    }\n\n        out[v] = time;\n    }\n\n    int lca(int u, int v) {\n     \
    \   while (true) {\n            if (id[u] > id[v]) std::swap(u, v);\n        \
    \    if (head[u] == head[v]) return u;\n            v = par[head[v]];\n      \
    \  }\n    }\n\n    int dist(int u, int v) {\n        return dep[u] + dep[v] -\
    \ dep[lca(u, v)] * 2;\n    }\n\n    std::vector<std::pair<int, int>> path(int\
    \ u, int v, bool is_edge) {\n        std::vector<std::pair<int, int>> segs;\n\n\
    \        while (true) {\n            if (id[u] > id[v]) std::swap(u, v);\n\n \
    \           if (head[u] == head[v]) {\n                // when edge path, the\
    \ lca has to be excluded\n                segs.emplace_back(id[u] + is_edge, id[v]\
    \ + 1);\n                return segs;\n            }\n\n            segs.emplace_back(id[head[v]],\
    \ id[v] + 1);\n            v = par[head[v]];\n        }\n    }\n\n    std::pair<int,\
    \ int> subtree(int v, bool is_edge) {\n        // when edge path, the root has\
    \ to be excluded\n        return {id[v] + is_edge, out[v]};\n    }\n};\n"
  dependsOn:
  - Graph/graph.hpp
  isVerificationFile: false
  path: Graph/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2020-11-05 12:15:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/hld_lca.test.cpp
  - Verify/hld_path.test.cpp
  - Verify/hld_subtree.test.cpp
documentation_of: Graph/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/Graph/heavy_light_decomposition.hpp
- /library/Graph/heavy_light_decomposition.hpp.html
title: Graph/heavy_light_decomposition.hpp
---
