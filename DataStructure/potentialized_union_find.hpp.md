---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/potentialized_union_find.test.cpp
    title: Verify/potentialized_union_find.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/potentialized_union_find.hpp\"\n\n#include\
    \ <numeric>\n#include <vector>\n\ntemplate <class Dist>\nstruct PotentializedUnionFind\
    \ {\n    std::vector<int> par, sz;\n    std::vector<Dist> dist;  // A[par[v]]\
    \ - A[v] = dist[v]\n    int gnum;\n\n    explicit PotentializedUnionFind(int n)\n\
    \        : par(n), sz(n, 1), dist(n, 0), gnum(n) {\n        std::iota(par.begin(),\
    \ par.end(), 0);\n    }\n\n    int find(int v) {\n        if (par[v] == v) {\n\
    \            return v;\n        } else {\n            int p = find(par[v]);\n\
    \            dist[v] += dist[par[v]];\n            return par[v] = p;\n      \
    \  }\n    }\n\n    // A[u] - A[v] = d\n    void unite(int u, int v, Dist d) {\n\
    \        find(u), find(v);\n        d += dist[u];\n        d -= dist[v];\n   \
    \     u = par[u], v = par[v];\n        if (u == v) return;\n\n        if (sz[u]\
    \ < sz[v]) {\n            std::swap(u, v);\n            d = -d;\n        }\n\n\
    \        sz[u] += sz[v];\n        par[v] = u;\n        dist[v] = d;\n        --gnum;\n\
    \    }\n\n    // A[v] - A[u]\n    Dist diff(int u, int v) {\n        find(u),\
    \ find(v);\n        return dist[u] - dist[v];\n    }\n\n    bool same(int u, int\
    \ v) { return find(u) == find(v); }\n    bool ispar(int v) { return v == find(v);\
    \ }\n    int size(int v) { return sz[find(v)]; }\n};\n"
  code: "#pragma once\n\n#include <numeric>\n#include <vector>\n\ntemplate <class\
    \ Dist>\nstruct PotentializedUnionFind {\n    std::vector<int> par, sz;\n    std::vector<Dist>\
    \ dist;  // A[par[v]] - A[v] = dist[v]\n    int gnum;\n\n    explicit PotentializedUnionFind(int\
    \ n)\n        : par(n), sz(n, 1), dist(n, 0), gnum(n) {\n        std::iota(par.begin(),\
    \ par.end(), 0);\n    }\n\n    int find(int v) {\n        if (par[v] == v) {\n\
    \            return v;\n        } else {\n            int p = find(par[v]);\n\
    \            dist[v] += dist[par[v]];\n            return par[v] = p;\n      \
    \  }\n    }\n\n    // A[u] - A[v] = d\n    void unite(int u, int v, Dist d) {\n\
    \        find(u), find(v);\n        d += dist[u];\n        d -= dist[v];\n   \
    \     u = par[u], v = par[v];\n        if (u == v) return;\n\n        if (sz[u]\
    \ < sz[v]) {\n            std::swap(u, v);\n            d = -d;\n        }\n\n\
    \        sz[u] += sz[v];\n        par[v] = u;\n        dist[v] = d;\n        --gnum;\n\
    \    }\n\n    // A[v] - A[u]\n    Dist diff(int u, int v) {\n        find(u),\
    \ find(v);\n        return dist[u] - dist[v];\n    }\n\n    bool same(int u, int\
    \ v) { return find(u) == find(v); }\n    bool ispar(int v) { return v == find(v);\
    \ }\n    int size(int v) { return sz[find(v)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/potentialized_union_find.hpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/potentialized_union_find.test.cpp
documentation_of: DataStructure/potentialized_union_find.hpp
layout: document
redirect_from:
- /library/DataStructure/potentialized_union_find.hpp
- /library/DataStructure/potentialized_union_find.hpp.html
title: DataStructure/potentialized_union_find.hpp
---
