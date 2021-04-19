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
  bundledCode: "#line 2 \"Tools/run_length.hpp\"\n\n#include <vector>\n#include <string>\n\
    \ntemplate <class It>\nstd::vector<std::pair<typename It::value_type, int>> runlength(\n\
    \    It begin, It end) {\n    using T = typename It::value_type;\n\n    std::vector<std::pair<T,\
    \ int>> res;\n    while (begin != end) {\n        const T& c = *(begin++);\n \
    \       if (res.empty() || c != res.back().first) {\n            res.emplace_back(c,\
    \ 1);\n        } else {\n            ++res.back().second;\n        }\n    }\n\n\
    \    return res;\n}\n"
  code: "#pragma once\n\n#include <vector>\n#include <string>\n\ntemplate <class It>\n\
    std::vector<std::pair<typename It::value_type, int>> runlength(\n    It begin,\
    \ It end) {\n    using T = typename It::value_type;\n\n    std::vector<std::pair<T,\
    \ int>> res;\n    while (begin != end) {\n        const T& c = *(begin++);\n \
    \       if (res.empty() || c != res.back().first) {\n            res.emplace_back(c,\
    \ 1);\n        } else {\n            ++res.back().second;\n        }\n    }\n\n\
    \    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Tools/run_length.hpp
  requiredBy: []
  timestamp: '2020-07-27 20:19:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Tools/run_length.hpp
layout: document
redirect_from:
- /library/Tools/run_length.hpp
- /library/Tools/run_length.hpp.html
title: Tools/run_length.hpp
---
