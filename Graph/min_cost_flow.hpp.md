---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/min_cost_flow.test.cpp
    title: Verify/min_cost_flow.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/min_cost_flow.hpp\"\n\n#include <vector>\n#include\
    \ <limits>\n\ntemplate <class Cap, class Cost>\nstruct MinCostFlow {\n    struct\
    \ Edge {\n        int src, dst;\n        Cap cap;\n        Cost cost;\n      \
    \  Edge(int src, int dst, Cap cap, Cost cost)\n            : src(src), dst(dst),\
    \ cap(cap), cost(cost){};\n    };\n\n    using Edges = std::vector<Edge>;\n  \
    \  using Graph = std::vector<std::vector<int>>;\n\n    Edges edges;\n    Graph\
    \ graph;\n    std::vector<Cost> dist;\n    std::vector<int> rev;\n\n    const\
    \ Cost INF = std::numeric_limits<Cost>::max() / 2;\n\n    explicit MinCostFlow(int\
    \ n) : graph(n), dist(n), rev(n) {}\n\n    void span(int u, int v, Cap cap, Cost\
    \ cost) {\n        graph[u].push_back(edges.size());\n        edges.emplace_back(u,\
    \ v, cap, cost);\n\n        graph[v].push_back(edges.size());\n        edges.emplace_back(v,\
    \ u, 0, -cost);\n    }\n\n    void bellman_ford(int s) {\n        std::fill(dist.begin(),\
    \ dist.end(), INF);\n        dist[s] = 0;\n\n        for (int i = 0; i < (int)graph.size();\
    \ ++i) {\n            for (int eidx = 0; eidx < (int)edges.size(); ++eidx) {\n\
    \                const auto& edge = edges[eidx];\n                int u = edge.src,\
    \ v = edge.dst;\n\n                if (edge.cap > 0 &&\n                    dist[u]\
    \ < INF &&\n                    dist[v] > dist[u] + edge.cost) {\n           \
    \         dist[v] = dist[u] + edge.cost;\n                    rev[v] = eidx;\n\
    \                }\n            }\n        }\n    }\n\n    Cost exec(int s, int\
    \ g, Cap flow) {\n        Cost ret = 0;\n\n        while (flow > 0) {\n      \
    \      bellman_ford(s);\n            if (dist[g] == INF) break;\n\n          \
    \  Cap f = flow;\n            int v = g;\n            while (v != s) {\n     \
    \           const auto& edge = edges[rev[v]];\n                f = std::min(f,\
    \ edge.cap);\n                v = edge.src;\n            }\n\n            flow\
    \ -= f;\n            ret += f * dist[g];\n\n            v = g;\n            while\
    \ (v != s) {\n                auto& edge = edges[rev[v]];\n                auto&\
    \ redge = edges[rev[v] ^ 1];\n                edge.cap -= f;\n               \
    \ redge.cap += f;\n                v = edge.src;\n            }\n        }\n \
    \       return (flow > 0 ? -1 : ret);\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <limits>\n\ntemplate <class Cap,\
    \ class Cost>\nstruct MinCostFlow {\n    struct Edge {\n        int src, dst;\n\
    \        Cap cap;\n        Cost cost;\n        Edge(int src, int dst, Cap cap,\
    \ Cost cost)\n            : src(src), dst(dst), cap(cap), cost(cost){};\n    };\n\
    \n    using Edges = std::vector<Edge>;\n    using Graph = std::vector<std::vector<int>>;\n\
    \n    Edges edges;\n    Graph graph;\n    std::vector<Cost> dist;\n    std::vector<int>\
    \ rev;\n\n    const Cost INF = std::numeric_limits<Cost>::max() / 2;\n\n    explicit\
    \ MinCostFlow(int n) : graph(n), dist(n), rev(n) {}\n\n    void span(int u, int\
    \ v, Cap cap, Cost cost) {\n        graph[u].push_back(edges.size());\n      \
    \  edges.emplace_back(u, v, cap, cost);\n\n        graph[v].push_back(edges.size());\n\
    \        edges.emplace_back(v, u, 0, -cost);\n    }\n\n    void bellman_ford(int\
    \ s) {\n        std::fill(dist.begin(), dist.end(), INF);\n        dist[s] = 0;\n\
    \n        for (int i = 0; i < (int)graph.size(); ++i) {\n            for (int\
    \ eidx = 0; eidx < (int)edges.size(); ++eidx) {\n                const auto& edge\
    \ = edges[eidx];\n                int u = edge.src, v = edge.dst;\n\n        \
    \        if (edge.cap > 0 &&\n                    dist[u] < INF &&\n         \
    \           dist[v] > dist[u] + edge.cost) {\n                    dist[v] = dist[u]\
    \ + edge.cost;\n                    rev[v] = eidx;\n                }\n      \
    \      }\n        }\n    }\n\n    Cost exec(int s, int g, Cap flow) {\n      \
    \  Cost ret = 0;\n\n        while (flow > 0) {\n            bellman_ford(s);\n\
    \            if (dist[g] == INF) break;\n\n            Cap f = flow;\n       \
    \     int v = g;\n            while (v != s) {\n                const auto& edge\
    \ = edges[rev[v]];\n                f = std::min(f, edge.cap);\n             \
    \   v = edge.src;\n            }\n\n            flow -= f;\n            ret +=\
    \ f * dist[g];\n\n            v = g;\n            while (v != s) {\n         \
    \       auto& edge = edges[rev[v]];\n                auto& redge = edges[rev[v]\
    \ ^ 1];\n                edge.cap -= f;\n                redge.cap += f;\n   \
    \             v = edge.src;\n            }\n        }\n        return (flow >\
    \ 0 ? -1 : ret);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/min_cost_flow.hpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/min_cost_flow.test.cpp
documentation_of: Graph/min_cost_flow.hpp
layout: document
redirect_from:
- /library/Graph/min_cost_flow.hpp
- /library/Graph/min_cost_flow.hpp.html
title: Graph/min_cost_flow.hpp
---
