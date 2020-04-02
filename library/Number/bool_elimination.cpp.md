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


# :warning: Number/bool_elimination.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b2ee912b91d69b435159c7c3f6df7f5f">Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Number/bool_elimination.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 22:05:02+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <algorithm>
#include <vector>

void bool_elimination(std::vector<std::vector<int>>& mat) {
    int n = mat.size(), m = mat.front().size();

    for (int l = 0; l < n; ++l) {
        {
            auto& v = *std::max_element(mat.begin() + l, mat.end());
            std::swap(v, mat[l]);
        }

        const auto& v = mat[l];
        for (int i = l + 1; i < n; ++i) {
            auto u = mat[i];
            for (int j = 0; j < m; ++j) u[j] ^= v[j];
            if (u < mat[i]) std::swap(u, mat[i]);
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Number/bool_elimination.cpp"
#include <algorithm>
#include <vector>

void bool_elimination(std::vector<std::vector<int>>& mat) {
    int n = mat.size(), m = mat.front().size();

    for (int l = 0; l < n; ++l) {
        {
            auto& v = *std::max_element(mat.begin() + l, mat.end());
            std::swap(v, mat[l]);
        }

        const auto& v = mat[l];
        for (int i = l + 1; i < n; ++i) {
            auto u = mat[i];
            for (int j = 0; j < m; ++j) u[j] ^= v[j];
            if (u < mat[i]) std::swap(u, mat[i]);
        }
    }
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

