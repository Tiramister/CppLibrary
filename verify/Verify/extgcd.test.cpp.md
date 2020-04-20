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


# :heavy_check_mark: Verify/extgcd.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/extgcd.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 23:42:37+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E">https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Number/extgcd.cpp.html">Number/extgcd.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E"

#include "../Number/extgcd.cpp"

#include <iostream>
#include <cassert>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int a, b;
    std::cin >> a >> b;

    int x, y;
    int g = extgcd(a, b, x, y);
    assert(a * x + b * y == g);

    std::cout << x << " " << y << "\n";
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/extgcd.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E"

#line 2 "Number/extgcd.cpp"

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
#line 4 "Verify/extgcd.test.cpp"

#include <iostream>
#include <cassert>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int a, b;
    std::cin >> a >> b;

    int x, y;
    int g = extgcd(a, b, x, y);
    assert(a * x + b * y == g);

    std::cout << x << " " << y << "\n";
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

