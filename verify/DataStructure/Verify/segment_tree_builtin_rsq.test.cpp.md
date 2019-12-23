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


# :heavy_check_mark: DataStructure/Verify/segment_tree_builtin_rsq.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/Verify/segment_tree_builtin_rsq.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-23 08:32:42+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/DataStructure/segment_tree_builtin.cpp.html">DataStructure/segment_tree_builtin.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"

#include <iostream>
#include "../segment_tree_builtin.cpp"

int main() {
    int n;
    std::cin >> n;
    SegmentTree<int> seg(n);

    int q;
    std::cin >> q;
    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int i, x;
            std::cin >> i >> x;
            --i;
            seg.update(i, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.query(l - 1, r) << std::endl;
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/Verify/segment_tree_builtin_rsq.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"

#include <iostream>
#line 1 "DataStructure/Verify/../segment_tree_builtin.cpp"
#include <vector>

// update: add
// query : sum
// unit  : 0
template <class T>
struct SegmentTree {
    int length;
    std::vector<T> dat;
    T unit = 0;  // unit

    explicit SegmentTree(int n) : length(1) {
        while (length < n) {
            length <<= 1;
        }
        dat.assign(length * 2 - 1, unit);
    }

    T query(int ql, int qr, int nidx, int nl, int nr) {
        if (nr <= ql || qr <= nl) return unit;
        if (ql <= nl && nr <= qr) return dat[nidx];

        int nm = (nl + nr) / 2;
        T vl = query(ql, qr, nidx * 2 + 1, nl, nm);
        T vr = query(ql, qr, nidx * 2 + 2, nm, nr);
        return vl + vr;  // query
    }

    T query(int ql, int qr) { return query(ql, qr, 0, 0, length); }

    void update(int nidx, T elem) {
        nidx += length - 1;
        dat[nidx] += elem;  // update

        while (nidx > 0) {
            nidx = (nidx - 1) >> 1;
            T vl = dat[nidx * 2 + 1];
            T vr = dat[nidx * 2 + 2];
            dat[nidx] = vl + vr;  // query
        }
    }
};
#line 5 "DataStructure/Verify/segment_tree_builtin_rsq.test.cpp"

int main() {
    int n;
    std::cin >> n;
    SegmentTree<int> seg(n);

    int q;
    std::cin >> q;
    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int i, x;
            std::cin >> i >> x;
            --i;
            seg.update(i, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.query(l - 1, r) << std::endl;
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

