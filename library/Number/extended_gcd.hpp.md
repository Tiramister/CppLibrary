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


# :heavy_check_mark: Number/extended_gcd.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b2ee912b91d69b435159c7c3f6df7f5f">Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Number/extended_gcd.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 22:31:04+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/extended_gcd.test.cpp.html">Verify/extended_gcd.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <algorithm>

template <typename T>
T extgcd(T a, T b, T& x, T& y) {
    T s = a, t = b,
      xs = 1, ys = 0,
      xt = 0, yt = 1;

    while (t != 0) {
        T div = s / t;

        s -= t * div;
        xs -= xt * div;
        ys -= yt * div;

        std::swap(s, t);
        std::swap(xs, xt);
        std::swap(ys, yt);
    }

    x = xs;
    y = ys;
    return s;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Number/extended_gcd.hpp"

#include <algorithm>

template <typename T>
T extgcd(T a, T b, T& x, T& y) {
    T s = a, t = b,
      xs = 1, ys = 0,
      xt = 0, yt = 1;

    while (t != 0) {
        T div = s / t;

        s -= t * div;
        xs -= xt * div;
        ys -= yt * div;

        std::swap(s, t);
        std::swap(xs, xt);
        std::swap(ys, yt);
    }

    x = xs;
    y = ys;
    return s;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

