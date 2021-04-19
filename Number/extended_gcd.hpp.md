---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/extended_gcd.test.cpp
    title: Verify/extended_gcd.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Number/extended_gcd.hpp\"\n\n#include <algorithm>\n\ntemplate\
    \ <typename T>\nT extgcd(T a, T b, T& x, T& y) {\n    T s = a, t = b,\n      xs\
    \ = 1, ys = 0,\n      xt = 0, yt = 1;\n\n    while (t != 0) {\n        T div =\
    \ s / t;\n\n        s -= t * div;\n        xs -= xt * div;\n        ys -= yt *\
    \ div;\n\n        std::swap(s, t);\n        std::swap(xs, xt);\n        std::swap(ys,\
    \ yt);\n    }\n\n    x = xs;\n    y = ys;\n    return s;\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n\ntemplate <typename T>\nT extgcd(T\
    \ a, T b, T& x, T& y) {\n    T s = a, t = b,\n      xs = 1, ys = 0,\n      xt\
    \ = 0, yt = 1;\n\n    while (t != 0) {\n        T div = s / t;\n\n        s -=\
    \ t * div;\n        xs -= xt * div;\n        ys -= yt * div;\n\n        std::swap(s,\
    \ t);\n        std::swap(xs, xt);\n        std::swap(ys, yt);\n    }\n\n    x\
    \ = xs;\n    y = ys;\n    return s;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Number/extended_gcd.hpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/extended_gcd.test.cpp
documentation_of: Number/extended_gcd.hpp
layout: document
redirect_from:
- /library/Number/extended_gcd.hpp
- /library/Number/extended_gcd.hpp.html
title: Number/extended_gcd.hpp
---
