---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/suffix_array.test.cpp
    title: Verify/suffix_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"String/suffix_array.hpp\"\n\n#include <algorithm>\n#include\
    \ <numeric>\n#include <vector>\n\ntemplate <class T>\nstruct SuffixArray {\n \
    \   std::vector<int> ord, rank;\n\n    template <class It>\n    explicit SuffixArray(const\
    \ It& begin, const It& end) {\n        std::vector<T> dat(begin, end);\n     \
    \   int n = dat.size();\n\n        ord.resize(n);\n        std::iota(ord.begin(),\
    \ ord.end(), 0);\n        std::sort(ord.begin(), ord.end(),\n                \
    \  [&](int i, int j) { return dat[i] < dat[j]; });\n\n        rank.resize(n);\n\
    \        {\n            int cnt = 1;\n            rank[ord[0]] = 1;\n        \
    \    for (int i = 1; i < n; ++i) {\n                if (dat[ord[i - 1]] != dat[ord[i]])\
    \ ++cnt;\n                rank[ord[i]] = cnt;\n            }\n        }\n\n  \
    \      ord.insert(ord.begin(), n);\n        rank.push_back(0);\n\n        std::vector<int>\
    \ bucket(n + 1), nrank(n + 1), idxs(n + 1);\n\n        for (int k = 1; k < n;\
    \ k <<= 1) {\n            std::fill(bucket.begin(), bucket.end(), 0);\n\n    \
    \        for (int i = 0; i <= n; ++i) {\n                idxs[i] = (ord[i] - k\
    \ + n + 1) % (n + 1);\n                ++bucket[rank[idxs[i]]];\n            }\n\
    \n            for (int i = 1; i <= n; ++i) {\n                bucket[i] += bucket[i\
    \ - 1];\n            }\n            for (int i = n; i >= 0; --i) {\n         \
    \       ord[--bucket[rank[idxs[i]]]] = idxs[i];\n            }\n\n           \
    \ int cnt = 0;\n            for (int i = 0;; ++i) {\n                nrank[ord[i]]\
    \ = cnt;\n                if (i == n) break;\n\n                if (rank[ord[i]]\
    \ != rank[ord[i + 1]] ||\n                    rank[(ord[i] + k) % (n + 1)] !=\n\
    \                        rank[(ord[i + 1] + k) % (n + 1)]) ++cnt;\n          \
    \  }\n            std::swap(rank, nrank);\n        }\n    }\n};\n"
  code: "#pragma once\n\n#include <algorithm>\n#include <numeric>\n#include <vector>\n\
    \ntemplate <class T>\nstruct SuffixArray {\n    std::vector<int> ord, rank;\n\n\
    \    template <class It>\n    explicit SuffixArray(const It& begin, const It&\
    \ end) {\n        std::vector<T> dat(begin, end);\n        int n = dat.size();\n\
    \n        ord.resize(n);\n        std::iota(ord.begin(), ord.end(), 0);\n    \
    \    std::sort(ord.begin(), ord.end(),\n                  [&](int i, int j) {\
    \ return dat[i] < dat[j]; });\n\n        rank.resize(n);\n        {\n        \
    \    int cnt = 1;\n            rank[ord[0]] = 1;\n            for (int i = 1;\
    \ i < n; ++i) {\n                if (dat[ord[i - 1]] != dat[ord[i]]) ++cnt;\n\
    \                rank[ord[i]] = cnt;\n            }\n        }\n\n        ord.insert(ord.begin(),\
    \ n);\n        rank.push_back(0);\n\n        std::vector<int> bucket(n + 1), nrank(n\
    \ + 1), idxs(n + 1);\n\n        for (int k = 1; k < n; k <<= 1) {\n          \
    \  std::fill(bucket.begin(), bucket.end(), 0);\n\n            for (int i = 0;\
    \ i <= n; ++i) {\n                idxs[i] = (ord[i] - k + n + 1) % (n + 1);\n\
    \                ++bucket[rank[idxs[i]]];\n            }\n\n            for (int\
    \ i = 1; i <= n; ++i) {\n                bucket[i] += bucket[i - 1];\n       \
    \     }\n            for (int i = n; i >= 0; --i) {\n                ord[--bucket[rank[idxs[i]]]]\
    \ = idxs[i];\n            }\n\n            int cnt = 0;\n            for (int\
    \ i = 0;; ++i) {\n                nrank[ord[i]] = cnt;\n                if (i\
    \ == n) break;\n\n                if (rank[ord[i]] != rank[ord[i + 1]] ||\n  \
    \                  rank[(ord[i] + k) % (n + 1)] !=\n                        rank[(ord[i\
    \ + 1] + k) % (n + 1)]) ++cnt;\n            }\n            std::swap(rank, nrank);\n\
    \        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: String/suffix_array.hpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/suffix_array.test.cpp
documentation_of: String/suffix_array.hpp
layout: document
redirect_from:
- /library/String/suffix_array.hpp
- /library/String/suffix_array.hpp.html
title: String/suffix_array.hpp
---
