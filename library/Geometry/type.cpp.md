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


# :warning: Geometry/type.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d9c6333623e6357515fcbf17be806273">Geometry</a>
* <a href="{{ site.github.repository_url }}/blob/master/Geometry/type.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-21 00:48:01+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <cmath>

using Real = long double;
constexpr Real EPS = 1e-10L;
constexpr Real PI = 3.14159265358979323846L;

template <class T>
T sq(T x) { return x * x; }

int compare(Real a, Real b) {
    if (std::abs(a - b) < EPS) return 0;
    return a - b > 0 ? 1 : -1;
}

Real deg2rad(Real theta) { return theta / 180 * PI; }
Real rad2deg(Real theta) { return theta / PI * 180; }

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Geometry/type.cpp"

#include <cmath>

using Real = long double;
constexpr Real EPS = 1e-10L;
constexpr Real PI = 3.14159265358979323846L;

template <class T>
T sq(T x) { return x * x; }

int compare(Real a, Real b) {
    if (std::abs(a - b) < EPS) return 0;
    return a - b > 0 ? 1 : -1;
}

Real deg2rad(Real theta) { return theta / 180 * PI; }
Real rad2deg(Real theta) { return theta / PI * 180; }

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

