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


# :heavy_check_mark: Verify/gcd.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/Verify/gcd.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-29 02:37:49+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B">https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Number/gcd.cpp.html">Number/gcd.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B"

#define __guard__
#include "../Number/gcd.cpp"
#undef __guard__

#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;
    std::cout << gcd(x, y) << std::endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/gcd.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B"

#define __guard__
#line 1 "Verify/../Number/gcd.cpp"
#include <algorithm>

template <class T>
T gcd(T n, T m) {
    while (m != 0) {
        n %= m;
        std::swap(n, m);
    }
    return n;
}
#line 5 "Verify/gcd.test.cpp"
#undef __guard__

#include <iostream>

int main() {
    int x, y;
    std::cin >> x >> y;
    std::cout << gcd(x, y) << std::endl;
    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

