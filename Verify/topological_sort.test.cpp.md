---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/topological_sort.hpp
    title: Graph/topological_sort.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B
  bundledCode: "#line 1 \"Verify/topological_sort.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B\"\
    \n\n#line 2 \"Graph/topological_sort.hpp\"\n\n#line 2 \"Graph/graph.hpp\"\n\n\
    #include <vector>\n\ntemplate <class Cost = int>\nstruct Edge {\n    int src,\
    \ dst;\n    Cost cost;\n\n    Edge() = default;\n    Edge(int src, int dst, Cost\
    \ cost = 1)\n        : src(src), dst(dst), cost(cost){};\n\n    bool operator<(const\
    \ Edge<Cost>& e) const { return cost < e.cost; }\n    bool operator>(const Edge<Cost>&\
    \ e) const { return cost > e.cost; }\n};\n\ntemplate <class Cost = int>\nstruct\
    \ Graph : public std::vector<std::vector<Edge<Cost>>> {\n    using std::vector<std::vector<Edge<Cost>>>::vector;\n\
    \n    void span(bool direct, int src, int dst, Cost cost = 1) {\n        (*this)[src].emplace_back(src,\
    \ dst, cost);\n        if (!direct) (*this)[dst].emplace_back(dst, src, cost);\n\
    \    }\n};\n#line 4 \"Graph/topological_sort.hpp\"\n\n#include <algorithm>\n\n\
    template <class Cost = int>\nstruct TopologicalSort {\n    Graph<Cost> graph;\n\
    \    std::vector<bool> visited;\n    std::vector<int> vs, id;\n\n    explicit\
    \ TopologicalSort(const Graph<Cost>& graph)\n        : graph(graph), visited(graph.size(),\
    \ false), id(graph.size()) {\n        for (int v = 0; v < (int)graph.size(); ++v)\
    \ dfs(v);\n        std::reverse(vs.begin(), vs.end());\n\n        for (int i =\
    \ 0; i < (int)graph.size(); ++i) id[vs[i]] = i;\n    }\n\n    void dfs(int v)\
    \ {\n        if (visited[v]) return;\n        visited[v] = true;\n        for\
    \ (const auto& e : graph[v]) dfs(e.dst);\n        vs.push_back(v);\n    }\n};\n\
    #line 4 \"Verify/topological_sort.test.cpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n    int n,\
    \ m;\n    std::cin >> n >> m;\n\n    Graph<> graph(n);\n    while (m--) {\n  \
    \      int u, v;\n        std::cin >> u >> v;\n        graph.span(true, u, v);\n\
    \    }\n\n    TopologicalSort<> ts(graph);\n    for (int v : ts.vs) std::cout\
    \ << v << \"\\n\";\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B\"\
    \n\n#include \"../Graph/topological_sort.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n    int n,\
    \ m;\n    std::cin >> n >> m;\n\n    Graph<> graph(n);\n    while (m--) {\n  \
    \      int u, v;\n        std::cin >> u >> v;\n        graph.span(true, u, v);\n\
    \    }\n\n    TopologicalSort<> ts(graph);\n    for (int v : ts.vs) std::cout\
    \ << v << \"\\n\";\n\n    return 0;\n}\n"
  dependsOn:
  - Graph/topological_sort.hpp
  - Graph/graph.hpp
  isVerificationFile: true
  path: Verify/topological_sort.test.cpp
  requiredBy: []
  timestamp: '2020-11-05 12:15:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/topological_sort.test.cpp
layout: document
redirect_from:
- /verify/Verify/topological_sort.test.cpp
- /verify/Verify/topological_sort.test.cpp.html
title: Verify/topological_sort.test.cpp
---
