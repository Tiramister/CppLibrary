---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/matrix_pow.test.cpp
    title: Verify/matrix_pow.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Number/matrix.hpp\"\n\n#include <vector>\n\ntemplate <class\
    \ T>\nstruct Matrix : public std::vector<std::vector<T>> {\n    // constructor\n\
    \    using std::vector<std::vector<T>>::vector;\n\n    Matrix(int h, int w, T\
    \ val = 0) {\n        this->resize(h);\n        for (auto& v : *this) v.resize(w,\
    \ val);\n    }\n\n    static Matrix id(int n) {\n        Matrix m(n, n);\n   \
    \     for (int i = 0; i < n; ++i) m[i][i] = 1;\n        return m;\n    }\n\n \
    \   // arithmetic\n    Matrix operator*(const Matrix& m) const { return Matrix(*this)\
    \ *= m; }\n    Matrix& operator*=(const Matrix& m) {\n        int h1 = this->size(),\n\
    \            h2 = m.size(),\n            w2 = m.front().size();\n\n        Matrix\
    \ nmat(h1, w2);\n        for (int i = 0; i < h1; ++i) {\n            for (int\
    \ j = 0; j < w2; ++j) {\n                for (int k = 0; k < h2; ++k) {\n    \
    \                nmat[i][j] += (*this)[i][k] * m[k][j];\n                }\n \
    \           }\n        }\n        return *this = nmat;\n    }\n\n    template\
    \ <class U>\n    Matrix pow(U k) {\n        Matrix ret = id(this->size());\n \
    \       Matrix a = *this;\n\n        while (k > 0) {\n            if (k & 1) ret\
    \ *= a;\n            a *= a;\n            k >>= 1;\n        }\n        return\
    \ ret;\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate <class T>\nstruct Matrix :\
    \ public std::vector<std::vector<T>> {\n    // constructor\n    using std::vector<std::vector<T>>::vector;\n\
    \n    Matrix(int h, int w, T val = 0) {\n        this->resize(h);\n        for\
    \ (auto& v : *this) v.resize(w, val);\n    }\n\n    static Matrix id(int n) {\n\
    \        Matrix m(n, n);\n        for (int i = 0; i < n; ++i) m[i][i] = 1;\n \
    \       return m;\n    }\n\n    // arithmetic\n    Matrix operator*(const Matrix&\
    \ m) const { return Matrix(*this) *= m; }\n    Matrix& operator*=(const Matrix&\
    \ m) {\n        int h1 = this->size(),\n            h2 = m.size(),\n         \
    \   w2 = m.front().size();\n\n        Matrix nmat(h1, w2);\n        for (int i\
    \ = 0; i < h1; ++i) {\n            for (int j = 0; j < w2; ++j) {\n          \
    \      for (int k = 0; k < h2; ++k) {\n                    nmat[i][j] += (*this)[i][k]\
    \ * m[k][j];\n                }\n            }\n        }\n        return *this\
    \ = nmat;\n    }\n\n    template <class U>\n    Matrix pow(U k) {\n        Matrix\
    \ ret = id(this->size());\n        Matrix a = *this;\n\n        while (k > 0)\
    \ {\n            if (k & 1) ret *= a;\n            a *= a;\n            k >>=\
    \ 1;\n        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Number/matrix.hpp
  requiredBy: []
  timestamp: '2020-11-05 12:15:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/matrix_pow.test.cpp
documentation_of: Number/matrix.hpp
layout: document
redirect_from:
- /library/Number/matrix.hpp
- /library/Number/matrix.hpp.html
title: Number/matrix.hpp
---
