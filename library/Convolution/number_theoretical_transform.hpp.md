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


# :heavy_check_mark: Convolution/number_theoretical_transform.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#fa0f0ae43fdca46d1d68255409ec0b89">Convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/Convolution/number_theoretical_transform.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 16:50:53+09:00




## Depends on

* :heavy_check_mark: <a href="../Number/modint.hpp.html">Number/modint.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/number_theoretical_transform.test.cpp.html">Verify/number_theoretical_transform.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "../Number/modint.hpp"

#include <vector>

template <int MOD, int Root>
struct NumberTheoreticalTransform {
    using mint = ModInt<MOD>;
    using mints = std::vector<mint>;

    // the 2^k-th root of 1
    std::vector<mint> zetas;
    mint unit_i;

    explicit NumberTheoreticalTransform() {
        int exp = MOD - 1;
        while (true) {
            mint zeta = mint(Root).pow(exp);
            zetas.push_back(zeta);
            if (exp & 1) break;
            exp /= 2;
        }
        unit_i = zetas[2];
    }

    // ceil(log_2 n)
    static int clog2(int n) {
        int k = 0;
        while ((1 << k) < n) ++k;
        return k;
    }

    // 4-radix cooley-tukey algorithm without bit reverse
    // the size of f must be a power of 4
    void ntt(mints& f) const {
        int n = f.size();

        for (int m = n >> 1; m >= 1; m >>= 1) {
            auto zeta = zetas[clog2(m) + 1];
            mint zetapow(1);

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
    void intt(mints& f) const {
        int n = f.size();

        for (int m = 1; m <= (n >> 1); m <<= 1) {
            auto zeta = zetas[clog2(m) + 1].inv();
            mint zetapow(1);

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

        auto ninv = mint(n).inv();
        for (auto& x : f) x *= ninv;
    }

    mints convolute(mints f, mints g) const {
        int fsz = f.size(),
            gsz = g.size();

        // simple convolution in small cases
        if (std::min(fsz, gsz) < 8) {
            mints ret(fsz + gsz - 1, 0);
            for (int i = 0; i < fsz; ++i) {
                for (int j = 0; j < gsz; ++j) {
                    ret[i + j] += f[i] * g[j];
                }
            }
            return ret;
        }

        int n = 1 << clog2(fsz + gsz - 1);
        f.resize(n, mint(0));
        g.resize(n, mint(0));

        ntt(f);
        ntt(g);

        for (int i = 0; i < n; ++i) f[i] *= g[i];

        intt(f);

        f.resize(fsz + gsz - 1);
        return f;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Convolution/number_theoretical_transform.hpp"

#line 2 "Number/modint.hpp"

#include <iostream>

template <int MOD>
struct ModInt {
    using lint = long long;
    int val;

    // constructor
    ModInt(lint v = 0) : val(v % MOD) {
        if (val < 0) val += MOD;
    };

    // unary operator
    ModInt operator+() const { return ModInt(val); }
    ModInt operator-() const { return ModInt(MOD - val); }
    ModInt inv() const { return this->pow(MOD - 2); }

    // arithmetic
    ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }
    ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }
    ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }
    ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }
    ModInt pow(lint n) const {
        auto x = ModInt(1);
        auto b = *this;
        while (n > 0) {
            if (n & 1) x *= b;
            n >>= 1;
            b *= b;
        }
        return x;
    }

    // compound assignment
    ModInt& operator+=(const ModInt& x) {
        if ((val += x.val) >= MOD) val -= MOD;
        return *this;
    }
    ModInt& operator-=(const ModInt& x) {
        if ((val -= x.val) < 0) val += MOD;
        return *this;
    }
    ModInt& operator*=(const ModInt& x) {
        val = lint(val) * x.val % MOD;
        return *this;
    }
    ModInt& operator/=(const ModInt& x) { return *this *= x.inv(); }

    // compare
    bool operator==(const ModInt& b) const { return val == b.val; }
    bool operator!=(const ModInt& b) const { return val != b.val; }
    bool operator<(const ModInt& b) const { return val < b.val; }
    bool operator<=(const ModInt& b) const { return val <= b.val; }
    bool operator>(const ModInt& b) const { return val > b.val; }
    bool operator>=(const ModInt& b) const { return val >= b.val; }

    // I/O
    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept {
        lint v;
        is >> v;
        x = v;
        return is;
    }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
};

// constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
// using mint = ModInt<MOD>;
#line 4 "Convolution/number_theoretical_transform.hpp"

#include <vector>

template <int MOD, int Root>
struct NumberTheoreticalTransform {
    using mint = ModInt<MOD>;
    using mints = std::vector<mint>;

    // the 2^k-th root of 1
    std::vector<mint> zetas;
    mint unit_i;

    explicit NumberTheoreticalTransform() {
        int exp = MOD - 1;
        while (true) {
            mint zeta = mint(Root).pow(exp);
            zetas.push_back(zeta);
            if (exp & 1) break;
            exp /= 2;
        }
        unit_i = zetas[2];
    }

    // ceil(log_2 n)
    static int clog2(int n) {
        int k = 0;
        while ((1 << k) < n) ++k;
        return k;
    }

    // 4-radix cooley-tukey algorithm without bit reverse
    // the size of f must be a power of 4
    void ntt(mints& f) const {
        int n = f.size();

        for (int m = n >> 1; m >= 1; m >>= 1) {
            auto zeta = zetas[clog2(m) + 1];
            mint zetapow(1);

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
    void intt(mints& f) const {
        int n = f.size();

        for (int m = 1; m <= (n >> 1); m <<= 1) {
            auto zeta = zetas[clog2(m) + 1].inv();
            mint zetapow(1);

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

        auto ninv = mint(n).inv();
        for (auto& x : f) x *= ninv;
    }

    mints convolute(mints f, mints g) const {
        int fsz = f.size(),
            gsz = g.size();

        // simple convolution in small cases
        if (std::min(fsz, gsz) < 8) {
            mints ret(fsz + gsz - 1, 0);
            for (int i = 0; i < fsz; ++i) {
                for (int j = 0; j < gsz; ++j) {
                    ret[i + j] += f[i] * g[j];
                }
            }
            return ret;
        }

        int n = 1 << clog2(fsz + gsz - 1);
        f.resize(n, mint(0));
        g.resize(n, mint(0));

        ntt(f);
        ntt(g);

        for (int i = 0; i < n; ++i) f[i] *= g[i];

        intt(f);

        f.resize(fsz + gsz - 1);
        return f;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

