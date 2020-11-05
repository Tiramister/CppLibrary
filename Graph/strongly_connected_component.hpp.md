---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/two_sat.hpp
    title: Graph/two_sat.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/strongly_connected_component.test.cpp
    title: Verify/strongly_connected_component.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/two_sat.test.cpp
    title: Verify/two_sat.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/strongly_connected_component.hpp\"\n\n#line 2 \"Graph/graph.hpp\"\
    \n\n#include <vector>\n\ntemplate <class Cost = int>\nstruct Edge {\n    int src,\
    \ dst;\n    Cost cost;\n\n    Edge() = default;\n    Edge(int src, int dst, Cost\
    \ cost = 1)\n        : src(src), dst(dst), cost(cost){};\n\n    bool operator<(const\
    \ Edge<Cost>& e) const { return cost < e.cost; }\n    bool operator>(const Edge<Cost>&\
    \ e) const { return cost > e.cost; }\n};\n\ntemplate <class Cost = int>\nstruct\
    \ Graph : public std::vector<std::vector<Edge<Cost>>> {\n    using std::vector<std::vector<Edge<Cost>>>::vector;\n\
    \n    void span(bool direct, int src, int dst, Cost cost = 1) {\n        (*this)[src].emplace_back(src,\
    \ dst, cost);\n        if (!direct) (*this)[dst].emplace_back(dst, src, cost);\n\
    \    }\n};\n#line 4 \"Graph/strongly_connected_component.hpp\"\n\n#line 6 \"Graph/strongly_connected_component.hpp\"\
    \n\ntemplate <class Cost = int>\nstruct StronglyConnectedComponents {\n    Graph<Cost>\
    \ graph, rgraph;\n    std::vector<bool> visited;\n    std::vector<int> stk;\n\n\
    \    // id[v] = \u9802\u70B9v\u306Fgroups[id[v]]\u306B\u5C5E\u3059\u308B\n   \
    \ std::vector<int> id;\n    std::vector<std::vector<int>> groups;\n\n    explicit\
    \ StronglyConnectedComponents(const Graph<Cost>& g)\n        : graph(g), visited(graph.size(),\
    \ false), id(graph.size(), -1) {\n        revinit();\n\n        for (int v = 0;\
    \ v < (int)graph.size(); ++v) dfs(v);\n\n        while (!stk.empty()) {\n    \
    \        int v = stk.back();\n            stk.pop_back();\n            if (id[v]\
    \ < 0) {\n                groups.emplace_back();\n                rdfs(v);\n \
    \           }\n        }\n    }\n\n    void revinit() {\n        rgraph = Graph<Cost>(graph.size());\n\
    \        for (int v = 0; v < (int)graph.size(); ++v) {\n            for (const\
    \ auto& e : graph[v]) {\n                rgraph[e.dst].emplace_back(e.dst, v,\
    \ e.cost);\n            }\n        }\n    }\n\n    void dfs(int v) {\n       \
    \ if (visited[v]) return;\n        visited[v] = true;\n        for (const auto&\
    \ e : graph[v]) dfs(e.dst);\n        stk.push_back(v);\n    }\n\n    void rdfs(int\
    \ v) {\n        if (id[v] >= 0) return;\n        id[v] = groups.size() - 1;\n\
    \        groups.back().push_back(v);\n        for (const auto& e : rgraph[v])\
    \ rdfs(e.dst);\n    }\n};\n"
  code: "#pragma once\n\n#include \"graph.hpp\"\n\n#include <vector>\n\ntemplate <class\
    \ Cost = int>\nstruct StronglyConnectedComponents {\n    Graph<Cost> graph, rgraph;\n\
    \    std::vector<bool> visited;\n    std::vector<int> stk;\n\n    // id[v] = \u9802\
    \u70B9v\u306Fgroups[id[v]]\u306B\u5C5E\u3059\u308B\n    std::vector<int> id;\n\
    \    std::vector<std::vector<int>> groups;\n\n    explicit StronglyConnectedComponents(const\
    \ Graph<Cost>& g)\n        : graph(g), visited(graph.size(), false), id(graph.size(),\
    \ -1) {\n        revinit();\n\n        for (int v = 0; v < (int)graph.size();\
    \ ++v) dfs(v);\n\n        while (!stk.empty()) {\n            int v = stk.back();\n\
    \            stk.pop_back();\n            if (id[v] < 0) {\n                groups.emplace_back();\n\
    \                rdfs(v);\n            }\n        }\n    }\n\n    void revinit()\
    \ {\n        rgraph = Graph<Cost>(graph.size());\n        for (int v = 0; v <\
    \ (int)graph.size(); ++v) {\n            for (const auto& e : graph[v]) {\n  \
    \              rgraph[e.dst].emplace_back(e.dst, v, e.cost);\n            }\n\
    \        }\n    }\n\n    void dfs(int v) {\n        if (visited[v]) return;\n\
    \        visited[v] = true;\n        for (const auto& e : graph[v]) dfs(e.dst);\n\
    \        stk.push_back(v);\n    }\n\n    void rdfs(int v) {\n        if (id[v]\
    \ >= 0) return;\n        id[v] = groups.size() - 1;\n        groups.back().push_back(v);\n\
    \        for (const auto& e : rgraph[v]) rdfs(e.dst);\n    }\n};\n"
  dependsOn:
  - Graph/graph.hpp
  isVerificationFile: false
  path: Graph/strongly_connected_component.hpp
  requiredBy:
  - Graph/two_sat.hpp
  timestamp: '2020-11-05 12:15:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/two_sat.test.cpp
  - Verify/strongly_connected_component.test.cpp
documentation_of: Graph/strongly_connected_component.hpp
layout: document
redirect_from:
- /library/Graph/strongly_connected_component.hpp
- /library/Graph/strongly_connected_component.hpp.html
title: Graph/strongly_connected_component.hpp
---
