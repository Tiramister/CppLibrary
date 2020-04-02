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


# :heavy_check_mark: DataStructure/sliding_window.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/sliding_window.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 22:58:51+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/sliding_window.test.cpp.html">Verify/sliding_window.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

