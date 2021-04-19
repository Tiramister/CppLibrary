---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Tools/random.hpp\"\n\n#include <chrono>\n\nstruct Random\
    \ {\n    using ulint = uint64_t;\n    ulint x;\n\n    explicit Random() {\n  \
    \      x = std::chrono::steady_clock::now()\n                .time_since_epoch()\n\
    \                .count();\n    }\n\n    ulint next() {\n        x ^= (x << 13);\n\
    \        x ^= (x >> 7);\n        x ^= (x << 17);\n        return x;\n    }\n};\n"
  code: "#pragma once\n\n#include <chrono>\n\nstruct Random {\n    using ulint = uint64_t;\n\
    \    ulint x;\n\n    explicit Random() {\n        x = std::chrono::steady_clock::now()\n\
    \                .time_since_epoch()\n                .count();\n    }\n\n   \
    \ ulint next() {\n        x ^= (x << 13);\n        x ^= (x >> 7);\n        x ^=\
    \ (x << 17);\n        return x;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Tools/random.hpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Tools/random.hpp
layout: document
redirect_from:
- /library/Tools/random.hpp
- /library/Tools/random.hpp.html
title: Tools/random.hpp
---
