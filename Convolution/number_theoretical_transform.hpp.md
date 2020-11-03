---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Number/modint.hpp
    title: Number/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/number_theoretical_transform.test.cpp
    title: Verify/number_theoretical_transform.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Convolution/number_theoretical_transform.hpp\"\n\n#line\
    \ 2 \"Number/modint.hpp\"\n\n#include <iostream>\n\ntemplate <int MOD>\nstruct\
    \ ModInt {\n    using lint = long long;\n    int val;\n\n    // constructor\n\
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
    // using mint = ModInt<MOD>;\n#line 4 \"Convolution/number_theoretical_transform.hpp\"\
    \n\n#include <vector>\n\ntemplate <int MOD, int Root>\nstruct NumberTheoreticalTransform\
    \ {\n    using mint = ModInt<MOD>;\n    using mints = std::vector<mint>;\n\n \
    \   // the 2^k-th root of 1\n    std::vector<mint> zetas;\n\n    explicit NumberTheoreticalTransform()\
    \ {\n        int exp = MOD - 1;\n        while (true) {\n            mint zeta\
    \ = mint(Root).pow(exp);\n            zetas.push_back(zeta);\n            if (exp\
    \ & 1) break;\n            exp /= 2;\n        }\n    }\n\n    // ceil(log_2 n)\n\
    \    static int clog2(int n) {\n        int k = 0;\n        while ((1 << k) <\
    \ n) ++k;\n        return k;\n    }\n\n    // 2-radix cooley-tukey algorithm without\
    \ bit reverse\n    // the size of f must be a power of 2\n    void ntt(mints&\
    \ f) const {\n        int n = f.size();\n\n        for (int m = n >> 1; m >= 1;\
    \ m >>= 1) {\n            auto zeta = zetas[clog2(m) + 1];\n            mint zetapow(1);\n\
    \n            for (int p = 0; p < m; ++p) {\n                for (int s = 0; s\
    \ < n; s += (m << 1)) {\n                    auto l = f[s + p],\n            \
    \             r = f[s + p + m];\n\n                    f[s + p] = l + r;\n   \
    \                 f[s + p + m] = (l - r) * zetapow;\n                }\n     \
    \           zetapow = zetapow * zeta;\n            }\n        }\n    }\n\n   \
    \ // the inverse of above function\n    void intt(mints& f) const {\n        int\
    \ n = f.size();\n\n        for (int m = 1; m <= (n >> 1); m <<= 1) {\n       \
    \     auto zeta = zetas[clog2(m) + 1].inv();\n            mint zetapow(1);\n\n\
    \            for (int p = 0; p < m; ++p) {\n                for (int s = 0; s\
    \ < n; s += (m << 1)) {\n                    auto l = f[s + p],\n            \
    \             r = f[s + p + m] * zetapow;\n\n                    f[s + p] = l\
    \ + r;\n                    f[s + p + m] = l - r;\n                }\n       \
    \         zetapow = zetapow * zeta;\n            }\n        }\n\n        auto\
    \ ninv = mint(n).inv();\n        for (auto& x : f) x *= ninv;\n    }\n\n    mints\
    \ convolute(mints f, mints g) const {\n        int fsz = f.size(),\n         \
    \   gsz = g.size();\n\n        // simple convolution in small cases\n        if\
    \ (std::min(fsz, gsz) < 8) {\n            mints ret(fsz + gsz - 1, 0);\n     \
    \       for (int i = 0; i < fsz; ++i) {\n                for (int j = 0; j < gsz;\
    \ ++j) {\n                    ret[i + j] += f[i] * g[j];\n                }\n\
    \            }\n            return ret;\n        }\n\n        int n = 1 << clog2(fsz\
    \ + gsz - 1);\n        f.resize(n, mint(0));\n        g.resize(n, mint(0));\n\n\
    \        ntt(f);\n        ntt(g);\n\n        for (int i = 0; i < n; ++i) f[i]\
    \ *= g[i];\n\n        intt(f);\n\n        f.resize(fsz + gsz - 1);\n        return\
    \ f;\n    }\n};\n"
  code: "#pragma once\n\n#include \"../Number/modint.hpp\"\n\n#include <vector>\n\n\
    template <int MOD, int Root>\nstruct NumberTheoreticalTransform {\n    using mint\
    \ = ModInt<MOD>;\n    using mints = std::vector<mint>;\n\n    // the 2^k-th root\
    \ of 1\n    std::vector<mint> zetas;\n\n    explicit NumberTheoreticalTransform()\
    \ {\n        int exp = MOD - 1;\n        while (true) {\n            mint zeta\
    \ = mint(Root).pow(exp);\n            zetas.push_back(zeta);\n            if (exp\
    \ & 1) break;\n            exp /= 2;\n        }\n    }\n\n    // ceil(log_2 n)\n\
    \    static int clog2(int n) {\n        int k = 0;\n        while ((1 << k) <\
    \ n) ++k;\n        return k;\n    }\n\n    // 2-radix cooley-tukey algorithm without\
    \ bit reverse\n    // the size of f must be a power of 2\n    void ntt(mints&\
    \ f) const {\n        int n = f.size();\n\n        for (int m = n >> 1; m >= 1;\
    \ m >>= 1) {\n            auto zeta = zetas[clog2(m) + 1];\n            mint zetapow(1);\n\
    \n            for (int p = 0; p < m; ++p) {\n                for (int s = 0; s\
    \ < n; s += (m << 1)) {\n                    auto l = f[s + p],\n            \
    \             r = f[s + p + m];\n\n                    f[s + p] = l + r;\n   \
    \                 f[s + p + m] = (l - r) * zetapow;\n                }\n     \
    \           zetapow = zetapow * zeta;\n            }\n        }\n    }\n\n   \
    \ // the inverse of above function\n    void intt(mints& f) const {\n        int\
    \ n = f.size();\n\n        for (int m = 1; m <= (n >> 1); m <<= 1) {\n       \
    \     auto zeta = zetas[clog2(m) + 1].inv();\n            mint zetapow(1);\n\n\
    \            for (int p = 0; p < m; ++p) {\n                for (int s = 0; s\
    \ < n; s += (m << 1)) {\n                    auto l = f[s + p],\n            \
    \             r = f[s + p + m] * zetapow;\n\n                    f[s + p] = l\
    \ + r;\n                    f[s + p + m] = l - r;\n                }\n       \
    \         zetapow = zetapow * zeta;\n            }\n        }\n\n        auto\
    \ ninv = mint(n).inv();\n        for (auto& x : f) x *= ninv;\n    }\n\n    mints\
    \ convolute(mints f, mints g) const {\n        int fsz = f.size(),\n         \
    \   gsz = g.size();\n\n        // simple convolution in small cases\n        if\
    \ (std::min(fsz, gsz) < 8) {\n            mints ret(fsz + gsz - 1, 0);\n     \
    \       for (int i = 0; i < fsz; ++i) {\n                for (int j = 0; j < gsz;\
    \ ++j) {\n                    ret[i + j] += f[i] * g[j];\n                }\n\
    \            }\n            return ret;\n        }\n\n        int n = 1 << clog2(fsz\
    \ + gsz - 1);\n        f.resize(n, mint(0));\n        g.resize(n, mint(0));\n\n\
    \        ntt(f);\n        ntt(g);\n\n        for (int i = 0; i < n; ++i) f[i]\
    \ *= g[i];\n\n        intt(f);\n\n        f.resize(fsz + gsz - 1);\n        return\
    \ f;\n    }\n};\n"
  dependsOn:
  - Number/modint.hpp
  isVerificationFile: false
  path: Convolution/number_theoretical_transform.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:07:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/number_theoretical_transform.test.cpp
documentation_of: Convolution/number_theoretical_transform.hpp
layout: document
redirect_from:
- /library/Convolution/number_theoretical_transform.hpp
- /library/Convolution/number_theoretical_transform.hpp.html
title: Convolution/number_theoretical_transform.hpp
---
