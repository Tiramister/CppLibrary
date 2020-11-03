---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: Convolution/number_theoretical_transform.hpp
    title: Convolution/number_theoretical_transform.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: Verify/aho_corasick.test.cpp
    title: Verify/aho_corasick.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/combination.test.cpp
    title: Verify/combination.test.cpp
  - icon: ':heavy_check_mark:'
    path: Verify/lazy_segment_tree_affine.test.cpp
    title: Verify/lazy_segment_tree_affine.test.cpp
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
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Number/modint.hpp\"\n\n#include <iostream>\n\ntemplate <int\
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
    // using mint = ModInt<MOD>;\n"
  code: "#pragma once\n\n#include <iostream>\n\ntemplate <int MOD>\nstruct ModInt\
    \ {\n    using lint = long long;\n    int val;\n\n    // constructor\n    ModInt(lint\
    \ v = 0) : val(v % MOD) {\n        if (val < 0) val += MOD;\n    };\n\n    //\
    \ unary operator\n    ModInt operator+() const { return ModInt(val); }\n    ModInt\
    \ operator-() const { return ModInt(MOD - val); }\n    ModInt inv() const { return\
    \ this->pow(MOD - 2); }\n\n    // arithmetic\n    ModInt operator+(const ModInt&\
    \ x) const { return ModInt(*this) += x; }\n    ModInt operator-(const ModInt&\
    \ x) const { return ModInt(*this) -= x; }\n    ModInt operator*(const ModInt&\
    \ x) const { return ModInt(*this) *= x; }\n    ModInt operator/(const ModInt&\
    \ x) const { return ModInt(*this) /= x; }\n    ModInt pow(lint n) const {\n  \
    \      auto x = ModInt(1);\n        auto b = *this;\n        while (n > 0) {\n\
    \            if (n & 1) x *= b;\n            n >>= 1;\n            b *= b;\n \
    \       }\n        return x;\n    }\n\n    // compound assignment\n    ModInt&\
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
    // using mint = ModInt<MOD>;\n"
  dependsOn: []
  isVerificationFile: false
  path: Number/modint.hpp
  requiredBy:
  - Convolution/number_theoretical_transform.hpp
  timestamp: '2020-08-25 16:49:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - Verify/combination.test.cpp
  - Verify/aho_corasick.test.cpp
  - Verify/number_theoretical_transform.test.cpp
  - Verify/lazy_segment_tree_affine.test.cpp
  - Verify/mod_pow.test.cpp
  - Verify/segment_tree_affine.test.cpp
documentation_of: Number/modint.hpp
layout: document
redirect_from:
- /library/Number/modint.hpp
- /library/Number/modint.hpp.html
title: Number/modint.hpp
---
