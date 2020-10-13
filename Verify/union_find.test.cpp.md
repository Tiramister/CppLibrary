---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/union_find.hpp
    title: DataStructure/union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"Verify/union_find.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#line 2 \"DataStructure/union_find.hpp\"\n\n#include <numeric>\n#include <vector>\n\
    \nstruct UnionFind {\n    std::vector<int> par, sz;\n    int gnum;\n\n    explicit\
    \ UnionFind(int n)\n        : par(n), sz(n, 1), gnum(n) {\n        std::iota(par.begin(),\
    \ par.end(), 0);\n    }\n\n    int find(int v) {\n        return (par[v] == v)\
    \ ? v : (par[v] = find(par[v]));\n    }\n\n    void unite(int u, int v) {\n  \
    \      u = find(u), v = find(v);\n        if (u == v) return;\n\n        if (sz[u]\
    \ < sz[v]) std::swap(u, v);\n        sz[u] += sz[v];\n        par[v] = u;\n  \
    \      --gnum;\n    }\n\n    bool same(int u, int v) { return find(u) == find(v);\
    \ }\n    bool ispar(int v) { return v == find(v); }\n    int size(int v) { return\
    \ sz[find(v)]; }\n};\n#line 4 \"Verify/union_find.test.cpp\"\n\n#include <iostream>\n\
    \nint main() {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n\
    \    int n, q;\n    std::cin >> n >> q;\n\n    UnionFind uf(n);\n    while (q--)\
    \ {\n        int t, u, v;\n        std::cin >> t >> u >> v;\n        if (t ==\
    \ 0) {\n            uf.unite(u, v);\n        } else {\n            std::cout <<\
    \ uf.same(u, v) << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../DataStructure/union_find.hpp\"\n\n#include <iostream>\n\nint main() {\n\
    \    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n    int n, q;\n\
    \    std::cin >> n >> q;\n\n    UnionFind uf(n);\n    while (q--) {\n        int\
    \ t, u, v;\n        std::cin >> t >> u >> v;\n        if (t == 0) {\n        \
    \    uf.unite(u, v);\n        } else {\n            std::cout << uf.same(u, v)\
    \ << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/union_find.hpp
  isVerificationFile: true
  path: Verify/union_find.test.cpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/union_find.test.cpp
layout: document
redirect_from:
- /verify/Verify/union_find.test.cpp
- /verify/Verify/union_find.test.cpp.html
title: Verify/union_find.test.cpp
---
