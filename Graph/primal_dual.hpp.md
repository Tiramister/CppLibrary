---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Tools/heap_alias.hpp
    title: Tools/heap_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/primal_dual.test.cpp
    title: Verify/primal_dual.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Tools/heap_alias.hpp\"\n\n#include <queue>\n\ntemplate <class\
    \ T>\nusing MaxHeap = std::priority_queue<T>;\ntemplate <class T>\nusing MinHeap\
    \ = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n#line 2 \"Graph/primal_dual.hpp\"\
    \n\n#include <vector>\n#include <tuple>\n#include <limits>\n\ntemplate <class\
    \ Cap, class Cost>\nstruct MinCostFlow {\n    struct Edge {\n        int src,\
    \ dst;\n        Cap cap;\n        Cost cost;\n        Edge(int src, int dst, Cap\
    \ cap, Cost cost)\n            : src(src), dst(dst), cap(cap), cost(cost){};\n\
    \    };\n\n    std::vector<Edge> edges;\n    std::vector<std::vector<int>> graph;\n\
    \n    std::vector<Cost> dist, pot;\n    std::vector<int> rev;\n\n    const Cost\
    \ INF = std::numeric_limits<Cost>::max() / 2;\n\n    explicit MinCostFlow(int\
    \ n) : graph(n), dist(n), pot(n), rev(n) {}\n\n    void span(int u, int v, Cap\
    \ cap, Cost cost) {\n        graph[u].push_back(edges.size());\n        edges.emplace_back(u,\
    \ v, cap, cost);\n\n        graph[v].push_back(edges.size());\n        edges.emplace_back(v,\
    \ u, 0, -cost);\n    }\n\n    void dijkstra(int s) {\n        std::fill(dist.begin(),\
    \ dist.end(), INF);\n        dist[s] = 0;\n        MinHeap<std::pair<Cost, int>>\
    \ heap;\n        heap.emplace(0, s);\n\n        while (!heap.empty()) {\n    \
    \        auto [d, u] = heap.top();\n            heap.pop();\n            if (d\
    \ > dist[u]) continue;\n\n            for (auto eidx : graph[u]) {\n         \
    \       const auto& edge = edges[eidx];\n                auto v = edge.dst;\n\n\
    \                if (edge.cap > 0 && dist[u] < INF &&\n                    dist[v]\
    \ > dist[u] + edge.cost + pot[u] - pot[v]) {\n                    dist[v] = dist[u]\
    \ + edge.cost + pot[u] - pot[v];\n                    rev[v] = eidx;\n       \
    \             heap.emplace(dist[v], v);\n                }\n            }\n  \
    \      }\n    }\n\n    std::pair<Cap, Cost> flow(int s, int g, Cap flow_limit)\
    \ {\n        Cap fsum = 0;\n        Cost csum = 0;\n        std::fill(pot.begin(),\
    \ pot.end(), 0);\n\n        while (flow_limit > 0) {\n            dijkstra(s);\n\
    \            if (dist[g] == INF) break;\n\n            for (int v = 0; v < (int)graph.size();\
    \ ++v) {\n                pot[v] = std::min(pot[v] + dist[v], INF);\n        \
    \    }\n\n            Cap f = flow_limit;\n            int v = g;\n          \
    \  while (v != s) {\n                const auto& edge = edges[rev[v]];\n     \
    \           f = std::min(f, edge.cap);\n                v = edge.src;\n      \
    \      }\n\n            flow_limit -= f;\n            fsum += f;\n           \
    \ csum += f * pot[g];\n\n            v = g;\n            while (v != s) {\n  \
    \              auto& edge = edges[rev[v]];\n                auto& redge = edges[rev[v]\
    \ ^ 1];\n                edge.cap -= f;\n                redge.cap += f;\n   \
    \             v = edge.src;\n            }\n        }\n        return {fsum, csum};\n\
    \    }\n\n    std::pair<Cap, Cost> flow(int s, int g) {\n        return flow(s,\
    \ g, std::numeric_limits<Cap>::max());\n    }\n};\n"
  code: "#include \"../Tools/heap_alias.hpp\"\n\n#include <vector>\n#include <tuple>\n\
    #include <limits>\n\ntemplate <class Cap, class Cost>\nstruct MinCostFlow {\n\
    \    struct Edge {\n        int src, dst;\n        Cap cap;\n        Cost cost;\n\
    \        Edge(int src, int dst, Cap cap, Cost cost)\n            : src(src), dst(dst),\
    \ cap(cap), cost(cost){};\n    };\n\n    std::vector<Edge> edges;\n    std::vector<std::vector<int>>\
    \ graph;\n\n    std::vector<Cost> dist, pot;\n    std::vector<int> rev;\n\n  \
    \  const Cost INF = std::numeric_limits<Cost>::max() / 2;\n\n    explicit MinCostFlow(int\
    \ n) : graph(n), dist(n), pot(n), rev(n) {}\n\n    void span(int u, int v, Cap\
    \ cap, Cost cost) {\n        graph[u].push_back(edges.size());\n        edges.emplace_back(u,\
    \ v, cap, cost);\n\n        graph[v].push_back(edges.size());\n        edges.emplace_back(v,\
    \ u, 0, -cost);\n    }\n\n    void dijkstra(int s) {\n        std::fill(dist.begin(),\
    \ dist.end(), INF);\n        dist[s] = 0;\n        MinHeap<std::pair<Cost, int>>\
    \ heap;\n        heap.emplace(0, s);\n\n        while (!heap.empty()) {\n    \
    \        auto [d, u] = heap.top();\n            heap.pop();\n            if (d\
    \ > dist[u]) continue;\n\n            for (auto eidx : graph[u]) {\n         \
    \       const auto& edge = edges[eidx];\n                auto v = edge.dst;\n\n\
    \                if (edge.cap > 0 && dist[u] < INF &&\n                    dist[v]\
    \ > dist[u] + edge.cost + pot[u] - pot[v]) {\n                    dist[v] = dist[u]\
    \ + edge.cost + pot[u] - pot[v];\n                    rev[v] = eidx;\n       \
    \             heap.emplace(dist[v], v);\n                }\n            }\n  \
    \      }\n    }\n\n    std::pair<Cap, Cost> flow(int s, int g, Cap flow_limit)\
    \ {\n        Cap fsum = 0;\n        Cost csum = 0;\n        std::fill(pot.begin(),\
    \ pot.end(), 0);\n\n        while (flow_limit > 0) {\n            dijkstra(s);\n\
    \            if (dist[g] == INF) break;\n\n            for (int v = 0; v < (int)graph.size();\
    \ ++v) {\n                pot[v] = std::min(pot[v] + dist[v], INF);\n        \
    \    }\n\n            Cap f = flow_limit;\n            int v = g;\n          \
    \  while (v != s) {\n                const auto& edge = edges[rev[v]];\n     \
    \           f = std::min(f, edge.cap);\n                v = edge.src;\n      \
    \      }\n\n            flow_limit -= f;\n            fsum += f;\n           \
    \ csum += f * pot[g];\n\n            v = g;\n            while (v != s) {\n  \
    \              auto& edge = edges[rev[v]];\n                auto& redge = edges[rev[v]\
    \ ^ 1];\n                edge.cap -= f;\n                redge.cap += f;\n   \
    \             v = edge.src;\n            }\n        }\n        return {fsum, csum};\n\
    \    }\n\n    std::pair<Cap, Cost> flow(int s, int g) {\n        return flow(s,\
    \ g, std::numeric_limits<Cap>::max());\n    }\n};\n"
  dependsOn:
  - Tools/heap_alias.hpp
  isVerificationFile: false
  path: Graph/primal_dual.hpp
  requiredBy: []
  timestamp: '2020-11-03 10:48:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/primal_dual.test.cpp
documentation_of: Graph/primal_dual.hpp
layout: document
redirect_from:
- /library/Graph/primal_dual.hpp
- /library/Graph/primal_dual.hpp.html
title: Graph/primal_dual.hpp
---
