#pragma once

#include <vector>

template <class T>
struct Vector {
    using V = std::vector<T>;

    int d;
    V vec;

    // constructor
    Vector(int d, T val = 0) : d(d), vec(d, val) {}

    // getter
    T& operator[](int i) { return vec[i]; }
    T operator[](int i) const { return vec[i]; }
    typename V::iterator begin() { return vec.begin(); }
    typename V::iterator end() { return vec.end(); }

    // arithmetic
    Vector operator+(const Vector& v) const { return Vector(*this) += v; }
    Vector operator-(const Vector& v) const { return Vector(*this) -= v; }
    T operator*(const Vector& v) const {
        T ret(0);
        for (int i = 0; i < d; ++i) ret += vec[i] * v[i];
        return ret;
    }

    // compound assignment
    Vector& operator+=(const Vector& v) {
        for (int i = 0; i < d; ++i) vec[i] += v[i];
        return *this;
    }
    Vector& operator-=(const Vector& v) {
        for (int i = 0; i < d; ++i) vec[i] -= v[i];
        return *this;
    }
};

template <class T>
struct Matrix {
    using M = std::vector<std::vector<T>>;

    int h, w;
    M mat;

    // constructor
    Matrix(int h, int w, T val = 0)
        : h(h), w(w), mat(h, std::vector<T>(w, val)) {}

    static Matrix id(int n) {
        Matrix m(n, n);
        for (int i = 0; i < n; ++i) m[i][i] = 1;
        return m;
    }

    // getter
    std::vector<T>& operator[](int i) { return mat[i]; }
    std::vector<T> operator[](int i) const { return mat[i]; }
    typename M::iterator begin() { return mat.begin(); }
    typename M::iterator end() { return mat.end(); }

    // arithmetic
    Matrix operator+(const Matrix& m) const { return Matrix(*this) += m; }
    Matrix operator-(const Matrix& m) const { return Matrix(*this) -= m; }
    Matrix operator*(const Matrix& m) const { return Matrix(*this) *= m; }

    template <class U>
    Matrix pow(U k) {
        Matrix ret = id(h);
        Matrix a = *this;

        while (k > 0) {
            if (k & 1) ret *= a;
            a *= a;
            k >>= 1;
        }
        return ret;
    }

    // compound assignment
    Matrix& operator+=(const Matrix& m) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                mat[i][j] += m[i][j];
            }
        }
        return *this;
    }
    Matrix& operator-=(const Matrix& m) {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                mat[i][j] -= m[i][j];
            }
        }
        return *this;
    }
    Matrix& operator*=(const Matrix& m) {
        std::vector<std::vector<T>> nmat(h, std::vector<T>(m.w, T(0)));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < m.w; ++j) {
                for (int k = 0; k < w; ++k) {
                    nmat[i][j] += mat[i][k] * m[k][j];
                }
            }
        }
        mat = nmat;
        return *this;
    }

    // arithmetic with vector
    using Vec = Vector<T>;
    Vec operator*(const Vec& v) {
        Vec ret(h, 0);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                ret[i] += mat[i][j] * v[j];
            }
        }
        return ret;
    }
};
