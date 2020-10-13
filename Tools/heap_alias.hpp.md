---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Graph/dijkstra.hpp
    title: Graph/dijkstra.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/primal_dual.hpp
    title: Graph/primal_dual.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/dijkstra.test.cpp
    title: Verify/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/primal_dual.test.cpp
    title: Verify/primal_dual.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "Tools/heap_alias.hpp"


    #include <queue>


    template <class T>

    using MaxHeap = std::priority_queue<T>;

    template <class T>

    using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

    '
  code: '#pragma once


    #include <queue>


    template <class T>

    using MaxHeap = std::priority_queue<T>;

    template <class T>

    using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

    '
  dependsOn: []
  isVerificationFile: false
  path: Tools/heap_alias.hpp
  requiredBy:
  - Graph/dijkstra.hpp
  - Graph/primal_dual.hpp
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/dijkstra.test.cpp
  - Verify/primal_dual.test.cpp
documentation_of: Tools/heap_alias.hpp
layout: document
redirect_from:
- /library/Tools/heap_alias.hpp
- /library/Tools/heap_alias.hpp.html
title: Tools/heap_alias.hpp
---
