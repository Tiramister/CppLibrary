---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/gcd.test.cpp
    title: Verify/gcd.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Number/gcd.hpp\"\n\n#include <algorithm>\n\ntemplate <class\
    \ T>\nT gcd(T n, T m) {\n    while (m != 0) {\n        n %= m;\n        std::swap(n,\
    \ m);\n    }\n    return n;\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n\ntemplate <class T>\nT gcd(T n, T\
    \ m) {\n    while (m != 0) {\n        n %= m;\n        std::swap(n, m);\n    }\n\
    \    return n;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Number/gcd.hpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/gcd.test.cpp
documentation_of: Number/gcd.hpp
layout: document
redirect_from:
- /library/Number/gcd.hpp
- /library/Number/gcd.hpp.html
title: Number/gcd.hpp
---
