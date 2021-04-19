---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/z_algorithm.hpp
    title: String/z_algorithm.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"Verify/z_algorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n#line 2 \"String/z_algorithm.hpp\"\n\n#include <vector>\n\ntemplate <class\
    \ Container>\nstd::vector<int> zalgo(const Container& dat) {\n    int n = dat.size();\n\
    \n    std::vector<int> ret(n);\n    ret[0] = n;\n\n    int i = 1, len = 0;\n \
    \   while (i < n) {\n        while (i + len < n && dat[len] == dat[i + len]) {\n\
    \            ++len;\n        }\n        ret[i] = len;\n\n        if (len == 0)\
    \ {\n            ++i;\n            continue;\n        }\n\n        int nlen =\
    \ 1;\n        while (i + nlen < n && nlen + ret[nlen] < len) {\n            ret[i\
    \ + nlen] = ret[nlen];\n            ++nlen;\n        }\n\n        i += nlen;\n\
    \        len -= nlen;\n    }\n\n    return ret;\n}\n#line 4 \"Verify/z_algorithm.test.cpp\"\
    \n\n#include <iostream>\n#include <string>\n\nint main() {\n    std::cin.tie();\n\
    \    std::ios::sync_with_stdio(false);\n\n    std::string s;\n    std::cin >>\
    \ s;\n\n    auto ans = zalgo(s);\n    for (auto a : ans) std::cout << a << \"\
    \ \";\n    std::cout << \"\\n\";\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ \"../String/z_algorithm.hpp\"\n\n#include <iostream>\n#include <string>\n\n\
    int main() {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n \
    \   std::string s;\n    std::cin >> s;\n\n    auto ans = zalgo(s);\n    for (auto\
    \ a : ans) std::cout << a << \" \";\n    std::cout << \"\\n\";\n\n    return 0;\n\
    }\n"
  dependsOn:
  - String/z_algorithm.hpp
  isVerificationFile: true
  path: Verify/z_algorithm.test.cpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/z_algorithm.test.cpp
layout: document
redirect_from:
- /verify/Verify/z_algorithm.test.cpp
- /verify/Verify/z_algorithm.test.cpp.html
title: Verify/z_algorithm.test.cpp
---
