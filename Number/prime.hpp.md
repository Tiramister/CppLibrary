---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/factorize.test.cpp
    title: Verify/factorize.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Number/prime.hpp\"\n\n#include <vector>\n\nstruct Prime\
    \ {\n    int max_n;\n    std::vector<int> primes;\n    std::vector<bool> isp;\n\
    \n    explicit Prime(int max_n)\n        : max_n(max_n), isp(max_n + 1, true)\
    \ {\n        isp[0] = isp[1] = false;\n        for (int i = 2; i * i <= max_n;\
    \ ++i) {\n            if (isp[i]) {\n                for (int j = i; i * j <=\
    \ max_n; ++j) {\n                    isp[i * j] = false;\n                }\n\
    \            }\n        }\n\n        for (int p = 2; p <= max_n; ++p) {\n    \
    \        if (isp[p]) primes.push_back(p);\n        }\n    }\n\n    template <class\
    \ T>\n    bool isprime(T n) const {\n        if (n <= max_n) return isp[n];\n\
    \        for (T p : primes) {\n            if (p * p > n) break;\n           \
    \ if (n % p == 0) return false;\n        }\n        return true;\n    }\n\n  \
    \  template <class T>\n    std::vector<std::pair<T, int>> factorize(T n) const\
    \ {\n        std::vector<std::pair<T, int>> facts;\n        for (T p : primes)\
    \ {\n            if (p * p > n) break;\n            if (n % p != 0) continue;\n\
    \            int exp = 0;\n            while (n % p == 0) {\n                n\
    \ /= p;\n                ++exp;\n            }\n            facts.emplace_back(p,\
    \ exp);\n        }\n        if (n > 1) {\n            facts.emplace_back(n, 1);\n\
    \        }\n        return facts;\n    }\n\n    template <class T>\n    static\
    \ std::vector<T> divisors(T n) {\n        std::vector<T> ret;\n        for (T\
    \ p = 1; p * p <= n; ++p) {\n            if (n % p != 0) continue;\n         \
    \   ret.push_back(p);\n            if (n / p == p) continue;\n            ret.push_back(n\
    \ / p);\n        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\nstruct Prime {\n    int max_n;\n   \
    \ std::vector<int> primes;\n    std::vector<bool> isp;\n\n    explicit Prime(int\
    \ max_n)\n        : max_n(max_n), isp(max_n + 1, true) {\n        isp[0] = isp[1]\
    \ = false;\n        for (int i = 2; i * i <= max_n; ++i) {\n            if (isp[i])\
    \ {\n                for (int j = i; i * j <= max_n; ++j) {\n                \
    \    isp[i * j] = false;\n                }\n            }\n        }\n\n    \
    \    for (int p = 2; p <= max_n; ++p) {\n            if (isp[p]) primes.push_back(p);\n\
    \        }\n    }\n\n    template <class T>\n    bool isprime(T n) const {\n \
    \       if (n <= max_n) return isp[n];\n        for (T p : primes) {\n       \
    \     if (p * p > n) break;\n            if (n % p == 0) return false;\n     \
    \   }\n        return true;\n    }\n\n    template <class T>\n    std::vector<std::pair<T,\
    \ int>> factorize(T n) const {\n        std::vector<std::pair<T, int>> facts;\n\
    \        for (T p : primes) {\n            if (p * p > n) break;\n           \
    \ if (n % p != 0) continue;\n            int exp = 0;\n            while (n %\
    \ p == 0) {\n                n /= p;\n                ++exp;\n            }\n\
    \            facts.emplace_back(p, exp);\n        }\n        if (n > 1) {\n  \
    \          facts.emplace_back(n, 1);\n        }\n        return facts;\n    }\n\
    \n    template <class T>\n    static std::vector<T> divisors(T n) {\n        std::vector<T>\
    \ ret;\n        for (T p = 1; p * p <= n; ++p) {\n            if (n % p != 0)\
    \ continue;\n            ret.push_back(p);\n            if (n / p == p) continue;\n\
    \            ret.push_back(n / p);\n        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Number/prime.hpp
  requiredBy: []
  timestamp: '2020-08-25 16:54:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/factorize.test.cpp
documentation_of: Number/prime.hpp
layout: document
redirect_from:
- /library/Number/prime.hpp
- /library/Number/prime.hpp.html
title: Number/prime.hpp
---
