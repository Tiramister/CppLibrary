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


# :heavy_check_mark: Number/Verify/lcm.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/Number/Verify/lcm.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-22 22:14:42+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C">https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/Number/gcd.cpp.html">Number/gcd.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C"

#include <iostream>
#include "../gcd.cpp"

int main() {
    int n;
    std::cin >> n;

    uint ans = 1;
    for (int i = 0; i < n; ++i) {
        uint a;
        std::cin >> a;
        ans *= a / gcd(ans, a);
    }
    std::cout << ans << std::endl;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Number/Verify/lcm.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C"

#include <iostream>
#line 1 "Number/Verify/../gcd.cpp"
#include <algorithm>

template <class T>
T gcd(T n, T m) {
    while (m != 0) {
        n %= m;
        std::swap(n, m);
    }
    return n;
}
#line 5 "Number/Verify/lcm.test.cpp"

int main() {
    int n;
    std::cin >> n;

    uint ans = 1;
    for (int i = 0; i < n; ++i) {
        uint a;
        std::cin >> a;
        ans *= a / gcd(ans, a);
    }
    std::cout << ans << std::endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

