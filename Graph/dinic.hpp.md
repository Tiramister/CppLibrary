---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/bipartite_matching.hpp
    title: Graph/bipartite_matching.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/bipartite_matching.test.cpp
    title: Verify/bipartite_matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/dinic.test.cpp
    title: Verify/dinic.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/dinic.hpp\"\n\n#include <vector>\n#include <queue>\n\
    #include <limits>\n\ntemplate <class Cap, bool isDirect>\nstruct MaxFlow {\n \
    \   struct Edge {\n        int src, dst;\n        Cap cap;\n        Edge(int src,\
    \ int dst, Cap cap)\n            : src(src), dst(dst), cap(cap){};\n    };\n\n\
    \    using Edges = std::vector<Edge>;\n    using Graph = std::vector<std::vector<int>>;\n\
    \n    Edges edges;\n    Graph graph;\n    std::vector<int> dist, iter;\n\n   \
    \ explicit MaxFlow(int n)\n        : graph(n), dist(n), iter(n) {}\n\n    void\
    \ span(int u, int v, Cap cap) {\n        graph[u].push_back(edges.size());\n \
    \       edges.emplace_back(u, v, cap);\n\n        graph[v].push_back(edges.size());\n\
    \        edges.emplace_back(v, u, (isDirect ? 0 : cap));\n    }\n\n    void bfs(int\
    \ s) {\n        std::fill(dist.begin(), dist.end(), -1);\n        dist[s] = 0;\n\
    \        std::queue<int> que;\n        que.push(s);\n\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n\n            for\
    \ (int eidx : graph[v]) {\n                const auto& edge = edges[eidx];\n\n\
    \                if (edge.cap > 0 && dist[edge.dst] < 0) {\n                 \
    \   dist[edge.dst] = dist[v] + 1;\n                    que.push(edge.dst);\n \
    \               }\n            }\n        }\n    }\n\n    int dfs(int v, int g,\
    \ Cap f) {\n        if (v == g) return f;\n\n        for (int& itr = iter[v];\
    \ itr < (int)graph[v].size(); ++itr) {\n            int eidx = graph[v][itr];\n\
    \            auto& edge = edges[eidx];\n\n            if (edge.cap > 0 && dist[v]\
    \ < dist[edge.dst]) {\n                Cap df = dfs(edge.dst, g, std::min(f, edge.cap));\n\
    \n                if (df > 0) {\n                    edge.cap -= df;\n       \
    \             auto& redge = edges[eidx ^ 1];\n                    redge.cap +=\
    \ df;\n                    return df;\n                }\n            }\n    \
    \    }\n        return 0;\n    }\n\n    Cap exec(int s, int g) {\n        const\
    \ Cap INF = std::numeric_limits<Cap>::max();\n\n        Cap ret = 0;\n       \
    \ while (true) {\n            bfs(s);\n            if (dist[g] < 0) return ret;\n\
    \n            std::fill(iter.begin(), iter.end(), 0);\n            while (true)\
    \ {\n                Cap flow = dfs(s, g, INF);\n                if (flow == 0)\
    \ break;\n                ret += flow;\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <queue>\n#include <limits>\n\n\
    template <class Cap, bool isDirect>\nstruct MaxFlow {\n    struct Edge {\n   \
    \     int src, dst;\n        Cap cap;\n        Edge(int src, int dst, Cap cap)\n\
    \            : src(src), dst(dst), cap(cap){};\n    };\n\n    using Edges = std::vector<Edge>;\n\
    \    using Graph = std::vector<std::vector<int>>;\n\n    Edges edges;\n    Graph\
    \ graph;\n    std::vector<int> dist, iter;\n\n    explicit MaxFlow(int n)\n  \
    \      : graph(n), dist(n), iter(n) {}\n\n    void span(int u, int v, Cap cap)\
    \ {\n        graph[u].push_back(edges.size());\n        edges.emplace_back(u,\
    \ v, cap);\n\n        graph[v].push_back(edges.size());\n        edges.emplace_back(v,\
    \ u, (isDirect ? 0 : cap));\n    }\n\n    void bfs(int s) {\n        std::fill(dist.begin(),\
    \ dist.end(), -1);\n        dist[s] = 0;\n        std::queue<int> que;\n     \
    \   que.push(s);\n\n        while (!que.empty()) {\n            int v = que.front();\n\
    \            que.pop();\n\n            for (int eidx : graph[v]) {\n         \
    \       const auto& edge = edges[eidx];\n\n                if (edge.cap > 0 &&\
    \ dist[edge.dst] < 0) {\n                    dist[edge.dst] = dist[v] + 1;\n \
    \                   que.push(edge.dst);\n                }\n            }\n  \
    \      }\n    }\n\n    int dfs(int v, int g, Cap f) {\n        if (v == g) return\
    \ f;\n\n        for (int& itr = iter[v]; itr < (int)graph[v].size(); ++itr) {\n\
    \            int eidx = graph[v][itr];\n            auto& edge = edges[eidx];\n\
    \n            if (edge.cap > 0 && dist[v] < dist[edge.dst]) {\n              \
    \  Cap df = dfs(edge.dst, g, std::min(f, edge.cap));\n\n                if (df\
    \ > 0) {\n                    edge.cap -= df;\n                    auto& redge\
    \ = edges[eidx ^ 1];\n                    redge.cap += df;\n                 \
    \   return df;\n                }\n            }\n        }\n        return 0;\n\
    \    }\n\n    Cap exec(int s, int g) {\n        const Cap INF = std::numeric_limits<Cap>::max();\n\
    \n        Cap ret = 0;\n        while (true) {\n            bfs(s);\n        \
    \    if (dist[g] < 0) return ret;\n\n            std::fill(iter.begin(), iter.end(),\
    \ 0);\n            while (true) {\n                Cap flow = dfs(s, g, INF);\n\
    \                if (flow == 0) break;\n                ret += flow;\n       \
    \     }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/dinic.hpp
  requiredBy:
  - Graph/bipartite_matching.hpp
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/dinic.test.cpp
  - Verify/bipartite_matching.test.cpp
documentation_of: Graph/dinic.hpp
layout: document
redirect_from:
- /library/Graph/dinic.hpp
- /library/Graph/dinic.hpp.html
title: Graph/dinic.hpp
---