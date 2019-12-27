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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: DataStructure/Verify/segment_tree_linear.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/Verify/segment_tree_linear.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-28 02:41:36+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/DataStructure/segment_tree.cpp.html">DataStructure/segment_tree.cpp</a>
* :heavy_check_mark: <a href="../../../library/Number/modint.cpp.html">Number/modint.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../segment_tree.cpp"
#include "../../Number/modint.cpp"

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

template <class T>
struct Linear {
    T a, b;
    explicit Linear(T a, T b) : a(a), b(b) {}
    T operator()(T x) const { return a * x + b; }
};

using linear = Linear<mint>;

int main() {
    int n, q;
    std::cin >> n >> q;

    SegmentTree<linear>
        seg(n, linear(1, 0),
            [](linear f, linear g) { return linear(f.a * g.a, g.a * f.b + g.b); });
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        seg.update(i, linear(a, b));
    }

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int i, a, b;
            std::cin >> i >> a >> b;
            seg.update(i, linear(a, b));
        } else {
            int l, r, x;
            std::cin >> l >> r >> x;
            auto f = seg.query(l, r);
            std::cout << f(x) << std::endl;
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/Verify/segment_tree_linear.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#line 1 "DataStructure/Verify/../segment_tree.cpp"
#include <vector>
#include <functional>

template <class T>
struct SegmentTree {
    using Merger = std::function<T(T, T)>;

    int length;
    std::vector<T> dat;
    T unit;
    Merger merge;

    explicit SegmentTree(int n, T unit, Merger merge)
        : length(1), unit(unit), merge(merge) {
        while (length < n) length <<= 1;
        dat.assign(length * 2, unit);
    }

    T query(int ql, int qr, int nidx, int nl, int nr) {
        if (nr <= ql || qr <= nl) return unit;
        if (ql <= nl && nr <= qr) return dat[nidx];

        int nm = (nl + nr) / 2;
        T vl = query(ql, qr, nidx * 2 + 0, nl, nm);
        T vr = query(ql, qr, nidx * 2 + 1, nm, nr);
        return merge(vl, vr);
    }

    T query(int ql, int qr) { return query(ql, qr, 1, 0, length); }

    void update(int nidx, T elem) {
        nidx += length;
        dat[nidx] = elem;

        while (nidx > 0) {
            nidx >>= 1;
            T vl = dat[nidx * 2 + 0];
            T vr = dat[nidx * 2 + 1];
            dat[nidx] = merge(vl, vr);
        }
    }
};
#line 1 "DataStructure/Verify/../../Number/modint.cpp"
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
#line 5 "DataStructure/Verify/segment_tree_linear.test.cpp"

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

template <class T>
struct Linear {
    T a, b;
    explicit Linear(T a, T b) : a(a), b(b) {}
    T operator()(T x) const { return a * x + b; }
};

using linear = Linear<mint>;

int main() {
    int n, q;
    std::cin >> n >> q;

    SegmentTree<linear>
        seg(n, linear(1, 0),
            [](linear f, linear g) { return linear(f.a * g.a, g.a * f.b + g.b); });
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        seg.update(i, linear(a, b));
    }

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int i, a, b;
            std::cin >> i >> a >> b;
            seg.update(i, linear(a, b));
        } else {
            int l, r, x;
            std::cin >> l >> r >> x;
            auto f = seg.query(l, r);
            std::cout << f(x) << std::endl;
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

