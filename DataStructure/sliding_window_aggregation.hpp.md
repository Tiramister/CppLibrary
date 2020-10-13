---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/sliding_window_aggregation.hpp\"\n\n#include\
    \ <stack>\n\ntemplate <class M>\nstruct SlidingWindowAggregation {\n    using\
    \ T = typename M::T;\n\n    std::stack<std::pair<T, T>> front, back;\n\n    explicit\
    \ SlidingWindowAggregation() = default;\n\n    void push(const T& x) {\n     \
    \   T acc = M::op(back.empty() ? M::id : back.top().second, x);\n        back.emplace(x,\
    \ acc);\n    }\n\n    void pop() {\n        if (front.empty()) {\n           \
    \ T acc = M::id;\n            while (!back.empty()) {\n                acc = M::op(back.top().first,\
    \ acc);\n                front.emplace(back.top().first, acc);\n             \
    \   back.pop();\n            }\n        }\n        front.pop();\n    }\n\n   \
    \ T fold() {\n        return M::op((front.empty() ? M::id : front.top().second),\n\
    \                     (back.empty() ? M::id : back.top().second));\n    }\n};\n"
  code: "#pragma once\n\n#include <stack>\n\ntemplate <class M>\nstruct SlidingWindowAggregation\
    \ {\n    using T = typename M::T;\n\n    std::stack<std::pair<T, T>> front, back;\n\
    \n    explicit SlidingWindowAggregation() = default;\n\n    void push(const T&\
    \ x) {\n        T acc = M::op(back.empty() ? M::id : back.top().second, x);\n\
    \        back.emplace(x, acc);\n    }\n\n    void pop() {\n        if (front.empty())\
    \ {\n            T acc = M::id;\n            while (!back.empty()) {\n       \
    \         acc = M::op(back.top().first, acc);\n                front.emplace(back.top().first,\
    \ acc);\n                back.pop();\n            }\n        }\n        front.pop();\n\
    \    }\n\n    T fold() {\n        return M::op((front.empty() ? M::id : front.top().second),\n\
    \                     (back.empty() ? M::id : back.top().second));\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/sliding_window_aggregation.hpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructure/sliding_window_aggregation.hpp
layout: document
redirect_from:
- /library/DataStructure/sliding_window_aggregation.hpp
- /library/DataStructure/sliding_window_aggregation.hpp.html
title: DataStructure/sliding_window_aggregation.hpp
---
