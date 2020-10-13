---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Number/linear_algebra.hpp\"\n\n#include <vector>\n\ntemplate\
    \ <class T>\nstruct Vector {\n    using V = std::vector<T>;\n\n    int d;\n  \
    \  V vec;\n\n    // constructor\n    Vector(int d, T val = 0) : d(d), vec(d, val)\
    \ {}\n\n    // getter\n    T& operator[](int i) { return vec[i]; }\n    T operator[](int\
    \ i) const { return vec[i]; }\n    typename V::iterator begin() { return vec.begin();\
    \ }\n    typename V::iterator end() { return vec.end(); }\n\n    // arithmetic\n\
    \    Vector operator+(const Vector& v) const { return Vector(*this) += v; }\n\
    \    Vector operator-(const Vector& v) const { return Vector(*this) -= v; }\n\
    \    T operator*(const Vector& v) const {\n        T ret(0);\n        for (int\
    \ i = 0; i < d; ++i) ret += vec[i] * v[i];\n        return ret;\n    }\n\n   \
    \ // compound assignment\n    Vector& operator+=(const Vector& v) {\n        for\
    \ (int i = 0; i < d; ++i) vec[i] += v[i];\n        return *this;\n    }\n    Vector&\
    \ operator-=(const Vector& v) {\n        for (int i = 0; i < d; ++i) vec[i] -=\
    \ v[i];\n        return *this;\n    }\n};\n\ntemplate <class T>\nstruct Matrix\
    \ {\n    using M = std::vector<std::vector<T>>;\n\n    int h, w;\n    M mat;\n\
    \n    // constructor\n    Matrix(int h, int w, T val = 0)\n        : h(h), w(w),\
    \ mat(h, std::vector<T>(w, val)) {}\n\n    static Matrix id(int n) {\n       \
    \ Matrix m(n, n);\n        for (int i = 0; i < n; ++i) m[i][i] = 1;\n        return\
    \ m;\n    }\n\n    // getter\n    std::vector<T>& operator[](int i) { return mat[i];\
    \ }\n    std::vector<T> operator[](int i) const { return mat[i]; }\n    typename\
    \ M::iterator begin() { return mat.begin(); }\n    typename M::iterator end()\
    \ { return mat.end(); }\n\n    // arithmetic\n    Matrix operator+(const Matrix&\
    \ m) const { return Matrix(*this) += m; }\n    Matrix operator-(const Matrix&\
    \ m) const { return Matrix(*this) -= m; }\n    Matrix operator*(const Matrix&\
    \ m) const { return Matrix(*this) *= m; }\n\n    template <class U>\n    Matrix\
    \ pow(U k) {\n        Matrix ret = id(h);\n        Matrix a = *this;\n\n     \
    \   while (k > 0) {\n            if (k & 1) ret *= a;\n            a *= a;\n \
    \           k >>= 1;\n        }\n        return ret;\n    }\n\n    // compound\
    \ assignment\n    Matrix& operator+=(const Matrix& m) {\n        for (int i =\
    \ 0; i < h; ++i) {\n            for (int j = 0; j < w; ++j) {\n              \
    \  mat[i][j] += m[i][j];\n            }\n        }\n        return *this;\n  \
    \  }\n    Matrix& operator-=(const Matrix& m) {\n        for (int i = 0; i < h;\
    \ ++i) {\n            for (int j = 0; j < w; ++j) {\n                mat[i][j]\
    \ -= m[i][j];\n            }\n        }\n        return *this;\n    }\n    Matrix&\
    \ operator*=(const Matrix& m) {\n        std::vector<std::vector<T>> nmat(h, std::vector<T>(m.w,\
    \ T(0)));\n        for (int i = 0; i < h; ++i) {\n            for (int j = 0;\
    \ j < m.w; ++j) {\n                for (int k = 0; k < w; ++k) {\n           \
    \         nmat[i][j] += mat[i][k] * m[k][j];\n                }\n            }\n\
    \        }\n        mat = nmat;\n        return *this;\n    }\n\n    // arithmetic\
    \ with vector\n    using Vec = Vector<T>;\n    Vec operator*(const Vec& v) {\n\
    \        Vec ret(h, 0);\n        for (int i = 0; i < h; ++i) {\n            for\
    \ (int j = 0; j < w; ++j) {\n                ret[i] += mat[i][j] * v[j];\n   \
    \         }\n        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n\n#include <vector>\n\ntemplate <class T>\nstruct Vector {\n\
    \    using V = std::vector<T>;\n\n    int d;\n    V vec;\n\n    // constructor\n\
    \    Vector(int d, T val = 0) : d(d), vec(d, val) {}\n\n    // getter\n    T&\
    \ operator[](int i) { return vec[i]; }\n    T operator[](int i) const { return\
    \ vec[i]; }\n    typename V::iterator begin() { return vec.begin(); }\n    typename\
    \ V::iterator end() { return vec.end(); }\n\n    // arithmetic\n    Vector operator+(const\
    \ Vector& v) const { return Vector(*this) += v; }\n    Vector operator-(const\
    \ Vector& v) const { return Vector(*this) -= v; }\n    T operator*(const Vector&\
    \ v) const {\n        T ret(0);\n        for (int i = 0; i < d; ++i) ret += vec[i]\
    \ * v[i];\n        return ret;\n    }\n\n    // compound assignment\n    Vector&\
    \ operator+=(const Vector& v) {\n        for (int i = 0; i < d; ++i) vec[i] +=\
    \ v[i];\n        return *this;\n    }\n    Vector& operator-=(const Vector& v)\
    \ {\n        for (int i = 0; i < d; ++i) vec[i] -= v[i];\n        return *this;\n\
    \    }\n};\n\ntemplate <class T>\nstruct Matrix {\n    using M = std::vector<std::vector<T>>;\n\
    \n    int h, w;\n    M mat;\n\n    // constructor\n    Matrix(int h, int w, T\
    \ val = 0)\n        : h(h), w(w), mat(h, std::vector<T>(w, val)) {}\n\n    static\
    \ Matrix id(int n) {\n        Matrix m(n, n);\n        for (int i = 0; i < n;\
    \ ++i) m[i][i] = 1;\n        return m;\n    }\n\n    // getter\n    std::vector<T>&\
    \ operator[](int i) { return mat[i]; }\n    std::vector<T> operator[](int i) const\
    \ { return mat[i]; }\n    typename M::iterator begin() { return mat.begin(); }\n\
    \    typename M::iterator end() { return mat.end(); }\n\n    // arithmetic\n \
    \   Matrix operator+(const Matrix& m) const { return Matrix(*this) += m; }\n \
    \   Matrix operator-(const Matrix& m) const { return Matrix(*this) -= m; }\n \
    \   Matrix operator*(const Matrix& m) const { return Matrix(*this) *= m; }\n\n\
    \    template <class U>\n    Matrix pow(U k) {\n        Matrix ret = id(h);\n\
    \        Matrix a = *this;\n\n        while (k > 0) {\n            if (k & 1)\
    \ ret *= a;\n            a *= a;\n            k >>= 1;\n        }\n        return\
    \ ret;\n    }\n\n    // compound assignment\n    Matrix& operator+=(const Matrix&\
    \ m) {\n        for (int i = 0; i < h; ++i) {\n            for (int j = 0; j <\
    \ w; ++j) {\n                mat[i][j] += m[i][j];\n            }\n        }\n\
    \        return *this;\n    }\n    Matrix& operator-=(const Matrix& m) {\n   \
    \     for (int i = 0; i < h; ++i) {\n            for (int j = 0; j < w; ++j) {\n\
    \                mat[i][j] -= m[i][j];\n            }\n        }\n        return\
    \ *this;\n    }\n    Matrix& operator*=(const Matrix& m) {\n        std::vector<std::vector<T>>\
    \ nmat(h, std::vector<T>(m.w, T(0)));\n        for (int i = 0; i < h; ++i) {\n\
    \            for (int j = 0; j < m.w; ++j) {\n                for (int k = 0;\
    \ k < w; ++k) {\n                    nmat[i][j] += mat[i][k] * m[k][j];\n    \
    \            }\n            }\n        }\n        mat = nmat;\n        return\
    \ *this;\n    }\n\n    // arithmetic with vector\n    using Vec = Vector<T>;\n\
    \    Vec operator*(const Vec& v) {\n        Vec ret(h, 0);\n        for (int i\
    \ = 0; i < h; ++i) {\n            for (int j = 0; j < w; ++j) {\n            \
    \    ret[i] += mat[i][j] * v[j];\n            }\n        }\n        return ret;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Number/linear_algebra.hpp
  requiredBy: []
  timestamp: '2020-08-25 16:53:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Number/linear_algebra.hpp
layout: document
redirect_from:
- /library/Number/linear_algebra.hpp
- /library/Number/linear_algebra.hpp.html
title: Number/linear_algebra.hpp
---
