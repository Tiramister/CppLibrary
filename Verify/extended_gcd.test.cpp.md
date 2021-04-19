---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Number/extended_gcd.hpp
    title: Number/extended_gcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E
  bundledCode: "#line 1 \"Verify/extended_gcd.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E\"\
    \n\n#line 2 \"Number/extended_gcd.hpp\"\n\n#include <algorithm>\n\ntemplate <typename\
    \ T>\nT extgcd(T a, T b, T& x, T& y) {\n    T s = a, t = b,\n      xs = 1, ys\
    \ = 0,\n      xt = 0, yt = 1;\n\n    while (t != 0) {\n        T div = s / t;\n\
    \n        s -= t * div;\n        xs -= xt * div;\n        ys -= yt * div;\n\n\
    \        std::swap(s, t);\n        std::swap(xs, xt);\n        std::swap(ys, yt);\n\
    \    }\n\n    x = xs;\n    y = ys;\n    return s;\n}\n#line 4 \"Verify/extended_gcd.test.cpp\"\
    \n\n#include <iostream>\n#include <cassert>\n\nint main() {\n    std::cin.tie();\n\
    \    std::ios::sync_with_stdio(false);\n\n    int a, b;\n    std::cin >> a >>\
    \ b;\n\n    int x, y;\n    int g = extgcd(a, b, x, y);\n    assert(a * x + b *\
    \ y == g);\n\n    std::cout << x << \" \" << y << \"\\n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E\"\
    \n\n#include \"../Number/extended_gcd.hpp\"\n\n#include <iostream>\n#include <cassert>\n\
    \nint main() {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n\
    \    int a, b;\n    std::cin >> a >> b;\n\n    int x, y;\n    int g = extgcd(a,\
    \ b, x, y);\n    assert(a * x + b * y == g);\n\n    std::cout << x << \" \" <<\
    \ y << \"\\n\";\n    return 0;\n}\n"
  dependsOn:
  - Number/extended_gcd.hpp
  isVerificationFile: true
  path: Verify/extended_gcd.test.cpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/extended_gcd.test.cpp
layout: document
redirect_from:
- /verify/Verify/extended_gcd.test.cpp
- /verify/Verify/extended_gcd.test.cpp.html
title: Verify/extended_gcd.test.cpp
---
