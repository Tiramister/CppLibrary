---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/level_ancestor.hpp
    title: Graph/level_ancestor.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"Verify/level_ancestor.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n\n#line 2 \"Graph/level_ancestor.hpp\"\n\n#line 2 \"Graph/graph.hpp\"\n\n#include\
    \ <vector>\n\ntemplate <class Cost = int>\nstruct Edge {\n    int src, dst;\n\
    \    Cost cost;\n\n    Edge() = default;\n    Edge(int src, int dst, Cost cost\
    \ = 1)\n        : src(src), dst(dst), cost(cost){};\n\n    bool operator<(const\
    \ Edge<Cost>& e) const { return cost < e.cost; }\n    bool operator>(const Edge<Cost>&\
    \ e) const { return cost > e.cost; }\n};\n\ntemplate <class Cost = int>\nstruct\
    \ Graph : public std::vector<std::vector<Edge<Cost>>> {\n    using std::vector<std::vector<Edge<Cost>>>::vector;\n\
    \n    void span(bool direct, int src, int dst, Cost cost = 1) {\n        (*this)[src].emplace_back(src,\
    \ dst, cost);\n        if (!direct) (*this)[dst].emplace_back(dst, src, cost);\n\
    \    }\n};\n#line 4 \"Graph/level_ancestor.hpp\"\n\ntemplate <class Cost = int>\n\
    struct LevelAncestor {\n    Graph<Cost> tree;\n    std::vector<std::vector<int>>\
    \ par;\n    std::vector<int> depth;\n    std::vector<Cost> cdepth;\n    int kmax;\n\
    \n    void dfs(int v, int p = -1, int d = 0, Cost c = 0) {\n        par[v][0]\
    \ = p;\n        depth[v] = d;\n        cdepth[v] = c;\n\n        for (const auto&\
    \ e : tree[v]) {\n            if (e.dst == p) continue;\n            dfs(e.dst,\
    \ v, d + 1, c + e.cost);\n        }\n    }\n\n    LevelAncestor(const Graph<Cost>&\
    \ tree, int root)\n        : tree(tree), par(tree.size()), depth(tree.size(),\
    \ -1), cdepth(tree.size()) {\n        kmax = 0;\n        while ((1 << kmax) <\
    \ (int)tree.size()) ++kmax;\n        for (auto& v : par) v.resize(kmax + 1);\n\
    \n        dfs(root);\n\n        for (int k = 1; k <= kmax; ++k) {\n          \
    \  for (int v = 0; v < (int)tree.size(); ++v) {\n                int p = par[v][k\
    \ - 1];\n                par[v][k] = (p == -1 ? -1 : par[p][k - 1]);\n       \
    \     }\n        }\n    }\n\n    int climb(int v, int d) const {\n        for\
    \ (int k = kmax; k >= 0 && v != -1; --k) {\n            if ((1 << k) > d) continue;\n\
    \n            v = par[v][k];\n            d -= (1 << k);\n        }\n        return\
    \ v;\n    }\n\n    int lca(int u, int v) const {\n        if (depth[u] < depth[v])\
    \ std::swap(u, v);\n\n        if (depth[u] > depth[v]) {\n            u = climb(u,\
    \ depth[u] - depth[v]);\n        }\n\n        if (u == v) return u;\n\n      \
    \  for (int k = kmax; k >= 0; --k) {\n            if (par[u][k] != par[v][k])\
    \ {\n                u = par[u][k];\n                v = par[v][k];\n        \
    \    }\n        }\n        return par[u][0];\n    }\n\n    int dist(int u, int\
    \ v) const {\n        int p = lca(u, v);\n        return depth[u] + depth[v] -\
    \ depth[p] * 2;\n    }\n\n    Cost cdist(int u, int v) const {\n        int p\
    \ = lca(u, v);\n        return cdepth[u] + cdepth[v] - cdepth[p] * 2;\n    }\n\
    };\n#line 4 \"Verify/level_ancestor.test.cpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\n   \
    \ int n, q;\n    std::cin >> n >> q;\n\n    Graph<> graph(n);\n    for (int v\
    \ = 1; v < n; ++v) {\n        int p;\n        std::cin >> p;\n        graph.span(false,\
    \ p, v);\n    }\n\n    LevelAncestor la(graph, 0);\n\n    while (q--) {\n    \
    \    int u, v;\n        std::cin >> u >> v;\n        std::cout << la.lca(u, v)\
    \ << \"\\n\";\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../Graph/level_ancestor.hpp\"\
    \n\n#include <iostream>\n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \n    int n, q;\n    std::cin >> n >> q;\n\n    Graph<> graph(n);\n    for (int\
    \ v = 1; v < n; ++v) {\n        int p;\n        std::cin >> p;\n        graph.span(false,\
    \ p, v);\n    }\n\n    LevelAncestor la(graph, 0);\n\n    while (q--) {\n    \
    \    int u, v;\n        std::cin >> u >> v;\n        std::cout << la.lca(u, v)\
    \ << \"\\n\";\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - Graph/level_ancestor.hpp
  - Graph/graph.hpp
  isVerificationFile: true
  path: Verify/level_ancestor.test.cpp
  requiredBy: []
  timestamp: '2020-11-05 12:15:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/level_ancestor.test.cpp
layout: document
redirect_from:
- /verify/Verify/level_ancestor.test.cpp
- /verify/Verify/level_ancestor.test.cpp.html
title: Verify/level_ancestor.test.cpp
---
