#include <array>

template <class T, int D>
struct Vector {
    using V = std::array<T, D>;

    V vec;

    // constructor
    Vector(T val = 0) { vec.fill(val); }

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
        for (int i = 0; i < D; ++i) ret += vec[i] * v[i];
        return ret;
    }

    // compound assignment
    Vector& operator+=(const Vector& v) {
        for (int i = 0; i < D; ++i) vec[i] += v[i];
        return *this;
    }
    Vector& operator-=(const Vector& v) {
        for (int i = 0; i < D; ++i) vec[i] -= v[i];
        return *this;
    }
};

template <class T, int D>
struct Matrix {
    using M = std::array<std::array<T, D>, D>;

    M mat;

    // constructor
    Matrix(T val = 0) {
        for (auto& v : mat) v.fill(val);
    }

    static Matrix id() {
        Matrix m;
        for (int i = 0; i < D; ++i) m[i][i] = 1;
        return m;
    }

    // getter
    std::array<T, D>& operator[](int i) { return mat[i]; }
    std::array<T, D> operator[](int i) const { return mat[i]; }
    typename M::iterator begin() { return mat.begin(); }
    typename M::iterator end() { return mat.end(); }

    // arithmetic
    Matrix operator+(const Matrix& m) const { return Matrix(*this) += m; }
    Matrix operator-(const Matrix& m) const { return Matrix(*this) -= m; }
    Matrix operator*(const Matrix& m) const { return Matrix(*this) *= m; }

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

    // compound assignment
    Matrix& operator+=(const Matrix& m) {
        for (int i = 0; i < D; ++i) {
            for (int j = 0; j < D; ++j) {
                mat[i][j] += m[i][j];
            }
        }
        return *this;
    }
    Matrix& operator-=(const Matrix& m) {
        for (int i = 0; i < D; ++i) {
            for (int j = 0; j < D; ++j) {
                mat[i][j] -= m[i][j];
            }
        }
        return *this;
    }
    Matrix& operator*=(const Matrix& m) {
        M nmat;
        for (auto& v : nmat) v.fill(0);

        for (int i = 0; i < D; ++i) {
            for (int j = 0; j < D; ++j) {
                for (int k = 0; k < D; ++k) {
                    nmat[i][j] += mat[i][k] * m[k][j];
                }
            }
        }
        mat = nmat;
        return *this;
    }

    // arithmetic with vector
    using Vec = Vector<T, D>;
    Vec operator*(const Vec& v) {
        Vec ret;
        for (int i = 0; i < D; ++i) {
            for (int j = 0; j < D; ++j) {
                ret[i] += mat[i][j] * v[j];
            }
        }
        return ret;
    }
};
