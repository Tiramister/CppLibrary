---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: Convolution/fast_fourier_transform.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#fa0f0ae43fdca46d1d68255409ec0b89">Convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/Convolution/fast_fourier_transform.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 17:07:38+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <algorithm>
#include <cmath>
#include <vector>

template <int K>
struct FastFourierTransform {
    using Real = double;

    struct cplx {
        Real real, imag;

        explicit cplx(Real real = 0, Real imag = 0)
            : real(real), imag(imag) {}

        cplx operator+(const cplx& other) const {
            return cplx(real + other.real, imag + other.imag);
        }
        cplx operator-(const cplx& other) const {
            return cplx(real - other.real, imag - other.imag);
        }
        cplx operator*(const cplx& other) const {
            return cplx(real * other.real - imag * other.imag,
                        real * other.imag + imag * other.real);
        }
        cplx conj() const { return cplx(real, -imag); }
    };
    using cplxs = std::vector<cplx>;

    static constexpr Real PI = 3.14159265358979323846L;

    cplxs zetas;

    explicit FastFourierTransform() : zetas(K) {
        for (int i = 0; i < K; ++i) {
            zetas[i] = cplx(std::cos(PI * 2 / (1 << i)),
                            std::sin(PI * 2 / (1 << i)));
        }
    }

    // ceil(log_2 n)
    static int clog2(int n) {
        int k = 0;
        while ((1 << k) < n) ++k;
        return k;
    }

    // 2-radix cooley-tukey algorithm without bit reverse
    // the size of f must be a power of 2
    void fft(cplxs& f) const {
        int n = f.size();

        for (int m = n >> 1; m >= 1; m >>= 1) {
            auto zeta = zetas[clog2(m) + 1];
            cplx zetapow(1);

            for (int p = 0; p < m; ++p) {
                for (int s = 0; s < n; s += (m << 1)) {
                    auto l = f[s + p],
                         r = f[s + p + m];

                    f[s + p] = l + r;
                    f[s + p + m] = (l - r) * zetapow;
                }
                zetapow = zetapow * zeta;
            }
        }
    }

    // the inverse of above function
    void ifft(cplxs& f) const {
        int n = f.size();

        for (int m = 1; m <= (n >> 1); m <<= 1) {
            auto zeta = zetas[clog2(m) + 1].conj();
            cplx zetapow(1);

            for (int p = 0; p < m; ++p) {
                for (int s = 0; s < n; s += (m << 1)) {
                    auto l = f[s + p],
                         r = f[s + p + m] * zetapow;

                    f[s + p] = l + r;
                    f[s + p + m] = l - r;
                }
                zetapow = zetapow * zeta;
            }
        }

        auto ninv = cplx(1.L / n);
        for (auto& x : f) x = x * ninv;
    }

    // main routine
    using lint = long long;
    using lints = std::vector<lint>;

    lints convolute(const lints& f, const lints& g) const {
        int fsz = f.size(),
            gsz = g.size();

        // simple convolution in small cases
        if (std::min(fsz, gsz) < 8) {
            lints ret(fsz + gsz - 1, 0);
            for (int i = 0; i < fsz; ++i) {
                for (int j = 0; j < gsz; ++j) {
                    ret[i + j] += f[i] * g[j];
                }
            }
            return ret;
        }

        auto fc = li2cp(f),
             gc = li2cp(g);

        int n = 1 << clog2(fsz + gsz - 1);
        fc.resize(n, cplx(0));
        gc.resize(n, cplx(0));

        fft(fc);
        fft(gc);

        for (int i = 0; i < n; ++i) fc[i] = fc[i] * gc[i];

        ifft(fc);

        fc.resize(fsz + gsz - 1);
        return cp2li(fc);
    }

    // lint <-> complex
    cplxs li2cp(const lints& f) const {
        cplxs ret(f.size());
        std::transform(f.begin(), f.end(), ret.begin(),
                       [](auto x) { return cplx(x); });
        return ret;
    }

