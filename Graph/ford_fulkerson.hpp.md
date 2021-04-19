---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/ford_fulkerson.test.cpp
    title: Verify/ford_fulkerson.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/ford_fulkerson.hpp\"\n\n#include <vector>\n#include\
    \ <limits>\n\ntemplate <class Cap, bool isDirect>\nstruct MaxFlow {\n    struct\
    \ Edge {\n        int src, dst;\n        Cap cap;\n        Edge(int src, int dst,\
    \ Cap cap)\n            : src(src), dst(dst), cap(cap){};\n    };\n\n    std::vector<Edge>\
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
    \ ret;\n            ret += f;\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <limits>\n\ntemplate <class Cap,\
    \ bool isDirect>\nstruct MaxFlow {\n    struct Edge {\n        int src, dst;\n\
    \        Cap cap;\n        Edge(int src, int dst, Cap cap)\n            : src(src),\
    \ dst(dst), cap(cap){};\n    };\n\n    std::vector<Edge> edges;\n    std::vector<std::vector<int>>\
    \ graph;\n    std::vector<bool> visited;\n\n    explicit MaxFlow(int n) : graph(n),\
    \ visited(n) {}\n\n    void span(int u, int v, Cap cap) {\n        graph[u].push_back(edges.size());\n\
    \        edges.emplace_back(u, v, cap);\n\n        graph[v].push_back(edges.size());\n\
    \        edges.emplace_back(v, u, (isDirect ? 0 : cap));\n    }\n\n    Cap dfs(int\
    \ v, int g, Cap f) {\n        if (v == g) return f;\n\n        visited[v] = true;\n\
    \        for (auto eidx : graph[v]) {\n            auto& edge = edges[eidx];\n\
    \n            if (edge.cap > 0 && !visited[edge.dst]) {\n                auto\
    \ df = dfs(edge.dst, g, std::min(f, edge.cap));\n\n                if (df > 0)\
    \ {\n                    edge.cap -= df;\n                    auto& redge = edges[eidx\
    \ ^ 1];\n                    redge.cap += df;\n                    return df;\n\
    \                }\n            }\n        }\n        return 0;\n    }\n\n   \
    \ Cap flow(int s, int g) {\n        constexpr Cap INF = std::numeric_limits<Cap>::max();\n\
    \n        Cap ret = 0;\n        while (true) {\n            std::fill(visited.begin(),\
    \ visited.end(), false);\n            Cap f = dfs(s, g, INF);\n            if\
    \ (f == 0) return ret;\n            ret += f;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/ford_fulkerson.hpp
  requiredBy: []
  timestamp: '2020-11-03 10:32:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/ford_fulkerson.test.cpp
documentation_of: Graph/ford_fulkerson.hpp
layout: document
redirect_from:
- /library/Graph/ford_fulkerson.hpp
- /library/Graph/ford_fulkerson.hpp.html
title: Graph/ford_fulkerson.hpp
---
