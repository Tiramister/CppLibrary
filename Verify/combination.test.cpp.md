---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Number/combination.hpp
    title: Number/combination.hpp
  - icon: ':question:'
    path: Number/modint.hpp
    title: Number/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C
  bundledCode: "#line 1 \"Verify/combination.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C\"\
    \n\n#line 2 \"Number/modint.hpp\"\n\n#include <iostream>\n\ntemplate <int MOD>\n\
    struct ModInt {\n    using lint = long long;\n    int val;\n\n    // constructor\n\
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
    // using mint = ModInt<MOD>;\n#line 2 \"Number/combination.hpp\"\n\n#include <vector>\n\
    \ntemplate <class T>\nstruct Combination {\n    int max_n;\n    std::vector<T>\
    \ f, invf;\n\n    explicit Combination(int n)\n        : max_n(n), f(n + 1), invf(n\
    \ + 1) {\n        f[0] = 1;\n        for (int i = 1; i <= n; ++i) {\n        \
    \    f[i] = f[i - 1] * i;\n        }\n\n        invf[max_n] = f[max_n].inv();\n\
    \        for (int i = max_n - 1; i >= 0; --i) {\n            invf[i] = invf[i\
    \ + 1] * (i + 1);\n        }\n    }\n\n    T fact(int n) const { return n < 0\
    \ ? T(0) : f[n]; }\n    T invfact(int n) const { return n < 0 ? T(0) : invf[n];\
    \ }\n    T perm(int a, int b) const {\n        return a < b || b < 0 ? T(0) :\
    \ f[a] * invf[a - b];\n    }\n    T binom(int a, int b) const {\n        return\
    \ a < b || b < 0 ? T(0) : f[a] * invf[a - b] * invf[b];\n    }\n};\n#line 5 \"\
    Verify/combination.test.cpp\"\n\nconstexpr int MOD = 1e9 + 7;\nusing mint = ModInt<MOD>;\n\
    \nconst Combination<mint> C(1000);\n\nint main() {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\
    \n    int n, k;\n    std::cin >> n >> k;\n\n    mint ans = 0;\n    for (int i\
    \ = 0; i <= k; ++i) {\n        ans += mint(-1).pow(k - i) * C.binom(k, i) * mint(i).pow(n);\n\
    \    }\n    std::cout << ans << \"\\n\";\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C\"\
    \n\n#include \"../Number/modint.hpp\"\n#include \"../Number/combination.hpp\"\n\
    \nconstexpr int MOD = 1e9 + 7;\nusing mint = ModInt<MOD>;\n\nconst Combination<mint>\
    \ C(1000);\n\nint main() {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\
    \n    int n, k;\n    std::cin >> n >> k;\n\n    mint ans = 0;\n    for (int i\
    \ = 0; i <= k; ++i) {\n        ans += mint(-1).pow(k - i) * C.binom(k, i) * mint(i).pow(n);\n\
    \    }\n    std::cout << ans << \"\\n\";\n\n    return 0;\n}\n"
  dependsOn:
  - Number/modint.hpp
  - Number/combination.hpp
  isVerificationFile: true
  path: Verify/combination.test.cpp
  requiredBy: []
  timestamp: '2020-08-25 16:49:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/combination.test.cpp
layout: document
redirect_from:
- /verify/Verify/combination.test.cpp
- /verify/Verify/combination.test.cpp.html
title: Verify/combination.test.cpp
---
