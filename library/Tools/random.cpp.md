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


# :warning: Tools/random.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8625e1de7be14c39b1d14dc03d822497">Tools</a>
* <a href="{{ site.github.repository_url }}/blob/master/Tools/random.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 22:58:51+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <chrono>

struct Random {
    using ulint = uint64_t;
    ulint x;

    explicit Random() {
        x = std::chrono::steady_clock::now()
                .time_since_epoch()
                .count();
    }

    ulint next() {
        x ^= (x << 13);
        x ^= (x >> 7);
        x ^= (x << 17);
        return x;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Tools/random.cpp"

#include <chrono>

struct Random {
    using ulint = uint64_t;
    ulint x;

    explicit Random() {
        x = std::chrono::steady_clock::now()
                .time_since_epoch()
                .count();
    }

    ulint next() {
        x ^= (x << 13);
        x ^= (x >> 7);
        x ^= (x << 17);
        return x;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

