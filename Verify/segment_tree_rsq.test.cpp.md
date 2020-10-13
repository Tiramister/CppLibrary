---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segment_tree.hpp
    title: DataStructure/segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"Verify/segment_tree_rsq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n\n#line 2 \"DataStructure/segment_tree.hpp\"\n\n#include <vector>\n#include\
    \ <functional>\n\ntemplate <class T>\nstruct SegmentTree {\n    using Merger =\
    \ std::function<T(T, T)>;\n\n    int length;\n    std::vector<T> dat;\n    T unit;\n\
    \    Merger merge;\n\n    SegmentTree() = default;\n\n    SegmentTree(int n, const\
    \ T& unit, const Merger& merge)\n        : length(1), unit(unit), merge(merge)\
    \ {\n        while (length < n) length <<= 1;\n        dat.assign(length * 2,\
    \ unit);\n    }\n\n    template <class Container>\n    SegmentTree(const Container&\
    \ elems, const T& unit, const Merger& merge)\n        : length(1), unit(unit),\
    \ merge(merge) {\n        int n = elems.size();\n        while (length < n) length\
    \ <<= 1;\n\n        dat.assign(length * 2, unit);\n\n        std::copy(elems.begin(),\
    \ elems.end(), dat.begin() + length);\n\n        for (int nidx = length - 1; nidx\
    \ >= 1; --nidx) {\n            T vl = dat[nidx * 2 + 0];\n            T vr = dat[nidx\
    \ * 2 + 1];\n            dat[nidx] = merge(vl, vr);\n        }\n    }\n\n    void\
    \ update(int nidx, const T& elem) {\n        nidx += length;\n        dat[nidx]\
    \ = elem;\n\n        while (nidx > 0) {\n            nidx >>= 1;\n           \
    \ T vl = dat[nidx * 2 + 0];\n            T vr = dat[nidx * 2 + 1];\n         \
    \   dat[nidx] = merge(vl, vr);\n        }\n    }\n\n    T fold(int ql, int qr)\
    \ const {\n        ql = std::max(ql, 0);\n        qr = std::min(qr, length);\n\
    \        ql += length, qr += length;\n\n        T lacc = unit, racc = unit;\n\
    \        while (ql < qr) {\n            if (ql & 1) {\n                lacc =\
    \ merge(lacc, dat[ql]);\n                ++ql;\n            }\n            if\
    \ (qr & 1) {\n                --qr;\n                racc = merge(dat[qr], racc);\n\
    \            }\n            ql >>= 1, qr >>= 1;\n        }\n\n        return merge(lacc,\
    \ racc);\n    }\n\n    T get(int idx) const { return dat[idx + length]; }\n  \
    \  T fold_all() const { return dat[1]; }\n};\n#line 4 \"Verify/segment_tree_rsq.test.cpp\"\
    \n\n#include <iostream>\n\nusing lint = long long;\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n\n    int n, q;\n    std::cin >> n >>\
    \ q;\n\n    std::vector<lint> xs(n);\n    for (auto& x : xs) std::cin >> x;\n\
    \    SegmentTree<lint> seg(xs, 0, [](auto a, auto b) { return a + b; });\n\n \
    \   while (q--) {\n        int t;\n        std::cin >> t;\n\n        if (t ==\
    \ 0) {\n            int i;\n            lint x;\n            std::cin >> i >>\
    \ x;\n            seg.update(i, seg.get(i) + x);\n\n        } else {\n       \
    \     int l, r;\n            std::cin >> l >> r;\n            std::cout << seg.fold(l,\
    \ r) << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../DataStructure/segment_tree.hpp\"\n\n#include <iostream>\n\nusing\
    \ lint = long long;\n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \n    int n, q;\n    std::cin >> n >> q;\n\n    std::vector<lint> xs(n);\n   \
    \ for (auto& x : xs) std::cin >> x;\n    SegmentTree<lint> seg(xs, 0, [](auto\
    \ a, auto b) { return a + b; });\n\n    while (q--) {\n        int t;\n      \
    \  std::cin >> t;\n\n        if (t == 0) {\n            int i;\n            lint\
    \ x;\n            std::cin >> i >> x;\n            seg.update(i, seg.get(i) +\
    \ x);\n\n        } else {\n            int l, r;\n            std::cin >> l >>\
    \ r;\n            std::cout << seg.fold(l, r) << \"\\n\";\n        }\n    }\n\n\
    \    return 0;\n}\n"
  dependsOn:
  - DataStructure/segment_tree.hpp
  isVerificationFile: true
  path: Verify/segment_tree_rsq.test.cpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/segment_tree_rsq.test.cpp
layout: document
redirect_from:
- /verify/Verify/segment_tree_rsq.test.cpp
- /verify/Verify/segment_tree_rsq.test.cpp.html
title: Verify/segment_tree_rsq.test.cpp
---
