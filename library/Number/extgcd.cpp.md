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


# :heavy_check_mark: Number/extgcd.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b2ee912b91d69b435159c7c3f6df7f5f">Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Number/extgcd.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-23 06:50:42+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/extgcd.test.cpp.html">Verify/extgcd.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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
#line 1 "Number/extgcd.cpp"
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

