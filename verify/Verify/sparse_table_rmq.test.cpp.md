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


# :heavy_check_mark: Verify/sparse_table_rmq.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/sparse_table_rmq.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 22:31:04+09:00


* see: <a href="https://judge.yosupo.jp/problem/staticrmq">https://judge.yosupo.jp/problem/staticrmq</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/sparse_table.hpp.html">DataStructure/sparse_table.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../DataStructure/sparse_table.hpp"

#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    SparseTable<int> st(xs, [](auto a, auto b) { return std::min(a, b); });

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << st.fold(l, r) << "\n";
    }

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/sparse_table_rmq.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#line 2 "DataStructure/sparse_table.hpp"

#include <vector>
#include <functional>

template <class T>
struct SparseTable {
    using Merger = std::function<T(T, T)>;

    int length;
    std::vector<std::vector<T>> table;
    Merger merge;
    std::vector<int> logs;

    SparseTable(const std::vector<T>& dat, const Merger& merge)
        : length(dat.size()), table{dat}, merge(merge), logs(length + 1) {
        int kmax = 0;
        for (int d = 0; d <= length; ++d) {
            if (d >= (1 << (kmax + 1))) ++kmax;
            logs[d] = kmax;
        }

        table.resize(kmax + 1);
        for (int k = 1; k <= kmax; ++k) {
            table[k].resize(length - (1 << k) + 1);
            for (int i = 0; i + (1 << k) <= length; ++i) {
                table[k][i] = merge(table[k - 1][i],
                                    table[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    T fold(int l, int r) {
        l = std::max(l, 0);
        r = std::min(r, length);

        int k = logs[r - l];
        return merge(table[k][l], table[k][r - (1 << k)]);
    }
};
#line 4 "Verify/sparse_table_rmq.test.cpp"

#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    SparseTable<int> st(xs, [](auto a, auto b) { return std::min(a, b); });

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << st.fold(l, r) << "\n";
    }

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
