---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/fixed_matrix_pow.test.cpp
    title: Verify/fixed_matrix_pow.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Number/fixed_matrix.hpp\"\n\n#include <array>\n\ntemplate\
    \ <class T, int D>\nstruct Matrix : public std::array<std::array<T, D>, D> {\n\
    \    // constructor\n    Matrix(T val = 0) {\n        for (auto& v : *this) v.fill(val);\n\
    \    }\n\n    static Matrix id() {\n        Matrix m;\n        for (int i = 0;\
    \ i < D; ++i) m[i][i] = 1;\n        return m;\n    }\n\n    // arithmetic\n  \
    \  Matrix operator*(const Matrix& m) const { return Matrix(*this) *= m; }\n  \
    \  Matrix& operator*=(const Matrix& m) {\n        Matrix nmat;\n        for (auto&\
    \ v : nmat) v.fill(0);\n\n        for (int i = 0; i < D; ++i) {\n            for\
    \ (int j = 0; j < D; ++j) {\n                for (int k = 0; k < D; ++k) {\n \
    \                   nmat[i][j] += (*this)[i][k] * m[k][j];\n                }\n\
    \            }\n        }\n        return *this = nmat;\n    }\n\n    template\
    \ <class U>\n    Matrix pow(U k) {\n        Matrix ret = id();\n        Matrix\
    \ a = *this;\n\n        while (k > 0) {\n            if (k & 1) ret *= a;\n  \
    \          a *= a;\n            k >>= 1;\n        }\n        return ret;\n   \
    \ }\n};\n"
  code: "#pragma once\n\n#include <array>\n\ntemplate <class T, int D>\nstruct Matrix\
    \ : public std::array<std::array<T, D>, D> {\n    // constructor\n    Matrix(T\
    \ val = 0) {\n        for (auto& v : *this) v.fill(val);\n    }\n\n    static\
    \ Matrix id() {\n        Matrix m;\n        for (int i = 0; i < D; ++i) m[i][i]\
    \ = 1;\n        return m;\n    }\n\n    // arithmetic\n    Matrix operator*(const\
    \ Matrix& m) const { return Matrix(*this) *= m; }\n    Matrix& operator*=(const\
    \ Matrix& m) {\n        Matrix nmat;\n        for (auto& v : nmat) v.fill(0);\n\
    \n        for (int i = 0; i < D; ++i) {\n            for (int j = 0; j < D; ++j)\
    \ {\n                for (int k = 0; k < D; ++k) {\n                    nmat[i][j]\
    \ += (*this)[i][k] * m[k][j];\n                }\n            }\n        }\n \
    \       return *this = nmat;\n    }\n\n    template <class U>\n    Matrix pow(U\
    \ k) {\n        Matrix ret = id();\n        Matrix a = *this;\n\n        while\
    \ (k > 0) {\n            if (k & 1) ret *= a;\n            a *= a;\n         \
    \   k >>= 1;\n        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Number/fixed_matrix.hpp
  requiredBy: []
  timestamp: '2020-11-03 12:02:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/fixed_matrix_pow.test.cpp
documentation_of: Number/fixed_matrix.hpp
layout: document
redirect_from:
- /library/Number/fixed_matrix.hpp
- /library/Number/fixed_matrix.hpp.html
title: Number/fixed_matrix.hpp
---
