#pragma once

#include <vector>

template <class T>
struct Matrix : public std::vector<std::vector<T>> {
    // constructor
    using std::vector<std::vector<T>>::vector;

    Matrix(int h, int w, T val = 0) {
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
        int h1 = this->size(),
            h2 = m.size(),
            w2 = m.front().size();

        Matrix nmat(h1, w2);
        for (int i = 0; i < h1; ++i) {
            for (int j = 0; j < w2; ++j) {
                for (int k = 0; k < h2; ++k) {
                    nmat[i][j] += (*this)[i][k] * m[k][j];
                }
            }
        }
        return *this = nmat;
    }

    template <class U>
    Matrix pow(U k) {
        Matrix ret = id(this->size());
        Matrix a = *this;

        while (k > 0) {
            if (k & 1) ret *= a;
            a *= a;
            k >>= 1;
        }
        return ret;
    }
};
