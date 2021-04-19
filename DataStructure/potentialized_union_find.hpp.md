---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/potentialized_union_find.test.cpp
    title: Verify/potentialized_union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/potentialized_union_find.hpp\"\n\n#include\
    \ <vector>\n\ntemplate <class Dist>\nstruct PotentializedUnionFind {\n    std::vector<int>\
    \ par;\n    std::vector<Dist> dist;  // A[par[v]] - A[v] = dist[v]\n    int gnum;\n\
    \n    explicit PotentializedUnionFind(int n)\n        : par(n, -1), dist(n, 0),\
    \ gnum(n) {}\n\n    int find(int v) {\n        if (par[v] < 0) {\n           \
    \ return v;\n        } else {\n            auto p = find(par[v]);\n          \
    \  dist[v] += dist[par[v]];\n            return par[v] = p;\n        }\n    }\n\
    \n    // A[u] - A[v] = d\n    void unite(int u, int v, Dist d) {\n        auto\
    \ pu = find(u), pv = find(v);\n        d += dist[u];\n        d -= dist[v];\n\
    \        u = pu, v = pv;\n        if (u == v) return;\n\n        if (par[u] >\
    \ par[v]) {\n            std::swap(u, v);\n            d = -d;\n        }\n\n\
    \        par[u] += par[v];\n        par[v] = u;\n        dist[v] = d;\n      \
    \  --gnum;\n    }\n\n    // A[u] - A[v]\n    Dist diff(int u, int v) {\n     \
    \   find(u), find(v);\n        return dist[v] - dist[u];\n    }\n\n    bool same(int\
    \ u, int v) { return find(u) == find(v); }\n    bool ispar(int v) { return v ==\
    \ find(v); }\n    int size(int v) { return -par[find(v)]; }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate <class Dist>\nstruct PotentializedUnionFind\
    \ {\n    std::vector<int> par;\n    std::vector<Dist> dist;  // A[par[v]] - A[v]\
    \ = dist[v]\n    int gnum;\n\n    explicit PotentializedUnionFind(int n)\n   \
    \     : par(n, -1), dist(n, 0), gnum(n) {}\n\n    int find(int v) {\n        if\
    \ (par[v] < 0) {\n            return v;\n        } else {\n            auto p\
    \ = find(par[v]);\n            dist[v] += dist[par[v]];\n            return par[v]\
    \ = p;\n        }\n    }\n\n    // A[u] - A[v] = d\n    void unite(int u, int\
    \ v, Dist d) {\n        auto pu = find(u), pv = find(v);\n        d += dist[u];\n\
    \        d -= dist[v];\n        u = pu, v = pv;\n        if (u == v) return;\n\
    \n        if (par[u] > par[v]) {\n            std::swap(u, v);\n            d\
    \ = -d;\n        }\n\n        par[u] += par[v];\n        par[v] = u;\n       \
    \ dist[v] = d;\n        --gnum;\n    }\n\n    // A[u] - A[v]\n    Dist diff(int\
    \ u, int v) {\n        find(u), find(v);\n        return dist[v] - dist[u];\n\
    \    }\n\n    bool same(int u, int v) { return find(u) == find(v); }\n    bool\
    \ ispar(int v) { return v == find(v); }\n    int size(int v) { return -par[find(v)];\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/potentialized_union_find.hpp
  requiredBy: []
  timestamp: '2020-11-03 12:50:03+09:00'
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
