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


# :heavy_check_mark: DataStructure/segment_tree_builtin.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/segment_tree_builtin.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-23 08:32:42+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/DataStructure/Verify/segment_tree_builtin_rsq.test.cpp.html">DataStructure/Verify/segment_tree_builtin_rsq.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "DataStructure/segment_tree_builtin.cpp"
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

