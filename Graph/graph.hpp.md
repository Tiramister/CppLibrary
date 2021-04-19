---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: Graph/bfs.hpp
    title: Graph/bfs.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/centroid_decomposition.hpp
    title: Graph/centroid_decomposition.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/dijkstra.hpp
    title: Graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/heavy_light_decomposition.hpp
    title: Graph/heavy_light_decomposition.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/level_ancestor.hpp
    title: Graph/level_ancestor.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/lowlink.hpp
    title: Graph/lowlink.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/strongly_connected_component.hpp
    title: Graph/strongly_connected_component.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/topological_sort.hpp
    title: Graph/topological_sort.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/two_sat.hpp
    title: Graph/two_sat.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/articulation_points.test.cpp
    title: Verify/articulation_points.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/bridges.test.cpp
    title: Verify/bridges.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/centroid_decomposition_diameter.test.cpp
    title: Verify/centroid_decomposition_diameter.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/dijkstra.test.cpp
    title: Verify/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/hld_lca.test.cpp
    title: Verify/hld_lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/hld_path.test.cpp
    title: Verify/hld_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/hld_subtree.test.cpp
    title: Verify/hld_subtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/level_ancestor.test.cpp
    title: Verify/level_ancestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/strongly_connected_component.test.cpp
    title: Verify/strongly_connected_component.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/topological_sort.test.cpp
    title: Verify/topological_sort.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/two_sat.test.cpp
    title: Verify/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/graph.hpp\"\n\n#include <vector>\n\ntemplate <class\
    \ Cost = int>\nstruct Edge {\n    int src, dst;\n    Cost cost;\n\n    Edge()\
    \ = default;\n    Edge(int src, int dst, Cost cost = 1)\n        : src(src), dst(dst),\
    \ cost(cost){};\n\n    bool operator<(const Edge<Cost>& e) const { return cost\
    \ < e.cost; }\n    bool operator>(const Edge<Cost>& e) const { return cost > e.cost;\
    \ }\n};\n\ntemplate <class Cost = int>\nstruct Graph : public std::vector<std::vector<Edge<Cost>>>\
    \ {\n    using std::vector<std::vector<Edge<Cost>>>::vector;\n\n    void span(bool\
    \ direct, int src, int dst, Cost cost = 1) {\n        (*this)[src].emplace_back(src,\
    \ dst, cost);\n        if (!direct) (*this)[dst].emplace_back(dst, src, cost);\n\
    \    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate <class Cost = int>\nstruct\
    \ Edge {\n    int src, dst;\n    Cost cost;\n\n    Edge() = default;\n    Edge(int\
    \ src, int dst, Cost cost = 1)\n        : src(src), dst(dst), cost(cost){};\n\n\
    \    bool operator<(const Edge<Cost>& e) const { return cost < e.cost; }\n   \
    \ bool operator>(const Edge<Cost>& e) const { return cost > e.cost; }\n};\n\n\
    template <class Cost = int>\nstruct Graph : public std::vector<std::vector<Edge<Cost>>>\
    \ {\n    using std::vector<std::vector<Edge<Cost>>>::vector;\n\n    void span(bool\
    \ direct, int src, int dst, Cost cost = 1) {\n        (*this)[src].emplace_back(src,\
    \ dst, cost);\n        if (!direct) (*this)[dst].emplace_back(dst, src, cost);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/graph.hpp
  requiredBy:
  - Graph/strongly_connected_component.hpp
  - Graph/two_sat.hpp
  - Graph/centroid_decomposition.hpp
  - Graph/lowlink.hpp
  - Graph/dijkstra.hpp
  - Graph/bfs.hpp
  - Graph/topological_sort.hpp
  - Graph/heavy_light_decomposition.hpp
  - Graph/level_ancestor.hpp
  timestamp: '2020-11-05 12:15:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/level_ancestor.test.cpp
  - Verify/hld_lca.test.cpp
  - Verify/two_sat.test.cpp
  - Verify/articulation_points.test.cpp
  - Verify/centroid_decomposition_diameter.test.cpp
  - Verify/topological_sort.test.cpp
  - Verify/hld_subtree.test.cpp
  - Verify/strongly_connected_component.test.cpp
  - Verify/dijkstra.test.cpp
  - Verify/hld_path.test.cpp
  - Verify/bridges.test.cpp
documentation_of: Graph/graph.hpp
layout: document
redirect_from:
- /library/Graph/graph.hpp
- /library/Graph/graph.hpp.html
title: Graph/graph.hpp
---
