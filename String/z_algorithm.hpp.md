---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/z_algorithm.test.cpp
    title: Verify/z_algorithm.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"String/z_algorithm.hpp\"\n\n#include <vector>\n\ntemplate\
    \ <class Container>\nstd::vector<int> zalgo(const Container& dat) {\n    int n\
    \ = dat.size();\n\n    std::vector<int> ret(n);\n    ret[0] = n;\n\n    int i\
    \ = 1, len = 0;\n    while (i < n) {\n        while (i + len < n && dat[len] ==\
    \ dat[i + len]) {\n            ++len;\n        }\n        ret[i] = len;\n\n  \
    \      if (len == 0) {\n            ++i;\n            continue;\n        }\n\n\
    \        int nlen = 1;\n        while (i + nlen < n && nlen + ret[nlen] < len)\
    \ {\n            ret[i + nlen] = ret[nlen];\n            ++nlen;\n        }\n\n\
    \        i += nlen;\n        len -= nlen;\n    }\n\n    return ret;\n}\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate <class Container>\nstd::vector<int>\
    \ zalgo(const Container& dat) {\n    int n = dat.size();\n\n    std::vector<int>\
    \ ret(n);\n    ret[0] = n;\n\n    int i = 1, len = 0;\n    while (i < n) {\n \
    \       while (i + len < n && dat[len] == dat[i + len]) {\n            ++len;\n\
    \        }\n        ret[i] = len;\n\n        if (len == 0) {\n            ++i;\n\
    \            continue;\n        }\n\n        int nlen = 1;\n        while (i +\
    \ nlen < n && nlen + ret[nlen] < len) {\n            ret[i + nlen] = ret[nlen];\n\
    \            ++nlen;\n        }\n\n        i += nlen;\n        len -= nlen;\n\
    \    }\n\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: String/z_algorithm.hpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/z_algorithm.test.cpp
documentation_of: String/z_algorithm.hpp
layout: document
redirect_from:
- /library/String/z_algorithm.hpp
- /library/String/z_algorithm.hpp.html
title: String/z_algorithm.hpp
---
