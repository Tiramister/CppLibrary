---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: String/knuth_morris_pratt.hpp
    title: String/knuth_morris_pratt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B
  bundledCode: "#line 1 \"Verify/knuth_morris_pratt.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B\"\n\n#line\
    \ 2 \"String/knuth_morris_pratt.hpp\"\n\n#include <vector>\n\ntemplate <class\
    \ Container>\nstruct PatternMatching {\n    Container pat;\n    std::vector<int>\
    \ fail;\n\n    explicit PatternMatching(const Container& pat) : pat(pat) {\n \
    \       fail.resize(pat.size() + 1, -1);\n\n        int fpos = -1;\n        for\
    \ (int pos = 0; pos < (int)pat.size(); ++pos) {\n            if (fpos >= 0 &&\
    \ pat[pos] == pat[fpos]) fail[pos] = fail[fpos];\n\n            while (fpos >=\
    \ 0 && pat[pos] != pat[fpos]) {\n                fpos = fail[fpos];\n        \
    \    }\n            fail[pos + 1] = ++fpos;\n        }\n    }\n\n    std::vector<int>\
    \ find(const Container& s) {\n        std::vector<int> ret;\n        int pos =\
    \ 0;\n        for (int i = 0; i < (int)s.size(); ++i) {\n            while (pos\
    \ >= 0 && pat[pos] != s[i]) {\n                pos = fail[pos];\n            }\n\
    \            if (++pos == (int)pat.size()) {\n                ret.push_back(i\
    \ - (int)pat.size() + 1);\n                pos = fail[pos];\n            }\n \
    \       }\n        return ret;\n    }\n};\n#line 4 \"Verify/knuth_morris_pratt.test.cpp\"\
    \n\n#include <iostream>\n#include <string>\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n\n    std::string s, p;\n    std::cin\
    \ >> s >> p;\n\n    PatternMatching pm(p);\n    for (auto i : pm.find(s)) std::cout\
    \ << i << \"\\n\";\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B\"\
    \n\n#include \"../String/knuth_morris_pratt.hpp\"\n\n#include <iostream>\n#include\
    \ <string>\n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \n    std::string s, p;\n    std::cin >> s >> p;\n\n    PatternMatching pm(p);\n\
    \    for (auto i : pm.find(s)) std::cout << i << \"\\n\";\n\n    return 0;\n}\n"
  dependsOn:
  - String/knuth_morris_pratt.hpp
  isVerificationFile: true
  path: Verify/knuth_morris_pratt.test.cpp
  requiredBy: []
  timestamp: '2020-08-28 20:17:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/knuth_morris_pratt.test.cpp
layout: document
redirect_from:
- /verify/Verify/knuth_morris_pratt.test.cpp
- /verify/Verify/knuth_morris_pratt.test.cpp.html
title: Verify/knuth_morris_pratt.test.cpp
---
