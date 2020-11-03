#pragma once

#include <vector>

template <class T>
struct Matrix : public std::vector<std::vector<T>> {
    int h, w;
    // constructor
    Matrix(int h, int w, T val = 0)
        : h(h), w(w) {
        this->resize(h);
        for (auto& v : *this) v.resize(w, val);
    }

    static Matrix id(int n) {
        Matrix m(n, n);
        for (int i = 0; i < n; ++i) m[i][i] = 1;
        return m;
    }

    // arithmetic
    Matrix operator*(const Matrix& m) const { return Matrix(*this) *= m; }
    Matrix& operator*=(const Matrix& m) {
        Matrix nmat(h, w);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < m.w; ++j) {
                for (int k = 0; k < w; ++k) {
                    nmat[i][j] += (*this)[i][k] * m[k][j];
                }
            }
        }
        return *this = nmat;
    }

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
};
