---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/ford_fulkerson.hpp
    title: Graph/ford_fulkerson.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A
  bundledCode: "#line 1 \"Verify/ford_fulkerson.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A\"\
    \n\n#line 2 \"Graph/ford_fulkerson.hpp\"\n\n#include <vector>\n#include <limits>\n\
    \ntemplate <class Cap, bool isDirect>\nstruct MaxFlow {\n    struct Edge {\n \
    \       int src, dst;\n        Cap cap;\n        Edge(int src, int dst, Cap cap)\n\
    \            : src(src), dst(dst), cap(cap){};\n    };\n\n    std::vector<Edge>\
    \ edges;\n    std::vector<std::vector<int>> graph;\n    std::vector<bool> visited;\n\
    \n    explicit MaxFlow(int n) : graph(n), visited(n) {}\n\n    void span(int u,\
    \ int v, Cap cap) {\n        graph[u].push_back(edges.size());\n        edges.emplace_back(u,\
    \ v, cap);\n\n        graph[v].push_back(edges.size());\n        edges.emplace_back(v,\
    \ u, (isDirect ? 0 : cap));\n    }\n\n    Cap dfs(int v, int g, Cap f) {\n   \
    \     if (v == g) return f;\n\n        visited[v] = true;\n        for (auto eidx\
    \ : graph[v]) {\n            auto& edge = edges[eidx];\n\n            if (edge.cap\
    \ > 0 && !visited[edge.dst]) {\n                auto df = dfs(edge.dst, g, std::min(f,\
    \ edge.cap));\n\n                if (df > 0) {\n                    edge.cap -=\
    \ df;\n                    auto& redge = edges[eidx ^ 1];\n                  \
    \  redge.cap += df;\n                    return df;\n                }\n     \
    \       }\n        }\n        return 0;\n    }\n\n    Cap flow(int s, int g) {\n\
    \        constexpr Cap INF = std::numeric_limits<Cap>::max();\n\n        Cap ret\
    \ = 0;\n        while (true) {\n            std::fill(visited.begin(), visited.end(),\
    \ false);\n            Cap f = dfs(s, g, INF);\n            if (f == 0) return\
    \ ret;\n            ret += f;\n        }\n    }\n};\n#line 4 \"Verify/ford_fulkerson.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\
    \n    int n, m;\n    std::cin >> n >> m;\n\n    MaxFlow<int, true> mf(n);\n  \
    \  while (m--) {\n        int u, v, c;\n        std::cin >> u >> v >> c;\n   \
    \     mf.span(u, v, c);\n    }\n\n    std::cout << mf.flow(0, n - 1) << \"\\n\"\
    ;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A\"\
    \n\n#include \"../Graph/ford_fulkerson.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n    int n,\
    \ m;\n    std::cin >> n >> m;\n\n    MaxFlow<int, true> mf(n);\n    while (m--)\
    \ {\n        int u, v, c;\n        std::cin >> u >> v >> c;\n        mf.span(u,\
    \ v, c);\n    }\n\n    std::cout << mf.flow(0, n - 1) << \"\\n\";\n    return\
    \ 0;\n}\n"
  dependsOn:
  - Graph/ford_fulkerson.hpp
  isVerificationFile: true
  path: Verify/ford_fulkerson.test.cpp
  requiredBy: []
  timestamp: '2020-11-03 10:32:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/ford_fulkerson.test.cpp
layout: document
redirect_from:
- /verify/Verify/ford_fulkerson.test.cpp
- /verify/Verify/ford_fulkerson.test.cpp.html
title: Verify/ford_fulkerson.test.cpp
---
