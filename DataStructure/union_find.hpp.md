---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/union_find.test.cpp
    title: Verify/union_find.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/union_find.hpp\"\n\n#include <numeric>\n#include\
    \ <vector>\n\nstruct UnionFind {\n    std::vector<int> par, sz;\n    int gnum;\n\
    \n    explicit UnionFind(int n)\n        : par(n), sz(n, 1), gnum(n) {\n     \
    \   std::iota(par.begin(), par.end(), 0);\n    }\n\n    int find(int v) {\n  \
    \      return (par[v] == v) ? v : (par[v] = find(par[v]));\n    }\n\n    void\
    \ unite(int u, int v) {\n        u = find(u), v = find(v);\n        if (u == v)\
    \ return;\n\n        if (sz[u] < sz[v]) std::swap(u, v);\n        sz[u] += sz[v];\n\
    \        par[v] = u;\n        --gnum;\n    }\n\n    bool same(int u, int v) {\
    \ return find(u) == find(v); }\n    bool ispar(int v) { return v == find(v); }\n\
    \    int size(int v) { return sz[find(v)]; }\n};\n"
  code: "#pragma once\n\n#include <numeric>\n#include <vector>\n\nstruct UnionFind\
    \ {\n    std::vector<int> par, sz;\n    int gnum;\n\n    explicit UnionFind(int\
    \ n)\n        : par(n), sz(n, 1), gnum(n) {\n        std::iota(par.begin(), par.end(),\
    \ 0);\n    }\n\n    int find(int v) {\n        return (par[v] == v) ? v : (par[v]\
    \ = find(par[v]));\n    }\n\n    void unite(int u, int v) {\n        u = find(u),\
    \ v = find(v);\n        if (u == v) return;\n\n        if (sz[u] < sz[v]) std::swap(u,\
    \ v);\n        sz[u] += sz[v];\n        par[v] = u;\n        --gnum;\n    }\n\n\
    \    bool same(int u, int v) { return find(u) == find(v); }\n    bool ispar(int\
    \ v) { return v == find(v); }\n    int size(int v) { return sz[find(v)]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/union_find.hpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/union_find.test.cpp
documentation_of: DataStructure/union_find.hpp
layout: document
redirect_from:
- /library/DataStructure/union_find.hpp
- /library/DataStructure/union_find.hpp.html
title: DataStructure/union_find.hpp
---
