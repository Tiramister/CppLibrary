---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Number/fixed_matrix.hpp
    title: Number/fixed_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: Number/modint.hpp
    title: Number/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1073
    links:
    - https://yukicoder.me/problems/no/1073
  bundledCode: "#line 1 \"Verify/fixed_matrix_pow.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/1073\"\
    \n\n#line 2 \"Number/modint.hpp\"\n\n#include <iostream>\n\ntemplate <int MOD>\n\
    struct ModInt {\n    using lint = long long;\n    int val;\n\n    // constructor\n\
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
    \ = 1000000007;\n// constexpr int MOD = 998244353;\n// using mint = ModInt<MOD>;\n\
    #line 2 \"Number/fixed_matrix.hpp\"\n\n#include <array>\n\ntemplate <class T,\
    \ int D>\nstruct Matrix : public std::array<std::array<T, D>, D> {\n    // constructor\n\
    \    Matrix(T val = 0) {\n        for (auto& v : *this) v.fill(val);\n    }\n\n\
    \    static Matrix id() {\n        Matrix m;\n        for (int i = 0; i < D; ++i)\
    \ m[i][i] = 1;\n        return m;\n    }\n\n    // arithmetic\n    Matrix operator*(const\
    \ Matrix& m) const { return Matrix(*this) *= m; }\n    Matrix& operator*=(const\
    \ Matrix& m) {\n        Matrix nmat;\n        for (auto& v : nmat) v.fill(0);\n\
    \n        for (int i = 0; i < D; ++i) {\n            for (int j = 0; j < D; ++j)\
    \ {\n                for (int k = 0; k < D; ++k) {\n                    nmat[i][j]\
    \ += (*this)[i][k] * m[k][j];\n                }\n            }\n        }\n \
    \       return *this = nmat;\n    }\n\n    template <class U>\n    Matrix pow(U\
    \ k) {\n        Matrix ret = id();\n        Matrix a = *this;\n\n        while\
    \ (k > 0) {\n            if (k & 1) ret *= a;\n            a *= a;\n         \
    \   k >>= 1;\n        }\n        return ret;\n    }\n};\n#line 5 \"Verify/fixed_matrix_pow.test.cpp\"\
    \n\n#line 7 \"Verify/fixed_matrix_pow.test.cpp\"\n\nconstexpr int MOD = 1000000007;\n\
    using mint = ModInt<MOD>;\nusing lint = long long;\n\nint main() {\n    Matrix<mint,\
    \ 6> m;\n    for (int i = 0; i < 6; ++i) m[0][i] = mint(6).inv();\n    for (int\
    \ i = 1; i < 6; ++i) m[i][i - 1] = 1;\n\n    lint n;\n    std::cin >> n;\n   \
    \ std::cout << (m.pow(n))[0][0] << \"\\n\";\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1073\"\n\n#include \"\
    ../Number/modint.hpp\"\n#include \"../Number/fixed_matrix.hpp\"\n\n#include <iostream>\n\
    \nconstexpr int MOD = 1000000007;\nusing mint = ModInt<MOD>;\nusing lint = long\
    \ long;\n\nint main() {\n    Matrix<mint, 6> m;\n    for (int i = 0; i < 6; ++i)\
    \ m[0][i] = mint(6).inv();\n    for (int i = 1; i < 6; ++i) m[i][i - 1] = 1;\n\
    \n    lint n;\n    std::cin >> n;\n    std::cout << (m.pow(n))[0][0] << \"\\n\"\
    ;\n\n    return 0;\n}\n"
  dependsOn:
  - Number/modint.hpp
  - Number/fixed_matrix.hpp
  isVerificationFile: true
  path: Verify/fixed_matrix_pow.test.cpp
  requiredBy: []
  timestamp: '2020-11-03 12:40:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/fixed_matrix_pow.test.cpp
layout: document
redirect_from:
- /verify/Verify/fixed_matrix_pow.test.cpp
- /verify/Verify/fixed_matrix_pow.test.cpp.html
title: Verify/fixed_matrix_pow.test.cpp
---
