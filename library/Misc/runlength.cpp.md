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


# :warning: Misc/runlength.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#74248c725e00bf9fe04df4e35b249a19">Misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/Misc/runlength.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-19 01:37:19+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <string>

std::vector<std::pair<char, int>> runlength(const std::string& s) {
    std::vector<std::pair<char, int>> res;
    for (char c : s) {
        if (res.empty() || c != res.back().first) {
            res.emplace_back(c, 1);
        } else {
            ++res.back().second;
        }
    }
    return res;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Misc/runlength.cpp"
#include <vector>
#include <string>

std::vector<std::pair<char, int>> runlength(const std::string& s) {
    std::vector<std::pair<char, int>> res;
    for (char c : s) {
        if (res.empty() || c != res.back().first) {
            res.emplace_back(c, 1);
        } else {
            ++res.back().second;
        }
    }
    return res;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

