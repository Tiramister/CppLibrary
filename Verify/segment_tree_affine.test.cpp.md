---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segment_tree.hpp
    title: DataStructure/segment_tree.hpp
  - icon: ':heavy_check_mark:'
    path: Number/modint.hpp
    title: Number/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"Verify/segment_tree_affine.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#line 2 \"DataStructure/segment_tree.hpp\"\
    \n\n#include <vector>\n#include <functional>\n\ntemplate <class T>\nstruct SegmentTree\
    \ {\n    using Merger = std::function<T(T, T)>;\n\n    int length;\n    std::vector<T>\
    \ dat;\n    T unit;\n    Merger merge;\n\n    SegmentTree() = default;\n\n   \
    \ SegmentTree(int n, const T& unit, const Merger& merge)\n        : length(1),\
    \ unit(unit), merge(merge) {\n        while (length < n) length <<= 1;\n     \
    \   dat.assign(length * 2, unit);\n    }\n\n    template <class Container>\n \
    \   SegmentTree(const Container& elems, const T& unit, const Merger& merge)\n\
    \        : length(1), unit(unit), merge(merge) {\n        int n = elems.size();\n\
    \        while (length < n) length <<= 1;\n\n        dat.assign(length * 2, unit);\n\
    \n        std::copy(elems.begin(), elems.end(), dat.begin() + length);\n\n   \
    \     for (int nidx = length - 1; nidx >= 1; --nidx) {\n            T vl = dat[nidx\
    \ * 2 + 0];\n            T vr = dat[nidx * 2 + 1];\n            dat[nidx] = merge(vl,\
    \ vr);\n        }\n    }\n\n    void update(int nidx, const T& elem) {\n     \
    \   nidx += length;\n        dat[nidx] = elem;\n\n        while (nidx > 0) {\n\
    \            nidx >>= 1;\n            T vl = dat[nidx * 2 + 0];\n            T\
    \ vr = dat[nidx * 2 + 1];\n            dat[nidx] = merge(vl, vr);\n        }\n\
    \    }\n\n    T fold(int ql, int qr) const {\n        ql = std::max(ql, 0);\n\
    \        qr = std::min(qr, length);\n        ql += length, qr += length;\n\n \
    \       T lacc = unit, racc = unit;\n        while (ql < qr) {\n            if\
    \ (ql & 1) {\n                lacc = merge(lacc, dat[ql]);\n                ++ql;\n\
    \            }\n            if (qr & 1) {\n                --qr;\n           \
    \     racc = merge(dat[qr], racc);\n            }\n            ql >>= 1, qr >>=\
    \ 1;\n        }\n\n        return merge(lacc, racc);\n    }\n\n    T get(int idx)\
    \ const { return dat[idx + length]; }\n    T fold_all() const { return dat[1];\
    \ }\n};\n#line 2 \"Number/modint.hpp\"\n\n#include <iostream>\n\ntemplate <int\
    \ MOD>\nstruct ModInt {\n    using lint = long long;\n    int val;\n\n    // constructor\n\
    \    ModInt(lint v = 0) : val(v % MOD) {\n        if (val < 0) val += MOD;\n \
    \   };\n\n    // unary operator\n    ModInt operator+() const { return ModInt(val);\
    \ }\n    ModInt operator-() const { return ModInt(MOD - val); }\n    ModInt inv()\
    \ const { return this->pow(MOD - 2); }\n\n    // arithmetic\n    ModInt operator+(const\
    \ ModInt& x) const { return ModInt(*this) += x; }\n    ModInt operator-(const\
    \ ModInt& x) const { return ModInt(*this) -= x; }\n    ModInt operator*(const\
    \ ModInt& x) const { return ModInt(*this) *= x; }\n    ModInt operator/(const\
    \ ModInt& x) const { return ModInt(*this) /= x; }\n    ModInt pow(lint n) const\
    \ {\n        auto x = ModInt(1);\n        auto b = *this;\n        while (n >\
    \ 0) {\n            if (n & 1) x *= b;\n            n >>= 1;\n            b *=\
    \ b;\n        }\n        return x;\n    }\n\n    // compound assignment\n    ModInt&\
    \ operator+=(const ModInt& x) {\n        if ((val += x.val) >= MOD) val -= MOD;\n\
    \        return *this;\n    }\n    ModInt& operator-=(const ModInt& x) {\n   \
    \     if ((val -= x.val) < 0) val += MOD;\n        return *this;\n    }\n    ModInt&\
    \ operator*=(const ModInt& x) {\n        val = lint(val) * x.val % MOD;\n    \
    \    return *this;\n    }\n    ModInt& operator/=(const ModInt& x) { return *this\
    \ *= x.inv(); }\n\n    // compare\n    bool operator==(const ModInt& b) const\
    \ { return val == b.val; }\n    bool operator!=(const ModInt& b) const { return\
    \ val != b.val; }\n    bool operator<(const ModInt& b) const { return val < b.val;\
    \ }\n    bool operator<=(const ModInt& b) const { return val <= b.val; }\n   \
    \ bool operator>(const ModInt& b) const { return val > b.val; }\n    bool operator>=(const\
    \ ModInt& b) const { return val >= b.val; }\n\n    // I/O\n    friend std::istream&\
    \ operator>>(std::istream& is, ModInt& x) noexcept {\n        lint v;\n      \
    \  is >> v;\n        x = v;\n        return is;\n    }\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val;\
    \ }\n};\n\n// constexpr int MOD = 1000000007;\n// constexpr int MOD = 998244353;\n\
    // using mint = ModInt<MOD>;\n#line 5 \"Verify/segment_tree_affine.test.cpp\"\n\
    \nconstexpr int MOD = 998244353;\nusing mint = ModInt<MOD>;\n\ntemplate <class\
    \ T>\nstruct Affine {\n    T a, b;\n    Affine() = default;\n    Affine(T a, T\
    \ b) : a(a), b(b) {}\n\n    T operator()(T x) const { return a * x + b; }\n};\n\
    \nusing affine = Affine<mint>;\n\nint main() {\n    std::cin.tie(nullptr);\n \
    \   std::ios::sync_with_stdio(false);\n\n    int n, q;\n    std::cin >> n >> q;\n\
    \n    std::vector<affine> xs(n);\n    for (auto& x : xs) std::cin >> x.a >> x.b;\n\
    \n    SegmentTree<affine>\n        seg(xs, affine(1, 0),\n            [](affine\
    \ f, affine g) { return affine(f.a * g.a, g.a * f.b + g.b); });\n\n    while (q--)\
    \ {\n        int t;\n        std::cin >> t;\n\n        if (t == 0) {\n       \
    \     int i, a, b;\n            std::cin >> i >> a >> b;\n            seg.update(i,\
    \ affine(a, b));\n\n        } else {\n            int l, r, x;\n            std::cin\
    \ >> l >> r >> x;\n            auto f = seg.fold(l, r);\n            std::cout\
    \ << f(x) << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../DataStructure/segment_tree.hpp\"\n#include \"../Number/modint.hpp\"\
    \n\nconstexpr int MOD = 998244353;\nusing mint = ModInt<MOD>;\n\ntemplate <class\
    \ T>\nstruct Affine {\n    T a, b;\n    Affine() = default;\n    Affine(T a, T\
    \ b) : a(a), b(b) {}\n\n    T operator()(T x) const { return a * x + b; }\n};\n\
    \nusing affine = Affine<mint>;\n\nint main() {\n    std::cin.tie(nullptr);\n \
    \   std::ios::sync_with_stdio(false);\n\n    int n, q;\n    std::cin >> n >> q;\n\
    \n    std::vector<affine> xs(n);\n    for (auto& x : xs) std::cin >> x.a >> x.b;\n\
    \n    SegmentTree<affine>\n        seg(xs, affine(1, 0),\n            [](affine\
    \ f, affine g) { return affine(f.a * g.a, g.a * f.b + g.b); });\n\n    while (q--)\
    \ {\n        int t;\n        std::cin >> t;\n\n        if (t == 0) {\n       \
    \     int i, a, b;\n            std::cin >> i >> a >> b;\n            seg.update(i,\
    \ affine(a, b));\n\n        } else {\n            int l, r, x;\n            std::cin\
    \ >> l >> r >> x;\n            auto f = seg.fold(l, r);\n            std::cout\
    \ << f(x) << \"\\n\";\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/segment_tree.hpp
  - Number/modint.hpp
  isVerificationFile: true
  path: Verify/segment_tree_affine.test.cpp
  requiredBy: []
  timestamp: '2020-08-25 16:49:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/segment_tree_affine.test.cpp
layout: document
redirect_from:
- /verify/Verify/segment_tree_affine.test.cpp
- /verify/Verify/segment_tree_affine.test.cpp.html
title: Verify/segment_tree_affine.test.cpp
---
