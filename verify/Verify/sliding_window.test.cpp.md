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


# :heavy_check_mark: Verify/sliding_window.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/sliding_window.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 22:58:51+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/sliding_window.cpp.html">DataStructure/sliding_window.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D"

#include "../DataStructure/sliding_window.cpp"

#include <iostream>

int main() {
    int n, l;
    std::cin >> n >> l;

    SlidingWindow<int> sw([](int lhs, int rhs) { return lhs <= rhs; });

    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        sw.push(a);
        if (i >= l - 1) {
            std::cout << sw.get() << " \n"[i == n - 1];
            sw.pop();
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/sliding_window.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D"

#line 2 "DataStructure/sliding_window.cpp"

#include <deque>
#include <functional>

template <class T>
struct SlidingWindow {
    using Cmp = std::function<bool(T, T)>;

    std::deque<std::pair<T, int>> window;
    Cmp cmp;
    int l, r;

    explicit SlidingWindow(Cmp cmp)
        : window(), cmp(cmp), l(0), r(0) {}

    void push(T val) {
        while (!window.empty() && cmp(val, window.back().first)) {
            window.pop_back();
        }
        window.emplace_back(val, r++);
    }

    T get() {
        return window.front().first;
    }

    void pop() {
        if (window.front().second == l++) {
            window.pop_front();
        }
    }
};
#line 4 "Verify/sliding_window.test.cpp"

#include <iostream>

int main() {
    int n, l;
    std::cin >> n >> l;

    SlidingWindow<int> sw([](int lhs, int rhs) { return lhs <= rhs; });

    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        sw.push(a);
        if (i >= l - 1) {
            std::cout << sw.get() << " \n"[i == n - 1];
            sw.pop();
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

