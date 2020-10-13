---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/dijkstra.hpp
    title: Graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: Tools/heap_alias.hpp
    title: Tools/heap_alias.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"Verify/dijkstra.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#line 2 \"Graph/dijkstra.hpp\"\n\n#line 2 \"Tools/heap_alias.hpp\"\n\n#include\
    \ <queue>\n\ntemplate <class T>\nusing MaxHeap = std::priority_queue<T>;\ntemplate\
    \ <class T>\nusing MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;\n\
    #line 2 \"Graph/graph.hpp\"\n\n#include <vector>\n\ntemplate <class Cost = int>\n\
    struct Edge {\n    int src, dst;\n    Cost cost;\n\n    Edge() = default;\n  \
    \  Edge(int src, int dst, Cost cost = 1)\n        : src(src), dst(dst), cost(cost){};\n\
    \n    bool operator<(const Edge<Cost>& e) const { return cost < e.cost; }\n  \
    \  bool operator>(const Edge<Cost>& e) const { return cost > e.cost; }\n};\n\n\
    template <class Cost = int>\nstruct Graph : public std::vector<std::vector<Edge<Cost>>>\
    \ {\n    Graph(int n = 0) : std::vector<std::vector<Edge<Cost>>>(n) {}\n\n   \
    \ void span(bool direct, int src, int dst, Cost cost = 1) {\n        (*this)[src].emplace_back(src,\
    \ dst, cost);\n        if (!direct) (*this)[dst].emplace_back(dst, src, cost);\n\
    \    }\n};\n#line 5 \"Graph/dijkstra.hpp\"\n\n#include <tuple>\n\ntemplate <class\
    \ Cost>\nstd::vector<Cost> dijkstra(const Graph<Cost>& graph, int s) {\n    std::vector<Cost>\
    \ dist(graph.size(), -1);\n    dist[s] = 0;\n    MinHeap<std::pair<Cost, int>>\
    \ que;\n    que.emplace(0, s);\n\n    while (!que.empty()) {\n        int v;\n\
    \        Cost d;\n        std::tie(d, v) = que.top();\n        que.pop();\n  \
    \      if (d > dist[v]) continue;\n\n        for (const auto& e : graph[v]) {\n\
    \            if (dist[e.dst] != -1 &&\n                dist[e.dst] <= dist[v]\
    \ + e.cost) continue;\n            dist[e.dst] = dist[v] + e.cost;\n         \
    \   que.emplace(dist[e.dst], e.dst);\n        }\n    }\n\n    return dist;\n}\n\
    #line 4 \"Verify/dijkstra.test.cpp\"\n\n#include <iostream>\n\nint main() {\n\
    \    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n    int n, m, s;\n\
    \    std::cin >> n >> m >> s;\n\n    Graph<int> graph(n);\n    while (m--) {\n\
    \        int u, v, d;\n        std::cin >> u >> v >> d;\n        graph.span(true,\
    \ u, v, d);\n    }\n\n    auto dist = dijkstra(graph, s);\n    for (auto d : dist)\
    \ {\n        if (d == -1) {\n            std::cout << \"INF\";\n        } else\
    \ {\n            std::cout << d;\n        }\n        std::cout << \"\\n\";\n \
    \   }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include \"../Graph/dijkstra.hpp\"\n\n#include <iostream>\n\nint main() {\n\
    \    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n    int n, m, s;\n\
    \    std::cin >> n >> m >> s;\n\n    Graph<int> graph(n);\n    while (m--) {\n\
    \        int u, v, d;\n        std::cin >> u >> v >> d;\n        graph.span(true,\
    \ u, v, d);\n    }\n\n    auto dist = dijkstra(graph, s);\n    for (auto d : dist)\
    \ {\n        if (d == -1) {\n            std::cout << \"INF\";\n        } else\
    \ {\n            std::cout << d;\n        }\n        std::cout << \"\\n\";\n \
    \   }\n\n    return 0;\n}\n"
  dependsOn:
  - Graph/dijkstra.hpp
  - Tools/heap_alias.hpp
  - Graph/graph.hpp
  isVerificationFile: true
  path: Verify/dijkstra.test.cpp
  requiredBy: []
  timestamp: '2020-10-13 21:34:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/dijkstra.test.cpp
layout: document
redirect_from:
- /verify/Verify/dijkstra.test.cpp
- /verify/Verify/dijkstra.test.cpp.html
title: Verify/dijkstra.test.cpp
---
