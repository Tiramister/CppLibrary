---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Number/boolean_elimination.hpp\"\n\n#include <algorithm>\n\
    #include <vector>\n\ntemplate <class T>\nvoid bool_elimination(std::vector<std::vector<T>>&\
    \ mat) {\n    int n = mat.size(), m = mat.front().size();\n\n    for (int l =\
    \ 0; l < n; ++l) {\n        {\n            auto& v = *std::max_element(mat.begin()\
    \ + l, mat.end());\n            std::swap(v, mat[l]);\n        }\n\n        const\
    \ auto& v = mat[l];\n        for (int i = l + 1; i < n; ++i) {\n            auto\
    \ u = mat[i];\n            for (int j = 0; j < m; ++j) u[j] ^= v[j];\n       \
    \     if (u < mat[i]) std::swap(u, mat[i]);\n        }\n    }\n}\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <vector>\n\ntemplate <class\
    \ T>\nvoid bool_elimination(std::vector<std::vector<T>>& mat) {\n    int n = mat.size(),\
    \ m = mat.front().size();\n\n    for (int l = 0; l < n; ++l) {\n        {\n  \
    \          auto& v = *std::max_element(mat.begin() + l, mat.end());\n        \
    \    std::swap(v, mat[l]);\n        }\n\n        const auto& v = mat[l];\n   \
    \     for (int i = l + 1; i < n; ++i) {\n            auto u = mat[i];\n      \
    \      for (int j = 0; j < m; ++j) u[j] ^= v[j];\n            if (u < mat[i])\
    \ std::swap(u, mat[i]);\n        }\n    }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Number/boolean_elimination.hpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Number/boolean_elimination.hpp
layout: document
redirect_from:
- /library/Number/boolean_elimination.hpp
- /library/Number/boolean_elimination.hpp.html
title: Number/boolean_elimination.hpp
---
