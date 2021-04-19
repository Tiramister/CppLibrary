---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/knuth_morris_pratt.test.cpp
    title: Verify/knuth_morris_pratt.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"String/knuth_morris_pratt.hpp\"\n\n#include <vector>\n\n\
    template <class Container>\nstruct PatternMatching {\n    Container pat;\n   \
    \ std::vector<int> fail;\n\n    explicit PatternMatching(const Container& pat)\
    \ : pat(pat) {\n        fail.resize(pat.size() + 1, -1);\n\n        int fpos =\
    \ -1;\n        for (int pos = 0; pos < (int)pat.size(); ++pos) {\n           \
    \ if (fpos >= 0 && pat[pos] == pat[fpos]) fail[pos] = fail[fpos];\n\n        \
    \    while (fpos >= 0 && pat[pos] != pat[fpos]) {\n                fpos = fail[fpos];\n\
    \            }\n            fail[pos + 1] = ++fpos;\n        }\n    }\n\n    std::vector<int>\
    \ find(const Container& s) {\n        std::vector<int> ret;\n        int pos =\
    \ 0;\n        for (int i = 0; i < (int)s.size(); ++i) {\n            while (pos\
    \ >= 0 && pat[pos] != s[i]) {\n                pos = fail[pos];\n            }\n\
    \            if (++pos == (int)pat.size()) {\n                ret.push_back(i\
    \ - (int)pat.size() + 1);\n                pos = fail[pos];\n            }\n \
    \       }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate <class Container>\nstruct PatternMatching\
    \ {\n    Container pat;\n    std::vector<int> fail;\n\n    explicit PatternMatching(const\
    \ Container& pat) : pat(pat) {\n        fail.resize(pat.size() + 1, -1);\n\n \
    \       int fpos = -1;\n        for (int pos = 0; pos < (int)pat.size(); ++pos)\
    \ {\n            if (fpos >= 0 && pat[pos] == pat[fpos]) fail[pos] = fail[fpos];\n\
    \n            while (fpos >= 0 && pat[pos] != pat[fpos]) {\n                fpos\
    \ = fail[fpos];\n            }\n            fail[pos + 1] = ++fpos;\n        }\n\
    \    }\n\n    std::vector<int> find(const Container& s) {\n        std::vector<int>\
    \ ret;\n        int pos = 0;\n        for (int i = 0; i < (int)s.size(); ++i)\
    \ {\n            while (pos >= 0 && pat[pos] != s[i]) {\n                pos =\
    \ fail[pos];\n            }\n            if (++pos == (int)pat.size()) {\n   \
    \             ret.push_back(i - (int)pat.size() + 1);\n                pos = fail[pos];\n\
    \            }\n        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: String/knuth_morris_pratt.hpp
  requiredBy: []
  timestamp: '2020-08-28 20:13:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/knuth_morris_pratt.test.cpp
documentation_of: String/knuth_morris_pratt.hpp
layout: document
redirect_from:
- /library/String/knuth_morris_pratt.hpp
- /library/String/knuth_morris_pratt.hpp.html
title: String/knuth_morris_pratt.hpp
---
