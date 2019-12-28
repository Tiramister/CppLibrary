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


# :warning: Verify/combination.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/Verify/combination.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-29 02:37:49+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C">https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C</a>


## Depends on

* :warning: <a href="../../library/Number/combination.cpp.html">Number/combination.cpp</a>
* :warning: <a href="../../library/Number/modint.cpp.html">Number/modint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C"

#define __guard__
#include "../Number/modint.cpp"
#include "../Number/combination.cpp"
#undef __guard__

constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

const Combination<mint> C(1000);

int main() {
    int n, k;
    std::cin >> n >> k;

    mint ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans += mint(-1).pow(k - i) * C.comb(k, i) * mint(i).pow(n);
    }
    std::cout << ans << std::endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/combination.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C"

#define __guard__
#line 1 "Verify/../Number/modint.cpp"
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

    // I/O
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }
};

// constexpr int MOD = 1e9 + 7;
// using mint = ModInt<MOD>;
#line 1 "Verify/../Number/combination.cpp"
#include <vector>

template <class T>
struct Combination {
    int max_n;
    std::vector<T> f, invf;

    explicit Combination(int n)
        : max_n(n), f(n + 1), invf(n + 1) {
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] * i;
        }

        invf[max_n] = f[max_n].inv();
        for (int i = max_n - 1; i >= 0; --i) {
            invf[i] = invf[i + 1] * (i + 1);
        }
    }

    T fact(int n) const { return f[n]; }
    T invfact(int n) const { return invf[n]; }
    T perm(int a, int b) const {
        return a < b ? T(0) : f[a] * invf[a - b];
    }
    T comb(int a, int b) const {
        return a < b ? T(0) : f[a] * invf[a - b] * invf[b];
    }
};
#line 6 "Verify/combination.test.cpp"
#undef __guard__

constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

const Combination<mint> C(1000);

int main() {
    int n, k;
    std::cin >> n >> k;

    mint ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans += mint(-1).pow(k - i) * C.comb(k, i) * mint(i).pow(n);
    }
    std::cout << ans << std::endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

