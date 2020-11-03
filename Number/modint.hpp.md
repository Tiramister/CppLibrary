---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Convolution/number_theoretical_transform.hpp
    title: Convolution/number_theoretical_transform.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/aho_corasick.test.cpp
    title: Verify/aho_corasick.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/combination.test.cpp
    title: Verify/combination.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/fixed_matrix_pow.test.cpp
    title: Verify/fixed_matrix_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/lazy_segment_tree_affine.test.cpp
    title: Verify/lazy_segment_tree_affine.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/matrix_pow.test.cpp
    title: Verify/matrix_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/mod_pow.test.cpp
    title: Verify/mod_pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/number_theoretical_transform.test.cpp
    title: Verify/number_theoretical_transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/segment_tree_affine.test.cpp
    title: Verify/segment_tree_affine.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Number/modint.hpp\"\n\n#include <iostream>\n\ntemplate <int\
    \ MOD>\nstruct ModInt {\n    using lint = long long;\n    int val;\n\n    // constructor\n\
    \    ModInt(lint v = 0) : val(v % MOD) {\n        if (val < 0) val += MOD;\n \
    \   };\n\n    // unary operator\n    ModInt operator+() const { return ModInt(val);\
    \ }\n    ModInt operator-() const { return ModInt(MOD - val); }\n\n    ModInt&\
    \ operator++() { return *this += 1; }\n    ModInt& operator--() { *this -= 1;\
    \ }\n\n    // functions\n    ModInt pow(lint n) const {\n        auto x = ModInt(1);\n\
    \        auto b = *this;\n        while (n > 0) {\n            if (n & 1) x *=\
    \ b;\n            n >>= 1;\n            b *= b;\n        }\n        return x;\n\
    \    }\n    ModInt inv() const {\n        int s = val, t = MOD,\n            xs\
    \ = 1, xt = 0;\n\n        while (t != 0) {\n            auto div = s / t;\n\n\
    \            s -= t * div;\n            xs -= xt * div;\n\n            std::swap(s,\
    \ t);\n            std::swap(xs, xt);\n        }\n\n        return xs;\n    }\n\
    \n    // arithmetic\n    ModInt operator+(const ModInt& x) const { return ModInt(*this)\
    \ += x; }\n    ModInt operator-(const ModInt& x) const { return ModInt(*this)\
    \ -= x; }\n    ModInt operator*(const ModInt& x) const { return ModInt(*this)\
    \ *= x; }\n    ModInt operator/(const ModInt& x) const { return ModInt(*this)\
    \ /= x; }\n\n    ModInt& operator+=(const ModInt& x) {\n        if ((val += x.val)\
    \ >= MOD) val -= MOD;\n        return *this;\n    }\n    ModInt& operator-=(const\
    \ ModInt& x) {\n        if ((val -= x.val) < 0) val += MOD;\n        return *this;\n\
    \    }\n    ModInt& operator*=(const ModInt& x) {\n        val = lint(val) * x.val\
    \ % MOD;\n        return *this;\n    }\n    ModInt& operator/=(const ModInt& x)\
    \ { return *this *= x.inv(); }\n\n    // comparator\n    bool operator==(const\
    \ ModInt& b) const { return val == b.val; }\n    bool operator!=(const ModInt&\
    \ b) const { return val != b.val; }\n\n    // I/O\n    friend std::istream& operator>>(std::istream&\
    \ is, ModInt& x) {\n        lint v;\n        is >> v;\n        x = v;\n      \
    \  return is;\n    }\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ ModInt& x) {\n        return os << x.val;\n    }\n};\n\n// constexpr int MOD\
    \ = 1000000007;\n// constexpr int MOD = 998244353;\n// using mint = ModInt<MOD>;\n"
  code: "#pragma once\n\n#include <iostream>\n\ntemplate <int MOD>\nstruct ModInt\
    \ {\n    using lint = long long;\n    int val;\n\n    // constructor\n    ModInt(lint\
    \ v = 0) : val(v % MOD) {\n        if (val < 0) val += MOD;\n    };\n\n    //\
    \ unary operator\n    ModInt operator+() const { return ModInt(val); }\n    ModInt\
    \ operator-() const { return ModInt(MOD - val); }\n\n    ModInt& operator++()\
    \ { return *this += 1; }\n    ModInt& operator--() { *this -= 1; }\n\n    // functions\n\
    \    ModInt pow(lint n) const {\n        auto x = ModInt(1);\n        auto b =\
    \ *this;\n        while (n > 0) {\n            if (n & 1) x *= b;\n          \
    \  n >>= 1;\n            b *= b;\n        }\n        return x;\n    }\n    ModInt\
    \ inv() const {\n        int s = val, t = MOD,\n            xs = 1, xt = 0;\n\n\
    \        while (t != 0) {\n            auto div = s / t;\n\n            s -= t\
    \ * div;\n            xs -= xt * div;\n\n            std::swap(s, t);\n      \
    \      std::swap(xs, xt);\n        }\n\n        return xs;\n    }\n\n    // arithmetic\n\
    \    ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }\n\
    \    ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }\n\
    \    ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }\n\
    \    ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }\n\n\
    \    ModInt& operator+=(const ModInt& x) {\n        if ((val += x.val) >= MOD)\
    \ val -= MOD;\n        return *this;\n    }\n    ModInt& operator-=(const ModInt&\
    \ x) {\n        if ((val -= x.val) < 0) val += MOD;\n        return *this;\n \
    \   }\n    ModInt& operator*=(const ModInt& x) {\n        val = lint(val) * x.val\
    \ % MOD;\n        return *this;\n    }\n    ModInt& operator/=(const ModInt& x)\
    \ { return *this *= x.inv(); }\n\n    // comparator\n    bool operator==(const\
    \ ModInt& b) const { return val == b.val; }\n    bool operator!=(const ModInt&\
    \ b) const { return val != b.val; }\n\n    // I/O\n    friend std::istream& operator>>(std::istream&\
    \ is, ModInt& x) {\n        lint v;\n        is >> v;\n        x = v;\n      \
    \  return is;\n    }\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ ModInt& x) {\n        return os << x.val;\n    }\n};\n\n// constexpr int MOD\
    \ = 1000000007;\n// constexpr int MOD = 998244353;\n// using mint = ModInt<MOD>;\n"
  dependsOn: []
  isVerificationFile: false
  path: Number/modint.hpp
  requiredBy:
  - Convolution/number_theoretical_transform.hpp
  timestamp: '2020-11-03 12:40:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/combination.test.cpp
  - Verify/matrix_pow.test.cpp
  - Verify/aho_corasick.test.cpp
  - Verify/number_theoretical_transform.test.cpp
  - Verify/lazy_segment_tree_affine.test.cpp
  - Verify/mod_pow.test.cpp
  - Verify/fixed_matrix_pow.test.cpp
  - Verify/segment_tree_affine.test.cpp
documentation_of: Number/modint.hpp
layout: document
redirect_from:
- /library/Number/modint.hpp
- /library/Number/modint.hpp.html
title: Number/modint.hpp
---
