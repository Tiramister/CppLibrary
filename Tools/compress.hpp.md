---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Tools/compress.hpp\"\n\n#include <algorithm>\n#include <vector>\n\
    #include <map>\n\ntemplate <class T>\nstd::map<T, int> compress(std::vector<T>&\
    \ v) {\n    std::sort(v.begin(), v.end());\n    v.erase(std::unique(v.begin(),\
    \ v.end()), v.end());\n\n    std::map<T, int> rev;\n    for (int i = 0; i < (int)v.size();\
    \ ++i) rev[v[i]] = i;\n    return rev;\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n#include <map>\n\
    \ntemplate <class T>\nstd::map<T, int> compress(std::vector<T>& v) {\n    std::sort(v.begin(),\
    \ v.end());\n    v.erase(std::unique(v.begin(), v.end()), v.end());\n\n    std::map<T,\
    \ int> rev;\n    for (int i = 0; i < (int)v.size(); ++i) rev[v[i]] = i;\n    return\
    \ rev;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Tools/compress.hpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Tools/compress.hpp
layout: document
redirect_from:
- /library/Tools/compress.hpp
- /library/Tools/compress.hpp.html
title: Tools/compress.hpp
---
