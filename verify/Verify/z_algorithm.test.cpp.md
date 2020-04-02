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


# :heavy_check_mark: Verify/z_algorithm.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/z_algorithm.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-03 05:11:30+09:00


* see: <a href="https://judge.yosupo.jp/problem/zalgorithm">https://judge.yosupo.jp/problem/zalgorithm</a>


## Depends on

* :heavy_check_mark: <a href="../../library/String/z_algorithm.cpp.html">String/z_algorithm.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#define __guard__
#include "../String/z_algorithm.cpp"
#undef __guard__

#include <iostream>
#include <string>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    auto ans = zalgo(s);
    for (auto a : ans) std::cout << a << " ";
    std::cout << std::endl;

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/z_algorithm.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#define __guard__
#line 1 "String/z_algorithm.cpp"
#include <vector>

template <class Container>
std::vector<int> zalgo(const Container& dat) {
    int n = dat.size();

    std::vector<int> ret(n);
    ret[0] = n;

    int i = 1, len = 0;
    while (i < n) {
        while (i + len < n && dat[len] == dat[i + len]) {
            ++len;
        }
        ret[i] = len;

        if (len == 0) {
            ++i;
            continue;
        }

        int nlen = 1;
        while (i + nlen < n && nlen + ret[nlen] < len) {
            ret[i + nlen] = ret[nlen];
            ++nlen;
        }

        i += nlen;
        len -= nlen;
    }

    return ret;
}
#line 5 "Verify/z_algorithm.test.cpp"
#undef __guard__

#include <iostream>
#include <string>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    auto ans = zalgo(s);
    for (auto a : ans) std::cout << a << " ";
    std::cout << std::endl;

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

