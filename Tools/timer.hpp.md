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
  bundledCode: "#line 2 \"Tools/timer.hpp\"\n\n#include <chrono>\n\nstruct Timer {\n\
    \    std::chrono::time_point<std::chrono::system_clock> begin;\n\n    void init()\
    \ {\n        begin = std::chrono::system_clock::now();\n    }\n\n    int get_ms()\
    \ {\n        auto cur = std::chrono::system_clock::now();\n        return std::chrono::\n\
    \            duration_cast<std::chrono::milliseconds>(cur - begin)\n         \
    \       .count();\n    }\n};\n"
  code: "#pragma once\n\n#include <chrono>\n\nstruct Timer {\n    std::chrono::time_point<std::chrono::system_clock>\
    \ begin;\n\n    void init() {\n        begin = std::chrono::system_clock::now();\n\
    \    }\n\n    int get_ms() {\n        auto cur = std::chrono::system_clock::now();\n\
    \        return std::chrono::\n            duration_cast<std::chrono::milliseconds>(cur\
    \ - begin)\n                .count();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Tools/timer.hpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Tools/timer.hpp
layout: document
redirect_from:
- /library/Tools/timer.hpp
- /library/Tools/timer.hpp.html
title: Tools/timer.hpp
---
