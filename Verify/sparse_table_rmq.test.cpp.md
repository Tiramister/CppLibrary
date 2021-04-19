---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/sparse_table.hpp
    title: DataStructure/sparse_table.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"Verify/sparse_table_rmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#line 2 \"DataStructure/sparse_table.hpp\"\n\n#include <vector>\n#include\
    \ <functional>\n\ntemplate <class T>\nstruct SparseTable {\n    using Merger =\
    \ std::function<T(T, T)>;\n\n    int length;\n    std::vector<std::vector<T>>\
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
    \ table[k][r - (1 << k)]);\n    }\n};\n#line 4 \"Verify/sparse_table_rmq.test.cpp\"\
    \n\n#include <iostream>\n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \n    int n, q;\n    std::cin >> n >> q;\n\n    std::vector<int> xs(n);\n    for\
    \ (auto& x : xs) std::cin >> x;\n\n    SparseTable<int> st(xs, [](auto a, auto\
    \ b) { return std::min(a, b); });\n\n    while (q--) {\n        int l, r;\n  \
    \      std::cin >> l >> r;\n        std::cout << st.fold(l, r) << \"\\n\";\n \
    \   }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../DataStructure/sparse_table.hpp\"\n\n#include <iostream>\n\nint main() {\n\
    \    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\n    int\
    \ n, q;\n    std::cin >> n >> q;\n\n    std::vector<int> xs(n);\n    for (auto&\
    \ x : xs) std::cin >> x;\n\n    SparseTable<int> st(xs, [](auto a, auto b) { return\
    \ std::min(a, b); });\n\n    while (q--) {\n        int l, r;\n        std::cin\
    \ >> l >> r;\n        std::cout << st.fold(l, r) << \"\\n\";\n    }\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - DataStructure/sparse_table.hpp
  isVerificationFile: true
  path: Verify/sparse_table_rmq.test.cpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/sparse_table_rmq.test.cpp
layout: document
redirect_from:
- /verify/Verify/sparse_table_rmq.test.cpp
- /verify/Verify/sparse_table_rmq.test.cpp.html
title: Verify/sparse_table_rmq.test.cpp
---
