---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/lazy_segment_tree.hpp
    title: DataStructure/lazy_segment_tree.hpp
  - icon: ':heavy_check_mark:'
    path: Number/modint.hpp
    title: Number/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"Verify/lazy_segment_tree_affine.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n#line 2 \"DataStructure/lazy_segment_tree.hpp\"\
    \n\n#include <vector>\n#include <functional>\n\ntemplate <class T, class E>\n\
    struct LazySegmentTree {\n    using DMerger = std::function<T(T, T)>;\n    using\
    \ OMerger = std::function<E(E, E)>;\n    using Applier = std::function<T(T, E,\
    \ int)>;\n\n    int length;\n\n    T d_unit;\n    E o_unit;\n\n    std::vector<T>\
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
    \    T fold_all() { return fold(0, length); }\n};\n#line 2 \"Number/modint.hpp\"\
    \n\n#include <iostream>\n\ntemplate <int MOD>\nstruct ModInt {\n    using lint\
    \ = long long;\n    int val;\n\n    // constructor\n    ModInt(lint v = 0) : val(v\
    \ % MOD) {\n        if (val < 0) val += MOD;\n    };\n\n    // unary operator\n\
    \    ModInt operator+() const { return ModInt(val); }\n    ModInt operator-()\
    \ const { return ModInt(MOD - val); }\n\n    ModInt& operator++() { return *this\
    \ += 1; }\n    ModInt& operator--() { *this -= 1; }\n\n    // functions\n    ModInt\
    \ pow(lint n) const {\n        auto x = ModInt(1);\n        auto b = *this;\n\
    \        while (n > 0) {\n            if (n & 1) x *= b;\n            n >>= 1;\n\
    \            b *= b;\n        }\n        return x;\n    }\n    ModInt inv() const\
    \ {\n        int s = val, t = MOD,\n            xs = 1, xt = 0;\n\n        while\
    \ (t != 0) {\n            auto div = s / t;\n\n            s -= t * div;\n   \
    \         xs -= xt * div;\n\n            std::swap(s, t);\n            std::swap(xs,\
    \ xt);\n        }\n\n        return xs;\n    }\n\n    // arithmetic\n    ModInt\
    \ operator+(const ModInt& x) const { return ModInt(*this) += x; }\n    ModInt\
    \ operator-(const ModInt& x) const { return ModInt(*this) -= x; }\n    ModInt\
    \ operator*(const ModInt& x) const { return ModInt(*this) *= x; }\n    ModInt\
    \ operator/(const ModInt& x) const { return ModInt(*this) /= x; }\n\n    ModInt&\
    \ operator+=(const ModInt& x) {\n        if ((val += x.val) >= MOD) val -= MOD;\n\
    \        return *this;\n    }\n    ModInt& operator-=(const ModInt& x) {\n   \
    \     if ((val -= x.val) < 0) val += MOD;\n        return *this;\n    }\n    ModInt&\
    \ operator*=(const ModInt& x) {\n        val = lint(val) * x.val % MOD;\n    \
    \    return *this;\n    }\n    ModInt& operator/=(const ModInt& x) { return *this\
    \ *= x.inv(); }\n\n    // comparator\n    bool operator==(const ModInt& b) const\
    \ { return val == b.val; }\n    bool operator!=(const ModInt& b) const { return\
    \ val != b.val; }\n\n    // I/O\n    friend std::istream& operator>>(std::istream&\
    \ is, ModInt& x) {\n        lint v;\n        is >> v;\n        x = v;\n      \
    \  return is;\n    }\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ ModInt& x) {\n        return os << x.val;\n    }\n};\n\n// constexpr int MOD\
    \ = 1000000007;\n// constexpr int MOD = 998244353;\n// using mint = ModInt<MOD>;\n\
    #line 5 \"Verify/lazy_segment_tree_affine.test.cpp\"\n\nconstexpr int MOD = 998244353;\n\
    using mint = ModInt<MOD>;\n\ntemplate <class T>\nstruct Affine {\n    T a, b;\n\
    \    Affine() = default;\n    Affine(T a, T b) : a(a), b(b) {}\n\n    T operator()(T\
    \ x) const { return a * x + b; }\n    bool operator==(const Affine<T>& rhs) const\
    \ {\n        return a == rhs.a && b == rhs.b;\n    }\n};\n\nusing affine = Affine<mint>;\n\
    \nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \n    int n, q;\n    std::cin >> n >> q;\n\n    std::vector<mint> xs(n);\n   \
    \ for (auto& x : xs) std::cin >> x;\n\n    LazySegmentTree<mint, affine>\n   \
    \     seg(\n            xs, 0, affine(1, 0),\n            [](mint a, mint b) {\
    \ return a + b; },\n            [](affine f, affine g) { return affine(f.a * g.a,\
    \ g.a * f.b + g.b); },\n            [](mint a, affine f, int k) { return f.a *\
    \ a + f.b * k; });\n\n    while (q--) {\n        int t;\n        std::cin >> t;\n\
    \n        if (t == 0) {\n            int l, r, a, b;\n            std::cin >>\
    \ l >> r >> a >> b;\n            seg.update(l, r, affine(a, b));\n\n        }\
    \ else {\n            int l, r;\n            std::cin >> l >> r;\n           \
    \ std::cout << seg.fold(l, r) << \"\\n\";\n        }\n    }\n\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../DataStructure/lazy_segment_tree.hpp\"\n#include \"../Number/modint.hpp\"\
    \n\nconstexpr int MOD = 998244353;\nusing mint = ModInt<MOD>;\n\ntemplate <class\
    \ T>\nstruct Affine {\n    T a, b;\n    Affine() = default;\n    Affine(T a, T\
    \ b) : a(a), b(b) {}\n\n    T operator()(T x) const { return a * x + b; }\n  \
    \  bool operator==(const Affine<T>& rhs) const {\n        return a == rhs.a &&\
    \ b == rhs.b;\n    }\n};\n\nusing affine = Affine<mint>;\n\nint main() {\n   \
    \ std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\n    int n,\
    \ q;\n    std::cin >> n >> q;\n\n    std::vector<mint> xs(n);\n    for (auto&\
    \ x : xs) std::cin >> x;\n\n    LazySegmentTree<mint, affine>\n        seg(\n\
    \            xs, 0, affine(1, 0),\n            [](mint a, mint b) { return a +\
    \ b; },\n            [](affine f, affine g) { return affine(f.a * g.a, g.a * f.b\
    \ + g.b); },\n            [](mint a, affine f, int k) { return f.a * a + f.b *\
    \ k; });\n\n    while (q--) {\n        int t;\n        std::cin >> t;\n\n    \
    \    if (t == 0) {\n            int l, r, a, b;\n            std::cin >> l >>\
    \ r >> a >> b;\n            seg.update(l, r, affine(a, b));\n\n        } else\
    \ {\n            int l, r;\n            std::cin >> l >> r;\n            std::cout\
    \ << seg.fold(l, r) << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/lazy_segment_tree.hpp
  - Number/modint.hpp
  isVerificationFile: true
  path: Verify/lazy_segment_tree_affine.test.cpp
  requiredBy: []
  timestamp: '2020-11-03 12:40:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/lazy_segment_tree_affine.test.cpp
layout: document
redirect_from:
- /verify/Verify/lazy_segment_tree_affine.test.cpp
- /verify/Verify/lazy_segment_tree_affine.test.cpp.html
title: Verify/lazy_segment_tree_affine.test.cpp
---
