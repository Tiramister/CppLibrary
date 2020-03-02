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


# :heavy_check_mark: Verify/segment_tree_rsq.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/Verify/segment_tree_rsq.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-18 18:37:29+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_add_range_sum">https://judge.yosupo.jp/problem/point_add_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/segment_tree.cpp.html">DataStructure/segment_tree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#define __guard__
#include "../DataStructure/segment_tree.cpp"
#undef __guard__

#include <iostream>

using lint = long long;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    SegmentTree<lint> seg(n, 0, [](auto a, auto b) { return a + b; });
    for (int i = 0; i < n; ++i) {
        lint x;
        std::cin >> x;
        seg.update(i, x);
    }

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int i;
            lint x;
            std::cin >> i >> x;
            seg.update(i, seg.query(i, i + 1) + x);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.query(l, r) << "\n";
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/segment_tree_rsq.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#define __guard__
#line 1 "Verify/../DataStructure/segment_tree.cpp"
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

    T query(int ql, int qr) {
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
#line 5 "Verify/segment_tree_rsq.test.cpp"
#undef __guard__

#include <iostream>

using lint = long long;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    SegmentTree<lint> seg(n, 0, [](auto a, auto b) { return a + b; });
    for (int i = 0; i < n; ++i) {
        lint x;
        std::cin >> x;
        seg.update(i, x);
    }

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int i;
            lint x;
            std::cin >> i >> x;
            seg.update(i, seg.query(i, i + 1) + x);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.query(l, r) << "\n";
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

