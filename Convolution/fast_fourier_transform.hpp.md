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
  bundledCode: "#line 1 \"Convolution/fast_fourier_transform.hpp\"\n#include <algorithm>\n\
    #include <cmath>\n#include <vector>\n\ntemplate <int K>\nstruct FastFourierTransform\
    \ {\n    using Real = double;\n\n    struct cplx {\n        Real real, imag;\n\
    \n        explicit cplx(Real real = 0, Real imag = 0)\n            : real(real),\
    \ imag(imag) {}\n\n        cplx operator+(const cplx& other) const {\n       \
    \     return cplx(real + other.real, imag + other.imag);\n        }\n        cplx\
    \ operator-(const cplx& other) const {\n            return cplx(real - other.real,\
    \ imag - other.imag);\n        }\n        cplx operator*(const cplx& other) const\
    \ {\n            return cplx(real * other.real - imag * other.imag,\n        \
    \                real * other.imag + imag * other.real);\n        }\n        cplx\
    \ conj() const { return cplx(real, -imag); }\n    };\n    using cplxs = std::vector<cplx>;\n\
    \n    static constexpr Real PI = 3.14159265358979323846L;\n\n    cplxs zetas;\n\
    \n    explicit FastFourierTransform() : zetas(K) {\n        for (int i = 0; i\
    \ < K; ++i) {\n            zetas[i] = cplx(std::cos(PI * 2 / (1 << i)),\n    \
    \                        std::sin(PI * 2 / (1 << i)));\n        }\n    }\n\n \
    \   // ceil(log_2 n)\n    static int clog2(int n) {\n        int k = 0;\n    \
    \    while ((1 << k) < n) ++k;\n        return k;\n    }\n\n    // 2-radix cooley-tukey\
    \ algorithm without bit reverse\n    // the size of f must be a power of 2\n \
    \   void fft(cplxs& f) const {\n        int n = f.size();\n\n        for (int\
    \ m = n >> 1; m >= 1; m >>= 1) {\n            auto zeta = zetas[clog2(m) + 1];\n\
    \            cplx zetapow(1);\n\n            for (int p = 0; p < m; ++p) {\n \
    \               for (int s = 0; s < n; s += (m << 1)) {\n                    auto\
    \ l = f[s + p],\n                         r = f[s + p + m];\n\n              \
    \      f[s + p] = l + r;\n                    f[s + p + m] = (l - r) * zetapow;\n\
    \                }\n                zetapow = zetapow * zeta;\n            }\n\
    \        }\n    }\n\n    // the inverse of above function\n    void ifft(cplxs&\
    \ f) const {\n        int n = f.size();\n\n        for (int m = 1; m <= (n >>\
    \ 1); m <<= 1) {\n            auto zeta = zetas[clog2(m) + 1].conj();\n      \
    \      cplx zetapow(1);\n\n            for (int p = 0; p < m; ++p) {\n       \
    \         for (int s = 0; s < n; s += (m << 1)) {\n                    auto l\
    \ = f[s + p],\n                         r = f[s + p + m] * zetapow;\n\n      \
    \              f[s + p] = l + r;\n                    f[s + p + m] = l - r;\n\
    \                }\n                zetapow = zetapow * zeta;\n            }\n\
    \        }\n\n        auto ninv = cplx(1.L / n);\n        for (auto& x : f) x\
    \ = x * ninv;\n    }\n\n    // main routine\n    using lint = long long;\n   \
    \ using lints = std::vector<lint>;\n\n    lints convolute(const lints& f, const\
    \ lints& g) const {\n        int fsz = f.size(),\n            gsz = g.size();\n\
    \n        // simple convolution in small cases\n        if (std::min(fsz, gsz)\
    \ < 8) {\n            lints ret(fsz + gsz - 1, 0);\n            for (int i = 0;\
    \ i < fsz; ++i) {\n                for (int j = 0; j < gsz; ++j) {\n         \
    \           ret[i + j] += f[i] * g[j];\n                }\n            }\n   \
    \         return ret;\n        }\n\n        auto fc = li2cp(f),\n            \
    \ gc = li2cp(g);\n\n        int n = 1 << clog2(fsz + gsz - 1);\n        fc.resize(n,\
    \ cplx(0));\n        gc.resize(n, cplx(0));\n\n        fft(fc);\n        fft(gc);\n\
    \n        for (int i = 0; i < n; ++i) fc[i] = fc[i] * gc[i];\n\n        ifft(fc);\n\
    \n        fc.resize(fsz + gsz - 1);\n        return cp2li(fc);\n    }\n\n    //\
    \ lint <-> complex\n    cplxs li2cp(const lints& f) const {\n        cplxs ret(f.size());\n\
    \        std::transform(f.begin(), f.end(), ret.begin(),\n                   \
    \    [](auto x) { return cplx(x); });\n        return ret;\n    }\n\n    lints\
    \ cp2li(const cplxs& f) const {\n        lints ret(f.size());\n        std::transform(f.begin(),\
    \ f.end(), ret.begin(),\n                       [](auto x) { return std::llround(x.real);\
    \ });\n        return ret;\n    }\n};\n"
  code: "#include <algorithm>\n#include <cmath>\n#include <vector>\n\ntemplate <int\
    \ K>\nstruct FastFourierTransform {\n    using Real = double;\n\n    struct cplx\
    \ {\n        Real real, imag;\n\n        explicit cplx(Real real = 0, Real imag\
    \ = 0)\n            : real(real), imag(imag) {}\n\n        cplx operator+(const\
    \ cplx& other) const {\n            return cplx(real + other.real, imag + other.imag);\n\
    \        }\n        cplx operator-(const cplx& other) const {\n            return\
    \ cplx(real - other.real, imag - other.imag);\n        }\n        cplx operator*(const\
    \ cplx& other) const {\n            return cplx(real * other.real - imag * other.imag,\n\
    \                        real * other.imag + imag * other.real);\n        }\n\
    \        cplx conj() const { return cplx(real, -imag); }\n    };\n    using cplxs\
    \ = std::vector<cplx>;\n\n    static constexpr Real PI = 3.14159265358979323846L;\n\
    \n    cplxs zetas;\n\n    explicit FastFourierTransform() : zetas(K) {\n     \
    \   for (int i = 0; i < K; ++i) {\n            zetas[i] = cplx(std::cos(PI * 2\
    \ / (1 << i)),\n                            std::sin(PI * 2 / (1 << i)));\n  \
    \      }\n    }\n\n    // ceil(log_2 n)\n    static int clog2(int n) {\n     \
    \   int k = 0;\n        while ((1 << k) < n) ++k;\n        return k;\n    }\n\n\
    \    // 2-radix cooley-tukey algorithm without bit reverse\n    // the size of\
    \ f must be a power of 2\n    void fft(cplxs& f) const {\n        int n = f.size();\n\
    \n        for (int m = n >> 1; m >= 1; m >>= 1) {\n            auto zeta = zetas[clog2(m)\
    \ + 1];\n            cplx zetapow(1);\n\n            for (int p = 0; p < m; ++p)\
    \ {\n                for (int s = 0; s < n; s += (m << 1)) {\n               \
    \     auto l = f[s + p],\n                         r = f[s + p + m];\n\n     \
    \               f[s + p] = l + r;\n                    f[s + p + m] = (l - r)\
    \ * zetapow;\n                }\n                zetapow = zetapow * zeta;\n \
    \           }\n        }\n    }\n\n    // the inverse of above function\n    void\
    \ ifft(cplxs& f) const {\n        int n = f.size();\n\n        for (int m = 1;\
    \ m <= (n >> 1); m <<= 1) {\n            auto zeta = zetas[clog2(m) + 1].conj();\n\
    \            cplx zetapow(1);\n\n            for (int p = 0; p < m; ++p) {\n \
    \               for (int s = 0; s < n; s += (m << 1)) {\n                    auto\
    \ l = f[s + p],\n                         r = f[s + p + m] * zetapow;\n\n    \
    \                f[s + p] = l + r;\n                    f[s + p + m] = l - r;\n\
    \                }\n                zetapow = zetapow * zeta;\n            }\n\
    \        }\n\n        auto ninv = cplx(1.L / n);\n        for (auto& x : f) x\
    \ = x * ninv;\n    }\n\n    // main routine\n    using lint = long long;\n   \
    \ using lints = std::vector<lint>;\n\n    lints convolute(const lints& f, const\
    \ lints& g) const {\n        int fsz = f.size(),\n            gsz = g.size();\n\
    \n        // simple convolution in small cases\n        if (std::min(fsz, gsz)\
    \ < 8) {\n            lints ret(fsz + gsz - 1, 0);\n            for (int i = 0;\
    \ i < fsz; ++i) {\n                for (int j = 0; j < gsz; ++j) {\n         \
    \           ret[i + j] += f[i] * g[j];\n                }\n            }\n   \
    \         return ret;\n        }\n\n        auto fc = li2cp(f),\n            \
    \ gc = li2cp(g);\n\n        int n = 1 << clog2(fsz + gsz - 1);\n        fc.resize(n,\
    \ cplx(0));\n        gc.resize(n, cplx(0));\n\n        fft(fc);\n        fft(gc);\n\
    \n        for (int i = 0; i < n; ++i) fc[i] = fc[i] * gc[i];\n\n        ifft(fc);\n\
    \n        fc.resize(fsz + gsz - 1);\n        return cp2li(fc);\n    }\n\n    //\
    \ lint <-> complex\n    cplxs li2cp(const lints& f) const {\n        cplxs ret(f.size());\n\
    \        std::transform(f.begin(), f.end(), ret.begin(),\n                   \
    \    [](auto x) { return cplx(x); });\n        return ret;\n    }\n\n    lints\
    \ cp2li(const cplxs& f) const {\n        lints ret(f.size());\n        std::transform(f.begin(),\
    \ f.end(), ret.begin(),\n                       [](auto x) { return std::llround(x.real);\
    \ });\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Convolution/fast_fourier_transform.hpp
  requiredBy: []
  timestamp: '2020-08-25 17:07:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Convolution/fast_fourier_transform.hpp
layout: document
redirect_from:
- /library/Convolution/fast_fourier_transform.hpp
- /library/Convolution/fast_fourier_transform.hpp.html
title: Convolution/fast_fourier_transform.hpp
---
