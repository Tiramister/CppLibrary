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


# :warning: DataStructure/sliding_window_aggregation.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/sliding_window_aggregation.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 22:31:04+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <stack>

template <class M>
struct SlidingWindowAggregation {
    using T = typename M::T;

    std::stack<std::pair<T, T>> front, back;

    explicit SlidingWindowAggregation() = default;

    void push(const T& x) {
        T acc = M::op(back.empty() ? M::id : back.top().second, x);
        back.emplace(x, acc);
    }

    void pop() {
        if (front.empty()) {
            T acc = M::id;
            while (!back.empty()) {
                acc = M::op(back.top().first, acc);
                front.emplace(back.top().first, acc);
                back.pop();
            }
        }
        front.pop();
    }

    T fold() {
        return M::op((front.empty() ? M::id : front.top().second),
                     (back.empty() ? M::id : back.top().second));
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "DataStructure/sliding_window_aggregation.hpp"

#include <stack>

template <class M>
struct SlidingWindowAggregation {
    using T = typename M::T;

    std::stack<std::pair<T, T>> front, back;

    explicit SlidingWindowAggregation() = default;

    void push(const T& x) {
        T acc = M::op(back.empty() ? M::id : back.top().second, x);
        back.emplace(x, acc);
    }

    void pop() {
        if (front.empty()) {
            T acc = M::id;
            while (!back.empty()) {
                acc = M::op(back.top().first, acc);
                front.emplace(back.top().first, acc);
                back.pop();
            }
        }
        front.pop();
    }

    T fold() {
        return M::op((front.empty() ? M::id : front.top().second),
                     (back.empty() ? M::id : back.top().second));
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

