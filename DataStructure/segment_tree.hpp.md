---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/segment_tree_affine.test.cpp
    title: Verify/segment_tree_affine.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/segment_tree_rsq.test.cpp
    title: Verify/segment_tree_rsq.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"DataStructure/segment_tree.hpp\"\n\n#include <vector>\n\
    #include <functional>\n\ntemplate <class T>\nstruct SegmentTree {\n    using Merger\
    \ = std::function<T(T, T)>;\n\n    int length;\n    std::vector<T> dat;\n    T\
    \ unit;\n    Merger merge;\n\n    SegmentTree() = default;\n\n    SegmentTree(int\
    \ n, const T& unit, const Merger& merge)\n        : length(1), unit(unit), merge(merge)\
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
    \  T fold_all() const { return dat[1]; }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <functional>\n\ntemplate <class\
    \ T>\nstruct SegmentTree {\n    using Merger = std::function<T(T, T)>;\n\n   \
    \ int length;\n    std::vector<T> dat;\n    T unit;\n    Merger merge;\n\n   \
    \ SegmentTree() = default;\n\n    SegmentTree(int n, const T& unit, const Merger&\
    \ merge)\n        : length(1), unit(unit), merge(merge) {\n        while (length\
    \ < n) length <<= 1;\n        dat.assign(length * 2, unit);\n    }\n\n    template\
    \ <class Container>\n    SegmentTree(const Container& elems, const T& unit, const\
    \ Merger& merge)\n        : length(1), unit(unit), merge(merge) {\n        int\
    \ n = elems.size();\n        while (length < n) length <<= 1;\n\n        dat.assign(length\
    \ * 2, unit);\n\n        std::copy(elems.begin(), elems.end(), dat.begin() + length);\n\
    \n        for (int nidx = length - 1; nidx >= 1; --nidx) {\n            T vl =\
    \ dat[nidx * 2 + 0];\n            T vr = dat[nidx * 2 + 1];\n            dat[nidx]\
    \ = merge(vl, vr);\n        }\n    }\n\n    void update(int nidx, const T& elem)\
    \ {\n        nidx += length;\n        dat[nidx] = elem;\n\n        while (nidx\
    \ > 0) {\n            nidx >>= 1;\n            T vl = dat[nidx * 2 + 0];\n   \
    \         T vr = dat[nidx * 2 + 1];\n            dat[nidx] = merge(vl, vr);\n\
    \        }\n    }\n\n    T fold(int ql, int qr) const {\n        ql = std::max(ql,\
    \ 0);\n        qr = std::min(qr, length);\n        ql += length, qr += length;\n\
    \n        T lacc = unit, racc = unit;\n        while (ql < qr) {\n           \
    \ if (ql & 1) {\n                lacc = merge(lacc, dat[ql]);\n              \
    \  ++ql;\n            }\n            if (qr & 1) {\n                --qr;\n  \
    \              racc = merge(dat[qr], racc);\n            }\n            ql >>=\
    \ 1, qr >>= 1;\n        }\n\n        return merge(lacc, racc);\n    }\n\n    T\
    \ get(int idx) const { return dat[idx + length]; }\n    T fold_all() const { return\
    \ dat[1]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructure/segment_tree.hpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/segment_tree_rsq.test.cpp
  - Verify/segment_tree_affine.test.cpp
documentation_of: DataStructure/segment_tree.hpp
layout: document
redirect_from:
- /library/DataStructure/segment_tree.hpp
- /library/DataStructure/segment_tree.hpp.html
title: DataStructure/segment_tree.hpp
---
