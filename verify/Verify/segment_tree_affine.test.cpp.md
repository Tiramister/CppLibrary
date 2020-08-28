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


# :heavy_check_mark: Verify/segment_tree_affine.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/segment_tree_affine.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 16:49:54+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/segment_tree.hpp.html">DataStructure/segment_tree.hpp</a>
* :heavy_check_mark: <a href="../../library/Number/modint.hpp.html">Number/modint.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../DataStructure/segment_tree.hpp"
#include "../Number/modint.hpp"

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

template <class T>
struct Affine {
    T a, b;
    Affine() = default;
    Affine(T a, T b) : a(a), b(b) {}

    T operator()(T x) const { return a * x + b; }
};

using affine = Affine<mint>;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    std::vector<affine> xs(n);
    for (auto& x : xs) std::cin >> x.a >> x.b;

    SegmentTree<affine>
        seg(xs, affine(1, 0),
            [](affine f, affine g) { return affine(f.a * g.a, g.a * f.b + g.b); });

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int i, a, b;
            std::cin >> i >> a >> b;
            seg.update(i, affine(a, b));

        } else {
            int l, r, x;
            std::cin >> l >> r >> x;
            auto f = seg.fold(l, r);
            std::cout << f(x) << "\n";
        }
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/segment_tree_affine.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#line 2 "DataStructure/segment_tree.hpp"

#include <vector>
#include <functional>

template <class T>
struct SegmentTree {
    using Merger = std::function<T(T, T)>;

    int length;
    std::vector<T> dat;
    T unit;
    Merger merge;

    SegmentTree() = default;

    SegmentTree(int n, const T& unit, const Merger& merge)
        : length(1), unit(unit), merge(merge) {
        while (length < n) length <<= 1;
        dat.assign(length * 2, unit);
    }

    template <class Container>
    SegmentTree(const Container& elems, const T& unit, const Merger& merge)
        : length(1), unit(unit), merge(merge) {
        int n = elems.size();
        while (length < n) length <<= 1;

        dat.assign(length * 2, unit);

        std::copy(elems.begin(), elems.end(), dat.begin() + length);

        for (int nidx = length - 1; nidx >= 1; --nidx) {
            T vl = dat[nidx * 2 + 0];
            T vr = dat[nidx * 2 + 1];
            dat[nidx] = merge(vl, vr);
        }
    }

    void update(int nidx, const T& elem) {
        nidx += length;
        dat[nidx] = elem;

        while (nidx > 0) {
            nidx >>= 1;
            T vl = dat[nidx * 2 + 0];
            T vr = dat[nidx * 2 + 1];
            dat[nidx] = merge(vl, vr);
        }
    }

    T fold(int ql, int qr) const {
        ql = std::max(ql, 0);
        qr = std::min(qr, length);
        ql += length, qr += length;

        T lacc = unit, racc = unit;
        while (ql < qr) {
            if (ql & 1) {
                lacc = merge(lacc, dat[ql]);
                ++ql;
            }
            if (qr & 1) {
                --qr;
                racc = merge(dat[qr], racc);
            }
            ql >>= 1, qr >>= 1;
        }

        return merge(lacc, racc);
    }

    T get(int idx) const { return dat[idx + length]; }
    T fold_all() const { return dat[1]; }
};
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
#line 5 "Verify/segment_tree_affine.test.cpp"

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

template <class T>
struct Affine {
    T a, b;
    Affine() = default;
    Affine(T a, T b) : a(a), b(b) {}

    T operator()(T x) const { return a * x + b; }
};

using affine = Affine<mint>;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    std::vector<affine> xs(n);
    for (auto& x : xs) std::cin >> x.a >> x.b;

    SegmentTree<affine>
        seg(xs, affine(1, 0),
            [](affine f, affine g) { return affine(f.a * g.a, g.a * f.b + g.b); });

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int i, a, b;
            std::cin >> i >> a >> b;
            seg.update(i, affine(a, b));

        } else {
            int l, r, x;
            std::cin >> l >> r >> x;
            auto f = seg.fold(l, r);
            std::cout << f(x) << "\n";
        }
    }

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
