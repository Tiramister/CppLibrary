---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Number/fixed_linear_algebra.hpp\"\n#include <array>\n\n\
    template <class T, int D>\nstruct Vector {\n    using V = std::array<T, D>;\n\n\
    \    V vec;\n\n    // constructor\n    Vector(T val = 0) { vec.fill(val); }\n\n\
    \    // getter\n    T& operator[](int i) { return vec[i]; }\n    T operator[](int\
    \ i) const { return vec[i]; }\n    typename V::iterator begin() { return vec.begin();\
    \ }\n    typename V::iterator end() { return vec.end(); }\n\n    // arithmetic\n\
    \    Vector operator+(const Vector& v) const { return Vector(*this) += v; }\n\
    \    Vector operator-(const Vector& v) const { return Vector(*this) -= v; }\n\
    \    T operator*(const Vector& v) const {\n        T ret(0);\n        for (int\
    \ i = 0; i < D; ++i) ret += vec[i] * v[i];\n        return ret;\n    }\n\n   \
    \ // compound assignment\n    Vector& operator+=(const Vector& v) {\n        for\
    \ (int i = 0; i < D; ++i) vec[i] += v[i];\n        return *this;\n    }\n    Vector&\
    \ operator-=(const Vector& v) {\n        for (int i = 0; i < D; ++i) vec[i] -=\
    \ v[i];\n        return *this;\n    }\n};\n\ntemplate <class T, int D>\nstruct\
    \ Matrix {\n    using M = std::array<std::array<T, D>, D>;\n\n    M mat;\n\n \
    \   // constructor\n    Matrix(T val = 0) {\n        for (auto& v : mat) v.fill(val);\n\
    \    }\n\n    static Matrix id() {\n        Matrix m;\n        for (int i = 0;\
    \ i < D; ++i) m[i][i] = 1;\n        return m;\n    }\n\n    // getter\n    std::array<T,\
    \ D>& operator[](int i) { return mat[i]; }\n    std::array<T, D> operator[](int\
    \ i) const { return mat[i]; }\n    typename M::iterator begin() { return mat.begin();\
    \ }\n    typename M::iterator end() { return mat.end(); }\n\n    // arithmetic\n\
    \    Matrix operator+(const Matrix& m) const { return Matrix(*this) += m; }\n\
    \    Matrix operator-(const Matrix& m) const { return Matrix(*this) -= m; }\n\
    \    Matrix operator*(const Matrix& m) const { return Matrix(*this) *= m; }\n\n\
    \    template <class U>\n    Matrix pow(U k) {\n        Matrix ret = id();\n \
    \       Matrix a = *this;\n\n        while (k > 0) {\n            if (k & 1) ret\
    \ *= a;\n            a *= a;\n            k >>= 1;\n        }\n        return\
    \ ret;\n    }\n\n    // compound assignment\n    Matrix& operator+=(const Matrix&\
    \ m) {\n        for (int i = 0; i < D; ++i) {\n            for (int j = 0; j <\
    \ D; ++j) {\n                mat[i][j] += m[i][j];\n            }\n        }\n\
    \        return *this;\n    }\n    Matrix& operator-=(const Matrix& m) {\n   \
    \     for (int i = 0; i < D; ++i) {\n            for (int j = 0; j < D; ++j) {\n\
    \                mat[i][j] -= m[i][j];\n            }\n        }\n        return\
    \ *this;\n    }\n    Matrix& operator*=(const Matrix& m) {\n        M nmat;\n\
    \        for (auto& v : nmat) v.fill(0);\n\n        for (int i = 0; i < D; ++i)\
    \ {\n            for (int j = 0; j < D; ++j) {\n                for (int k = 0;\
    \ k < D; ++k) {\n                    nmat[i][j] += mat[i][k] * m[k][j];\n    \
    \            }\n            }\n        }\n        mat = nmat;\n        return\
    \ *this;\n    }\n\n    // arithmetic with vector\n    using Vec = Vector<T, D>;\n\
    \    Vec operator*(const Vec& v) {\n        Vec ret;\n        for (int i = 0;\
    \ i < D; ++i) {\n            for (int j = 0; j < D; ++j) {\n                ret[i]\
    \ += mat[i][j] * v[j];\n            }\n        }\n        return ret;\n    }\n\
    };\n"
  code: "#include <array>\n\ntemplate <class T, int D>\nstruct Vector {\n    using\
    \ V = std::array<T, D>;\n\n    V vec;\n\n    // constructor\n    Vector(T val\
    \ = 0) { vec.fill(val); }\n\n    // getter\n    T& operator[](int i) { return\
    \ vec[i]; }\n    T operator[](int i) const { return vec[i]; }\n    typename V::iterator\
    \ begin() { return vec.begin(); }\n    typename V::iterator end() { return vec.end();\
    \ }\n\n    // arithmetic\n    Vector operator+(const Vector& v) const { return\
    \ Vector(*this) += v; }\n    Vector operator-(const Vector& v) const { return\
    \ Vector(*this) -= v; }\n    T operator*(const Vector& v) const {\n        T ret(0);\n\
    \        for (int i = 0; i < D; ++i) ret += vec[i] * v[i];\n        return ret;\n\
    \    }\n\n    // compound assignment\n    Vector& operator+=(const Vector& v)\
    \ {\n        for (int i = 0; i < D; ++i) vec[i] += v[i];\n        return *this;\n\
    \    }\n    Vector& operator-=(const Vector& v) {\n        for (int i = 0; i <\
    \ D; ++i) vec[i] -= v[i];\n        return *this;\n    }\n};\n\ntemplate <class\
    \ T, int D>\nstruct Matrix {\n    using M = std::array<std::array<T, D>, D>;\n\
    \n    M mat;\n\n    // constructor\n    Matrix(T val = 0) {\n        for (auto&\
    \ v : mat) v.fill(val);\n    }\n\n    static Matrix id() {\n        Matrix m;\n\
    \        for (int i = 0; i < D; ++i) m[i][i] = 1;\n        return m;\n    }\n\n\
    \    // getter\n    std::array<T, D>& operator[](int i) { return mat[i]; }\n \
    \   std::array<T, D> operator[](int i) const { return mat[i]; }\n    typename\
    \ M::iterator begin() { return mat.begin(); }\n    typename M::iterator end()\
    \ { return mat.end(); }\n\n    // arithmetic\n    Matrix operator+(const Matrix&\
    \ m) const { return Matrix(*this) += m; }\n    Matrix operator-(const Matrix&\
    \ m) const { return Matrix(*this) -= m; }\n    Matrix operator*(const Matrix&\
    \ m) const { return Matrix(*this) *= m; }\n\n    template <class U>\n    Matrix\
    \ pow(U k) {\n        Matrix ret = id();\n        Matrix a = *this;\n\n      \
    \  while (k > 0) {\n            if (k & 1) ret *= a;\n            a *= a;\n  \
    \          k >>= 1;\n        }\n        return ret;\n    }\n\n    // compound\
    \ assignment\n    Matrix& operator+=(const Matrix& m) {\n        for (int i =\
    \ 0; i < D; ++i) {\n            for (int j = 0; j < D; ++j) {\n              \
    \  mat[i][j] += m[i][j];\n            }\n        }\n        return *this;\n  \
    \  }\n    Matrix& operator-=(const Matrix& m) {\n        for (int i = 0; i < D;\
    \ ++i) {\n            for (int j = 0; j < D; ++j) {\n                mat[i][j]\
    \ -= m[i][j];\n            }\n        }\n        return *this;\n    }\n    Matrix&\
    \ operator*=(const Matrix& m) {\n        M nmat;\n        for (auto& v : nmat)\
    \ v.fill(0);\n\n        for (int i = 0; i < D; ++i) {\n            for (int j\
    \ = 0; j < D; ++j) {\n                for (int k = 0; k < D; ++k) {\n        \
    \            nmat[i][j] += mat[i][k] * m[k][j];\n                }\n         \
    \   }\n        }\n        mat = nmat;\n        return *this;\n    }\n\n    //\
    \ arithmetic with vector\n    using Vec = Vector<T, D>;\n    Vec operator*(const\
    \ Vec& v) {\n        Vec ret;\n        for (int i = 0; i < D; ++i) {\n       \
    \     for (int j = 0; j < D; ++j) {\n                ret[i] += mat[i][j] * v[j];\n\
    \            }\n        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Number/fixed_linear_algebra.hpp
  requiredBy: []
  timestamp: '2020-08-25 16:53:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Number/fixed_linear_algebra.hpp
layout: document
redirect_from:
- /library/Number/fixed_linear_algebra.hpp
- /library/Number/fixed_linear_algebra.hpp.html
title: Number/fixed_linear_algebra.hpp
---
