---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/sliding_window.test.cpp
    title: Verify/sliding_window.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/sliding_window.hpp\"\n\n#include <deque>\n\
    #include <functional>\n\ntemplate <class T>\nstruct SlidingWindow {\n    using\
    \ Cmp = std::function<bool(T, T)>;\n\n    std::deque<std::pair<T, int>> window;\n\
    \    Cmp cmp;\n    int l, r;\n\n    explicit SlidingWindow(Cmp cmp)\n        :\
    \ window(), cmp(cmp), l(0), r(0) {}\n\n    void push(T val) {\n        while (!window.empty()\
    \ && cmp(val, window.back().first)) {\n            window.pop_back();\n      \
    \  }\n        window.emplace_back(val, r++);\n    }\n\n    T get() {\n       \
    \ return window.front().first;\n    }\n\n    void pop() {\n        if (window.front().second\
    \ == l++) {\n            window.pop_front();\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include <deque>\n#include <functional>\n\ntemplate <class\
    \ T>\nstruct SlidingWindow {\n    using Cmp = std::function<bool(T, T)>;\n\n \
    \   std::deque<std::pair<T, int>> window;\n    Cmp cmp;\n    int l, r;\n\n   \
    \ explicit SlidingWindow(Cmp cmp)\n        : window(), cmp(cmp), l(0), r(0) {}\n\
    \n    void push(T val) {\n        while (!window.empty() && cmp(val, window.back().first))\
    \ {\n            window.pop_back();\n        }\n        window.emplace_back(val,\
    \ r++);\n    }\n\n    T get() {\n        return window.front().first;\n    }\n\
    \n    void pop() {\n        if (window.front().second == l++) {\n            window.pop_front();\n\
    \        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/sliding_window.hpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/sliding_window.test.cpp
documentation_of: DataStructure/sliding_window.hpp
layout: document
redirect_from:
- /library/DataStructure/sliding_window.hpp
- /library/DataStructure/sliding_window.hpp.html
title: DataStructure/sliding_window.hpp
---