    lints cp2li(const cplxs& f) const {
        lints ret(f.size());
        std::transform(f.begin(), f.end(), ret.begin(),
                       [](auto x) { return std::llround(x.real); });
        return ret;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Convolution/fast_fourier_transform.hpp"
#include <algorithm>
#include <cmath>
#include <vector>

template <int K>
struct FastFourierTransform {
    using Real = double;

    struct cplx {
        Real real, imag;

        explicit cplx(Real real = 0, Real imag = 0)
            : real(real), imag(imag) {}

        cplx operator+(const cplx& other) const {
            return cplx(real + other.real, imag + other.imag);
        }
        cplx operator-(const cplx& other) const {
            return cplx(real - other.real, imag - other.imag);
        }
        cplx operator*(const cplx& other) const {
            return cplx(real * other.real - imag * other.imag,
                        real * other.imag + imag * other.real);
        }
        cplx conj() const { return cplx(real, -imag); }
    };
    using cplxs = std::vector<cplx>;

    static constexpr Real PI = 3.14159265358979323846L;

    cplxs zetas;

    explicit FastFourierTransform() : zetas(K) {
        for (int i = 0; i < K; ++i) {
            zetas[i] = cplx(std::cos(PI * 2 / (1 << i)),
                            std::sin(PI * 2 / (1 << i)));
        }
    }

    // ceil(log_2 n)
    static int clog2(int n) {
        int k = 0;
        while ((1 << k) < n) ++k;
        return k;
    }

    // 2-radix cooley-tukey algorithm without bit reverse
    // the size of f must be a power of 2
    void fft(cplxs& f) const {
        int n = f.size();

        for (int m = n >> 1; m >= 1; m >>= 1) {
            auto zeta = zetas[clog2(m) + 1];
            cplx zetapow(1);

            for (int p = 0; p < m; ++p) {
                for (int s = 0; s < n; s += (m << 1)) {
                    auto l = f[s + p],
                         r = f[s + p + m];

                    f[s + p] = l + r;
                    f[s + p + m] = (l - r) * zetapow;
                }
                zetapow = zetapow * zeta;
            }
        }
    }

    // the inverse of above function
    void ifft(cplxs& f) const {
        int n = f.size();

        for (int m = 1; m <= (n >> 1); m <<= 1) {
            auto zeta = zetas[clog2(m) + 1].conj();
            cplx zetapow(1);

            for (int p = 0; p < m; ++p) {
                for (int s = 0; s < n; s += (m << 1)) {
                    auto l = f[s + p],
                         r = f[s + p + m] * zetapow;

                    f[s + p] = l + r;
                    f[s + p + m] = l - r;
                }
                zetapow = zetapow * zeta;
            }
        }

        auto ninv = cplx(1.L / n);
        for (auto& x : f) x = x * ninv;
    }

    // main routine
    using lint = long long;
    using lints = std::vector<lint>;

    lints convolute(const lints& f, const lints& g) const {
        int fsz = f.size(),
            gsz = g.size();

        // simple convolution in small cases
        if (std::min(fsz, gsz) < 8) {
            lints ret(fsz + gsz - 1, 0);
            for (int i = 0; i < fsz; ++i) {
                for (int j = 0; j < gsz; ++j) {
                    ret[i + j] += f[i] * g[j];
                }
            }
            return ret;
        }

        auto fc = li2cp(f),
             gc = li2cp(g);

        int n = 1 << clog2(fsz + gsz - 1);
        fc.resize(n, cplx(0));
        gc.resize(n, cplx(0));

        fft(fc);
        fft(gc);

        for (int i = 0; i < n; ++i) fc[i] = fc[i] * gc[i];

        ifft(fc);

        fc.resize(fsz + gsz - 1);
        return cp2li(fc);
    }

    // lint <-> complex
    cplxs li2cp(const lints& f) const {
        cplxs ret(f.size());
        std::transform(f.begin(), f.end(), ret.begin(),
                       [](auto x) { return cplx(x); });
        return ret;
    }

    lints cp2li(const cplxs& f) const {
        lints ret(f.size());
        std::transform(f.begin(), f.end(), ret.begin(),
                       [](auto x) { return std::llround(x.real); });
        return ret;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

