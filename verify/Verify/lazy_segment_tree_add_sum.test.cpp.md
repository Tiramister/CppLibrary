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


# :heavy_check_mark: Verify/lazy_segment_tree_add_sum.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/lazy_segment_tree_add_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 23:11:18+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/lazy_segment_tree.cpp.html">DataStructure/lazy_segment_tree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G"

#include "../DataStructure/lazy_segment_tree.cpp"

#include <iostream>

using lint = long long;

int main() {
    int n, q;
    std::cin >> n >> q;

    LazySegmentTree<lint, lint> seg(
        n, 0, 0,
        [](auto a, auto b) { return a + b; },
        [](auto e, auto f) { return e + f; },
        [](auto a, auto e, int l) { return a + e * l; });

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int l, r;
            lint x;
            std::cin >> l >> r >> x;
            --l, --r;
            seg.update(l, r + 1, x);

        } else {
            int l, r;
            std::cin >> l >> r;
            --l, --r;
            std::cout << seg.query(l, r + 1) << "\n";
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/lazy_segment_tree_add_sum.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G"

#line 2 "DataStructure/lazy_segment_tree.cpp"

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

    void eval(int nidx, int len) {
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
        eval(nidx, nr - nl);

        if (nr <= ql || qr <= nl) return;
        if (ql <= nl && nr <= qr) {
            ope[nidx] = omerge(ope[nidx], e);
            eval(nidx, nr - nl);
            return;
        }

        int nm = (nl + nr) / 2;
        update(ql, qr, e, nidx * 2 + 0, nl, nm);
        update(ql, qr, e, nidx * 2 + 1, nm, nr);

        // update data
        dat[nidx] = dmerge(dat[nidx * 2 + 0], dat[nidx * 2 + 1]);
    }

    void update(int ql, int qr, E e) { return update(ql, qr, e, 1, 0, length); }

    T query(int ql, int qr, int nidx, int nl, int nr) {
        eval(nidx, nr - nl);
        if (nr <= ql || qr <= nl) return d_unit;
        if (ql <= nl && nr <= qr) return dat[nidx];

        int nm = (nl + nr) / 2;
        T vl = query(ql, qr, nidx * 2 + 0, nl, nm);
        T vr = query(ql, qr, nidx * 2 + 1, nm, nr);
        return dmerge(vl, vr);
    }

    T query(int ql, int qr) { return query(ql, qr, 1, 0, length); }

    explicit LazySegmentTree(int n, T d_unit, E o_unit,
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
};
#line 4 "Verify/lazy_segment_tree_add_sum.test.cpp"

#include <iostream>

using lint = long long;

int main() {
    int n, q;
    std::cin >> n >> q;

    LazySegmentTree<lint, lint> seg(
        n, 0, 0,
        [](auto a, auto b) { return a + b; },
        [](auto e, auto f) { return e + f; },
        [](auto a, auto e, int l) { return a + e * l; });

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int l, r;
            lint x;
            std::cin >> l >> r >> x;
            --l, --r;
            seg.update(l, r + 1, x);

        } else {
            int l, r;
            std::cin >> l >> r;
            --l, --r;
            std::cout << seg.query(l, r + 1) << "\n";
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

