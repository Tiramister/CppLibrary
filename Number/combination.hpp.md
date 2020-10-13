---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/combination.test.cpp
    title: Verify/combination.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Number/combination.hpp\"\n\n#include <vector>\n\ntemplate\
    \ <class T>\nstruct Combination {\n    int max_n;\n    std::vector<T> f, invf;\n\
    \n    explicit Combination(int n)\n        : max_n(n), f(n + 1), invf(n + 1) {\n\
    \        f[0] = 1;\n        for (int i = 1; i <= n; ++i) {\n            f[i] =\
    \ f[i - 1] * i;\n        }\n\n        invf[max_n] = f[max_n].inv();\n        for\
    \ (int i = max_n - 1; i >= 0; --i) {\n            invf[i] = invf[i + 1] * (i +\
    \ 1);\n        }\n    }\n\n    T fact(int n) const { return n < 0 ? T(0) : f[n];\
    \ }\n    T invfact(int n) const { return n < 0 ? T(0) : invf[n]; }\n    T perm(int\
    \ a, int b) const {\n        return a < b || b < 0 ? T(0) : f[a] * invf[a - b];\n\
    \    }\n    T binom(int a, int b) const {\n        return a < b || b < 0 ? T(0)\
    \ : f[a] * invf[a - b] * invf[b];\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate <class T>\nstruct Combination\
    \ {\n    int max_n;\n    std::vector<T> f, invf;\n\n    explicit Combination(int\
    \ n)\n        : max_n(n), f(n + 1), invf(n + 1) {\n        f[0] = 1;\n       \
    \ for (int i = 1; i <= n; ++i) {\n            f[i] = f[i - 1] * i;\n        }\n\
    \n        invf[max_n] = f[max_n].inv();\n        for (int i = max_n - 1; i >=\
    \ 0; --i) {\n            invf[i] = invf[i + 1] * (i + 1);\n        }\n    }\n\n\
    \    T fact(int n) const { return n < 0 ? T(0) : f[n]; }\n    T invfact(int n)\
    \ const { return n < 0 ? T(0) : invf[n]; }\n    T perm(int a, int b) const {\n\
    \        return a < b || b < 0 ? T(0) : f[a] * invf[a - b];\n    }\n    T binom(int\
    \ a, int b) const {\n        return a < b || b < 0 ? T(0) : f[a] * invf[a - b]\
    \ * invf[b];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Number/combination.hpp
  requiredBy: []
  timestamp: '2020-08-01 08:36:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/combination.test.cpp
documentation_of: Number/combination.hpp
layout: document
redirect_from:
- /library/Number/combination.hpp
- /library/Number/combination.hpp.html
title: Number/combination.hpp
---
