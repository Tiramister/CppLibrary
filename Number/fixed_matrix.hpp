#pragma once

#include <array>

template <class T, int D>
struct Matrix : public std::array<std::array<T, D>, D> {
    // constructor
    using std::array<std::array<T, D>, D>::array;

    Matrix(T val = 0) {
        for (auto& v : *this) v.fill(val);
    }

    static Matrix id() {
        Matrix m;
        for (int i = 0; i < D; ++i) m[i][i] = 1;
        return m;
    }

    // arithmetic
    Matrix operator*(const Matrix& m) const { return Matrix(*this) *= m; }
    Matrix& operator*=(const Matrix& m) {
        Matrix nmat;
        for (auto& v : nmat) v.fill(0);

        for (int i = 0; i < D; ++i) {
            for (int j = 0; j < D; ++j) {
                for (int k = 0; k < D; ++k) {
                    nmat[i][j] += (*this)[i][k] * m[k][j];
                }
            }
        }
        return *this = nmat;
    }

    template <class U>
    Matrix pow(U k) {
        Matrix ret = id();
        Matrix a = *this;

        while (k > 0) {
            if (k & 1) ret *= a;
            a *= a;
            k >>= 1;
        }
        return ret;
    }
};
