---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Number/gcd.hpp
    title: Number/gcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B
  bundledCode: "#line 1 \"Verify/gcd.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B\"\
    \n\n#line 2 \"Number/gcd.hpp\"\n\n#include <algorithm>\n\ntemplate <class T>\n\
    T gcd(T n, T m) {\n    while (m != 0) {\n        n %= m;\n        std::swap(n,\
    \ m);\n    }\n    return n;\n}\n#line 4 \"Verify/gcd.test.cpp\"\n\n#include <iostream>\n\
    \nint main() {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n\
    \    int x, y;\n    std::cin >> x >> y;\n    std::cout << gcd(x, y) << \"\\n\"\
    ;\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B\"\
    \n\n#include \"../Number/gcd.hpp\"\n\n#include <iostream>\n\nint main() {\n  \
    \  std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n    int x, y;\n \
    \   std::cin >> x >> y;\n    std::cout << gcd(x, y) << \"\\n\";\n\n    return\
    \ 0;\n}\n"
  dependsOn:
  - Number/gcd.hpp
  isVerificationFile: true
  path: Verify/gcd.test.cpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/gcd.test.cpp
layout: document
redirect_from:
- /verify/Verify/gcd.test.cpp
- /verify/Verify/gcd.test.cpp.html
title: Verify/gcd.test.cpp
---
