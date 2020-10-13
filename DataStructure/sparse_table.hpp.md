---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/sparse_table_rmq.test.cpp
    title: Verify/sparse_table_rmq.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/sparse_table.hpp\"\n\n#include <vector>\n\
    #include <functional>\n\ntemplate <class T>\nstruct SparseTable {\n    using Merger\
    \ = std::function<T(T, T)>;\n\n    int length;\n    std::vector<std::vector<T>>\
    \ table;\n    Merger merge;\n    std::vector<int> logs;\n\n    SparseTable(const\
    \ std::vector<T>& dat, const Merger& merge)\n        : length(dat.size()), table{dat},\
    \ merge(merge), logs(length + 1) {\n        int kmax = 0;\n        for (int d\
    \ = 0; d <= length; ++d) {\n            if (d >= (1 << (kmax + 1))) ++kmax;\n\
    \            logs[d] = kmax;\n        }\n\n        table.resize(kmax + 1);\n \
    \       for (int k = 1; k <= kmax; ++k) {\n            table[k].resize(length\
    \ - (1 << k) + 1);\n            for (int i = 0; i + (1 << k) <= length; ++i) {\n\
    \                table[k][i] = merge(table[k - 1][i],\n                      \
    \              table[k - 1][i + (1 << (k - 1))]);\n            }\n        }\n\
    \    }\n\n    T fold(int l, int r) {\n        l = std::max(l, 0);\n        r =\
    \ std::min(r, length);\n\n        int k = logs[r - l];\n        return merge(table[k][l],\
    \ table[k][r - (1 << k)]);\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <functional>\n\ntemplate <class\
    \ T>\nstruct SparseTable {\n    using Merger = std::function<T(T, T)>;\n\n   \
    \ int length;\n    std::vector<std::vector<T>> table;\n    Merger merge;\n   \
    \ std::vector<int> logs;\n\n    SparseTable(const std::vector<T>& dat, const Merger&\
    \ merge)\n        : length(dat.size()), table{dat}, merge(merge), logs(length\
    \ + 1) {\n        int kmax = 0;\n        for (int d = 0; d <= length; ++d) {\n\
    \            if (d >= (1 << (kmax + 1))) ++kmax;\n            logs[d] = kmax;\n\
    \        }\n\n        table.resize(kmax + 1);\n        for (int k = 1; k <= kmax;\
    \ ++k) {\n            table[k].resize(length - (1 << k) + 1);\n            for\
    \ (int i = 0; i + (1 << k) <= length; ++i) {\n                table[k][i] = merge(table[k\
    \ - 1][i],\n                                    table[k - 1][i + (1 << (k - 1))]);\n\
    \            }\n        }\n    }\n\n    T fold(int l, int r) {\n        l = std::max(l,\
    \ 0);\n        r = std::min(r, length);\n\n        int k = logs[r - l];\n    \
    \    return merge(table[k][l], table[k][r - (1 << k)]);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/sparse_table.hpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/sparse_table_rmq.test.cpp
documentation_of: DataStructure/sparse_table.hpp
layout: document
redirect_from:
- /library/DataStructure/sparse_table.hpp
- /library/DataStructure/sparse_table.hpp.html
title: DataStructure/sparse_table.hpp
---
