---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/potentialized_union_find.hpp
    title: DataStructure/potentialized_union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
  bundledCode: "#line 1 \"Verify/potentialized_union_find.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\n\n#line\
    \ 2 \"DataStructure/potentialized_union_find.hpp\"\n\n#include <vector>\n\ntemplate\
    \ <class Dist>\nstruct PotentializedUnionFind {\n    std::vector<int> par;\n \
    \   std::vector<Dist> dist;  // A[par[v]] - A[v] = dist[v]\n    int gnum;\n\n\
    \    explicit PotentializedUnionFind(int n)\n        : par(n, -1), dist(n, 0),\
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
    \ find(v); }\n    int size(int v) { return -par[find(v)]; }\n};\n#line 4 \"Verify/potentialized_union_find.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\
    \n    int n, q;\n    std::cin >> n >> q;\n    PotentializedUnionFind<int> puf(n);\n\
    \n    while (q--) {\n        int t, u, v;\n        std::cin >> t >> u >> v;\n\n\
    \        if (t == 0) {\n            int d;\n            std::cin >> d;\n     \
    \       puf.unite(v, u, d);\n\n        } else {\n            if (!puf.same(u,\
    \ v)) {\n                std::cout << \"?\\n\";\n            } else {\n      \
    \          std::cout << puf.diff(v, u) << \"\\n\";\n            }\n        }\n\
    \    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\
    \n\n#include \"../DataStructure/potentialized_union_find.hpp\"\n\n#include <iostream>\n\
    \nint main() {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n\
    \    int n, q;\n    std::cin >> n >> q;\n    PotentializedUnionFind<int> puf(n);\n\
    \n    while (q--) {\n        int t, u, v;\n        std::cin >> t >> u >> v;\n\n\
    \        if (t == 0) {\n            int d;\n            std::cin >> d;\n     \
    \       puf.unite(v, u, d);\n\n        } else {\n            if (!puf.same(u,\
    \ v)) {\n                std::cout << \"?\\n\";\n            } else {\n      \
    \          std::cout << puf.diff(v, u) << \"\\n\";\n            }\n        }\n\
    \    }\n\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/potentialized_union_find.hpp
  isVerificationFile: true
  path: Verify/potentialized_union_find.test.cpp
  requiredBy: []
  timestamp: '2020-11-03 12:50:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/potentialized_union_find.test.cpp
layout: document
redirect_from:
- /verify/Verify/potentialized_union_find.test.cpp
- /verify/Verify/potentialized_union_find.test.cpp.html
title: Verify/potentialized_union_find.test.cpp
---
