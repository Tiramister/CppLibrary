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


# :warning: Debug/map.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a603905470e2a5b8c13e96b579ef0dba">Debug</a>
* <a href="{{ site.github.repository_url }}/blob/master/Debug/map.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-22 17:40:44+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <map>

template <class K, class T>
std::ostream& operator<<(std::ostream& os, const std::map<K, T>& map) {
    os << "{";
    for (const auto& elem : map) {
        os << "(" << elem.first << "->" << elem.second << "),";
    }
    return os << "}";
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Debug/map.cpp"
#include <iostream>
#include <map>

template <class K, class T>
std::ostream& operator<<(std::ostream& os, const std::map<K, T>& map) {
    os << "{";
    for (const auto& elem : map) {
        os << "(" << elem.first << "->" << elem.second << "),";
    }
    return os << "}";
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

