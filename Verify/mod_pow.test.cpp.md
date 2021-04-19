---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Number/modint.hpp
    title: Number/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B
  bundledCode: "#line 1 \"Verify/mod_pow.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n\n#line 2 \"Number/modint.hpp\"\n\n#include <iostream>\n\ntemplate <int MOD>\n\
    struct ModInt {\n    using lint = long long;\n    int val;\n\n    // constructor\n\
    \    ModInt(lint v = 0) : val(v % MOD) {\n        if (val < 0) val += MOD;\n \
    \   };\n\n    // unary operator\n    ModInt operator+() const { return ModInt(val);\
    \ }\n    ModInt operator-() const { return ModInt(MOD - val); }\n\n    ModInt&\
    \ operator++() { return *this += 1; }\n    ModInt& operator--() { return *this\
    \ -= 1; }\n\n    // functions\n    ModInt pow(lint n) const {\n        auto x\
    \ = ModInt(1);\n        auto b = *this;\n        while (n > 0) {\n           \
    \ if (n & 1) x *= b;\n            n >>= 1;\n            b *= b;\n        }\n \
    \       return x;\n    }\n    ModInt inv() const {\n        int s = val, t = MOD,\n\
    \            xs = 1, xt = 0;\n\n        while (t != 0) {\n            auto div\
    \ = s / t;\n\n            s -= t * div;\n            xs -= xt * div;\n\n     \
    \       std::swap(s, t);\n            std::swap(xs, xt);\n        }\n\n      \
    \  return xs;\n    }\n\n    // arithmetic\n    ModInt operator+(const ModInt&\
    \ x) const { return ModInt(*this) += x; }\n    ModInt operator-(const ModInt&\
    \ x) const { return ModInt(*this) -= x; }\n    ModInt operator*(const ModInt&\
    \ x) const { return ModInt(*this) *= x; }\n    ModInt operator/(const ModInt&\
    \ x) const { return ModInt(*this) /= x; }\n\n    ModInt& operator+=(const ModInt&\
    \ x) {\n        if ((val += x.val) >= MOD) val -= MOD;\n        return *this;\n\
    \    }\n    ModInt& operator-=(const ModInt& x) {\n        if ((val -= x.val)\
    \ < 0) val += MOD;\n        return *this;\n    }\n    ModInt& operator*=(const\
    \ ModInt& x) {\n        val = lint(val) * x.val % MOD;\n        return *this;\n\
    \    }\n    ModInt& operator/=(const ModInt& x) { return *this *= x.inv(); }\n\
    \n    // comparator\n    bool operator==(const ModInt& b) const { return val ==\
    \ b.val; }\n    bool operator!=(const ModInt& b) const { return val != b.val;\
    \ }\n\n    // I/O\n    friend std::istream& operator>>(std::istream& is, ModInt&\
    \ x) {\n        lint v;\n        is >> v;\n        x = v;\n        return is;\n\
    \    }\n    friend std::ostream& operator<<(std::ostream& os, const ModInt& x)\
    \ {\n        return os << x.val;\n    }\n};\n\nusing modint1000000007 = ModInt<1000000007>;\n\
    using modint998244353 = ModInt<998244353>;\n#line 4 \"Verify/mod_pow.test.cpp\"\
    \n\nconstexpr int MOD = 1e9 + 7;\nusing mint = ModInt<MOD>;\n\nint main() {\n\
    \    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n    int m, n;\n\
    \    std::cin >> m >> n;\n    std::cout << mint(m).pow(n) << \"\\n\";\n\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B\"\
    \n\n#include \"../Number/modint.hpp\"\n\nconstexpr int MOD = 1e9 + 7;\nusing mint\
    \ = ModInt<MOD>;\n\nint main() {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\
    \n    int m, n;\n    std::cin >> m >> n;\n    std::cout << mint(m).pow(n) << \"\
    \\n\";\n\n    return 0;\n}\n"
  dependsOn:
  - Number/modint.hpp
  isVerificationFile: true
  path: Verify/mod_pow.test.cpp
  requiredBy: []
  timestamp: '2021-04-20 01:42:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/mod_pow.test.cpp
layout: document
redirect_from:
- /verify/Verify/mod_pow.test.cpp
- /verify/Verify/mod_pow.test.cpp.html
title: Verify/mod_pow.test.cpp
---
