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


# :heavy_check_mark: Verify/lazy_segment_tree_affine.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/lazy_segment_tree_affine.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 16:49:54+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_affine_range_sum">https://judge.yosupo.jp/problem/range_affine_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/lazy_segment_tree.hpp.html">DataStructure/lazy_segment_tree.hpp</a>
* :heavy_check_mark: <a href="../../library/Number/modint.hpp.html">Number/modint.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../DataStructure/lazy_segment_tree.hpp"
#include "../Number/modint.hpp"

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

template <class T>
struct Affine {
    T a, b;
    Affine() = default;
    Affine(T a, T b) : a(a), b(b) {}

    T operator()(T x) const { return a * x + b; }
    bool operator==(const Affine<T>& rhs) const {
        return a == rhs.a && b == rhs.b;
    }
};

using affine = Affine<mint>;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    std::vector<mint> xs(n);
    for (auto& x : xs) std::cin >> x;

    LazySegmentTree<mint, affine>
        seg(
            xs, 0, affine(1, 0),
            [](mint a, mint b) { return a + b; },
            [](affine f, affine g) { return affine(f.a * g.a, g.a * f.b + g.b); },
            [](mint a, affine f, int k) { return f.a * a + f.b * k; });

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int l, r, a, b;
            std::cin >> l >> r >> a >> b;
            seg.update(l, r, affine(a, b));

        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.fold(l, r) << "\n";
        }
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/lazy_segment_tree_affine.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#line 2 "DataStructure/lazy_segment_tree.hpp"

#include <vector>
#include <functional>

template <class T, class E>
struct LazySegmentTree {
    using DMerger = std::function<T(T, T)>;
    using OMerger = std::function<E(E, E)>;
    using Applier = std::function<T(T, E, int)>;

    int length;

    T d_unit;
    E o_unit;

    std::vector<T> dat;
    std::vector<E> ope;

    DMerger dmerge;
    OMerger omerge;
    Applier app;

    explicit LazySegmentTree(int n,
                             T d_unit, E o_unit,
                             DMerger dmerge,
                             OMerger omerge,
                             Applier app)
        : length(1),
          d_unit(d_unit),
          o_unit(o_unit),
          dmerge(dmerge),
          omerge(omerge),
          app(app) {
        while (length < n) length <<= 1;

        dat.assign(length * 2, d_unit);
        ope.assign(length * 2, o_unit);
    }

    template <class Container>
    explicit LazySegmentTree(const Container& elems,
                             T d_unit, E o_unit,
                             DMerger dmerge,
                             OMerger omerge,
                             Applier app)
        : length(1),
          d_unit(d_unit),
          o_unit(o_unit),
          dmerge(dmerge),
          omerge(omerge),
          app(app) {
        int n = elems.size();
        while (length < n) length <<= 1;

        dat.assign(length * 2, d_unit);
        ope.assign(length * 2, o_unit);

        std::copy(elems.begin(), elems.end(), dat.begin() + length);

        for (int nidx = length - 1; nidx >= 1; --nidx) {
            T vl = dat[nidx * 2 + 0];
            T vr = dat[nidx * 2 + 1];
            dat[nidx] = dmerge(vl, vr);
        }
    }

    void propagate(int nidx, int len) {
        if (ope[nidx] == o_unit) return;

        // propagate
        if (len > 1) {
            ope[nidx * 2 + 0] = omerge(ope[nidx * 2 + 0], ope[nidx]);
            ope[nidx * 2 + 1] = omerge(ope[nidx * 2 + 1], ope[nidx]);
        }

        // update data
        dat[nidx] = app(dat[nidx], ope[nidx], len);
        ope[nidx] = o_unit;
    }

    void update(int ql, int qr, E e, int nidx, int nl, int nr) {
        propagate(nidx, nr - nl);

        if (nr <= ql || qr <= nl) return;
        if (ql <= nl && nr <= qr) {
            ope[nidx] = omerge(ope[nidx], e);
            propagate(nidx, nr - nl);
            return;
        }

        int nm = (nl + nr) / 2;
        update(ql, qr, e, nidx * 2 + 0, nl, nm);
        update(ql, qr, e, nidx * 2 + 1, nm, nr);

        // update data
        dat[nidx] = dmerge(dat[nidx * 2 + 0], dat[nidx * 2 + 1]);
    }

    void update(int ql, int qr, E e) { return update(ql, qr, e, 1, 0, length); }

    T fold(int ql, int qr, int nidx, int nl, int nr) {
        propagate(nidx, nr - nl);

        if (nr <= ql || qr <= nl) return d_unit;
        if (ql <= nl && nr <= qr) return dat[nidx];

        int nm = (nl + nr) / 2;
        T vl = fold(ql, qr, nidx * 2 + 0, nl, nm);
        T vr = fold(ql, qr, nidx * 2 + 1, nm, nr);
        return dmerge(vl, vr);
    }

    T fold(int ql, int qr) { return fold(ql, qr, 1, 0, length); }

    T get(int idx) { return fold(idx, idx + 1); }
    T fold_all() { return fold(0, length); }
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
#line 5 "Verify/lazy_segment_tree_affine.test.cpp"

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

template <class T>
struct Affine {
    T a, b;
    Affine() = default;
    Affine(T a, T b) : a(a), b(b) {}

    T operator()(T x) const { return a * x + b; }
    bool operator==(const Affine<T>& rhs) const {
        return a == rhs.a && b == rhs.b;
    }
};

using affine = Affine<mint>;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    std::vector<mint> xs(n);
    for (auto& x : xs) std::cin >> x;

    LazySegmentTree<mint, affine>
        seg(
            xs, 0, affine(1, 0),
            [](mint a, mint b) { return a + b; },
            [](affine f, affine g) { return affine(f.a * g.a, g.a * f.b + g.b); },
            [](mint a, affine f, int k) { return f.a * a + f.b * k; });

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int l, r, a, b;
            std::cin >> l >> r >> a >> b;
            seg.update(l, r, affine(a, b));

        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.fold(l, r) << "\n";
        }
    }

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
