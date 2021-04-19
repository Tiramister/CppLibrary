---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/lazy_segment_tree.hpp
    title: DataStructure/lazy_segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G
  bundledCode: "#line 1 \"Verify/lazy_segment_tree_add_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G\"\n\n#line\
    \ 2 \"DataStructure/lazy_segment_tree.hpp\"\n\n#include <vector>\n#include <functional>\n\
    \ntemplate <class T, class E>\nstruct LazySegmentTree {\n    using DMerger = std::function<T(T,\
    \ T)>;\n    using OMerger = std::function<E(E, E)>;\n    using Applier = std::function<T(T,\
    \ E, int)>;\n\n    int length;\n\n    T d_unit;\n    E o_unit;\n\n    std::vector<T>\
    \ dat;\n    std::vector<E> ope;\n\n    DMerger dmerge;\n    OMerger omerge;\n\
    \    Applier app;\n\n    explicit LazySegmentTree(int n,\n                   \
    \          T d_unit, E o_unit,\n                             DMerger dmerge,\n\
    \                             OMerger omerge,\n                             Applier\
    \ app)\n        : length(1),\n          d_unit(d_unit),\n          o_unit(o_unit),\n\
    \          dmerge(dmerge),\n          omerge(omerge),\n          app(app) {\n\
    \        while (length < n) length <<= 1;\n\n        dat.assign(length * 2, d_unit);\n\
    \        ope.assign(length * 2, o_unit);\n    }\n\n    template <class Container>\n\
    \    explicit LazySegmentTree(const Container& elems,\n                      \
    \       T d_unit, E o_unit,\n                             DMerger dmerge,\n  \
    \                           OMerger omerge,\n                             Applier\
    \ app)\n        : length(1),\n          d_unit(d_unit),\n          o_unit(o_unit),\n\
    \          dmerge(dmerge),\n          omerge(omerge),\n          app(app) {\n\
    \        int n = elems.size();\n        while (length < n) length <<= 1;\n\n \
    \       dat.assign(length * 2, d_unit);\n        ope.assign(length * 2, o_unit);\n\
    \n        std::copy(elems.begin(), elems.end(), dat.begin() + length);\n\n   \
    \     for (int nidx = length - 1; nidx >= 1; --nidx) {\n            T vl = dat[nidx\
    \ * 2 + 0];\n            T vr = dat[nidx * 2 + 1];\n            dat[nidx] = dmerge(vl,\
    \ vr);\n        }\n    }\n\n    void propagate(int nidx, int len) {\n        if\
    \ (ope[nidx] == o_unit) return;\n\n        // propagate\n        if (len > 1)\
    \ {\n            ope[nidx * 2 + 0] = omerge(ope[nidx * 2 + 0], ope[nidx]);\n \
    \           ope[nidx * 2 + 1] = omerge(ope[nidx * 2 + 1], ope[nidx]);\n      \
    \  }\n\n        // update data\n        dat[nidx] = app(dat[nidx], ope[nidx],\
    \ len);\n        ope[nidx] = o_unit;\n    }\n\n    void update(int ql, int qr,\
    \ E e, int nidx, int nl, int nr) {\n        propagate(nidx, nr - nl);\n\n    \
    \    if (nr <= ql || qr <= nl) return;\n        if (ql <= nl && nr <= qr) {\n\
    \            ope[nidx] = omerge(ope[nidx], e);\n            propagate(nidx, nr\
    \ - nl);\n            return;\n        }\n\n        int nm = (nl + nr) / 2;\n\
    \        update(ql, qr, e, nidx * 2 + 0, nl, nm);\n        update(ql, qr, e, nidx\
    \ * 2 + 1, nm, nr);\n\n        // update data\n        dat[nidx] = dmerge(dat[nidx\
    \ * 2 + 0], dat[nidx * 2 + 1]);\n    }\n\n    void update(int ql, int qr, E e)\
    \ { return update(ql, qr, e, 1, 0, length); }\n\n    T fold(int ql, int qr, int\
    \ nidx, int nl, int nr) {\n        propagate(nidx, nr - nl);\n\n        if (nr\
    \ <= ql || qr <= nl) return d_unit;\n        if (ql <= nl && nr <= qr) return\
    \ dat[nidx];\n\n        int nm = (nl + nr) / 2;\n        T vl = fold(ql, qr, nidx\
    \ * 2 + 0, nl, nm);\n        T vr = fold(ql, qr, nidx * 2 + 1, nm, nr);\n    \
    \    return dmerge(vl, vr);\n    }\n\n    T fold(int ql, int qr) { return fold(ql,\
    \ qr, 1, 0, length); }\n\n    T get(int idx) { return fold(idx, idx + 1); }\n\
    \    T fold_all() { return fold(0, length); }\n};\n#line 4 \"Verify/lazy_segment_tree_add_sum.test.cpp\"\
    \n\n#include <iostream>\n\nusing lint = long long;\n\nint main() {\n    std::cin.tie();\n\
    \    std::ios::sync_with_stdio(false);\n\n    int n, q;\n    std::cin >> n >>\
    \ q;\n\n    LazySegmentTree<lint, lint> seg(\n        n, 0, 0,\n        [](auto\
    \ a, auto b) { return a + b; },\n        [](auto e, auto f) { return e + f; },\n\
    \        [](auto a, auto e, int l) { return a + e * l; });\n\n    while (q--)\
    \ {\n        int t;\n        std::cin >> t;\n\n        if (t == 0) {\n       \
    \     int l, r;\n            lint x;\n            std::cin >> l >> r >> x;\n \
    \           --l, --r;\n            seg.update(l, r + 1, x);\n\n        } else\
    \ {\n            int l, r;\n            std::cin >> l >> r;\n            --l,\
    \ --r;\n            std::cout << seg.fold(l, r + 1) << \"\\n\";\n        }\n \
    \   }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G\"\
    \n\n#include \"../DataStructure/lazy_segment_tree.hpp\"\n\n#include <iostream>\n\
    \nusing lint = long long;\n\nint main() {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\
    \n    int n, q;\n    std::cin >> n >> q;\n\n    LazySegmentTree<lint, lint> seg(\n\
    \        n, 0, 0,\n        [](auto a, auto b) { return a + b; },\n        [](auto\
    \ e, auto f) { return e + f; },\n        [](auto a, auto e, int l) { return a\
    \ + e * l; });\n\n    while (q--) {\n        int t;\n        std::cin >> t;\n\n\
    \        if (t == 0) {\n            int l, r;\n            lint x;\n         \
    \   std::cin >> l >> r >> x;\n            --l, --r;\n            seg.update(l,\
    \ r + 1, x);\n\n        } else {\n            int l, r;\n            std::cin\
    \ >> l >> r;\n            --l, --r;\n            std::cout << seg.fold(l, r +\
    \ 1) << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/lazy_segment_tree.hpp
  isVerificationFile: true
  path: Verify/lazy_segment_tree_add_sum.test.cpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/lazy_segment_tree_add_sum.test.cpp
layout: document
redirect_from:
- /verify/Verify/lazy_segment_tree_add_sum.test.cpp
- /verify/Verify/lazy_segment_tree_add_sum.test.cpp.html
title: Verify/lazy_segment_tree_add_sum.test.cpp
---
