---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/sliding_window.hpp
    title: DataStructure/sliding_window.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D
  bundledCode: "#line 1 \"Verify/sliding_window.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D\"\
    \n\n#line 2 \"DataStructure/sliding_window.hpp\"\n\n#include <deque>\n#include\
    \ <functional>\n\ntemplate <class T>\nstruct SlidingWindow {\n    using Cmp =\
    \ std::function<bool(T, T)>;\n\n    std::deque<std::pair<T, int>> window;\n  \
    \  Cmp cmp;\n    int l, r;\n\n    explicit SlidingWindow(Cmp cmp)\n        : window(),\
    \ cmp(cmp), l(0), r(0) {}\n\n    void push(T val) {\n        while (!window.empty()\
    \ && cmp(val, window.back().first)) {\n            window.pop_back();\n      \
    \  }\n        window.emplace_back(val, r++);\n    }\n\n    T get() {\n       \
    \ return window.front().first;\n    }\n\n    void pop() {\n        if (window.front().second\
    \ == l++) {\n            window.pop_front();\n        }\n    }\n};\n#line 4 \"\
    Verify/sliding_window.test.cpp\"\n\n#include <iostream>\n\nint main() {\n    std::cin.tie();\n\
    \    std::ios::sync_with_stdio(false);\n\n    int n, l;\n    std::cin >> n >>\
    \ l;\n\n    SlidingWindow<int> sw([](int lhs, int rhs) { return lhs <= rhs; });\n\
    \n    for (int i = 0; i < n; ++i) {\n        int a;\n        std::cin >> a;\n\
    \        sw.push(a);\n\n        if (i >= l - 1) {\n            std::cout << sw.get()\
    \ << \" \\n\"[i == n - 1];\n            sw.pop();\n        }\n    }\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D\"\
    \n\n#include \"../DataStructure/sliding_window.hpp\"\n\n#include <iostream>\n\n\
    int main() {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n \
    \   int n, l;\n    std::cin >> n >> l;\n\n    SlidingWindow<int> sw([](int lhs,\
    \ int rhs) { return lhs <= rhs; });\n\n    for (int i = 0; i < n; ++i) {\n   \
    \     int a;\n        std::cin >> a;\n        sw.push(a);\n\n        if (i >=\
    \ l - 1) {\n            std::cout << sw.get() << \" \\n\"[i == n - 1];\n     \
    \       sw.pop();\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/sliding_window.hpp
  isVerificationFile: true
  path: Verify/sliding_window.test.cpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/sliding_window.test.cpp
layout: document
redirect_from:
- /verify/Verify/sliding_window.test.cpp
- /verify/Verify/sliding_window.test.cpp.html
title: Verify/sliding_window.test.cpp
---
