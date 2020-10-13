---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Geometry/type.cpp\"\n\n#include <cmath>\n\nusing Real =\
    \ long double;\nconstexpr Real EPS = 1e-10L;\nconstexpr Real PI = 3.14159265358979323846L;\n\
    \ntemplate <class T>\nT sq(T x) { return x * x; }\n\nint compare(Real a, Real\
    \ b) {\n    if (std::abs(a - b) < EPS) return 0;\n    return a - b > 0 ? 1 : -1;\n\
    }\n\nReal deg2rad(Real theta) { return theta / 180 * PI; }\nReal rad2deg(Real\
    \ theta) { return theta / PI * 180; }\n"
  code: "#pragma once\n\n#include <cmath>\n\nusing Real = long double;\nconstexpr\
    \ Real EPS = 1e-10L;\nconstexpr Real PI = 3.14159265358979323846L;\n\ntemplate\
    \ <class T>\nT sq(T x) { return x * x; }\n\nint compare(Real a, Real b) {\n  \
    \  if (std::abs(a - b) < EPS) return 0;\n    return a - b > 0 ? 1 : -1;\n}\n\n\
    Real deg2rad(Real theta) { return theta / 180 * PI; }\nReal rad2deg(Real theta)\
    \ { return theta / PI * 180; }\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/type.cpp
  requiredBy: []
  timestamp: '2020-04-21 00:48:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/type.cpp
layout: document
redirect_from:
- /library/Geometry/type.cpp
- /library/Geometry/type.cpp.html
title: Geometry/type.cpp
---
