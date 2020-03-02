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


# :heavy_check_mark: String/z_algorithm.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#27118326006d3829667a400ad23d5d98">String</a>
* <a href="{{ site.github.repository_url }}/blob/master/String/z_algorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2020-03-03 04:24:18+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/z_algorithm.test.cpp.html">Verify/z_algorithm.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

