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


# :heavy_check_mark: Tools/heap_alias.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8625e1de7be14c39b1d14dc03d822497">Tools</a>
* <a href="{{ site.github.repository_url }}/blob/master/Tools/heap_alias.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 22:58:51+09:00




## Required by

* :heavy_check_mark: <a href="../Graph/dijkstra.cpp.html">Graph/dijkstra.cpp</a>
* :heavy_check_mark: <a href="../Graph/prim.cpp.html">Graph/prim.cpp</a>
* :heavy_check_mark: <a href="../Graph/primal_dual.cpp.html">Graph/primal_dual.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/dijkstra.test.cpp.html">Verify/dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Verify/prim.test.cpp.html">Verify/prim.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Verify/primal_dual.test.cpp.html">Verify/primal_dual.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <queue>

template <class T>
using MaxHeap = std::priority_queue<T>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Tools/heap_alias.cpp"

#include <queue>

template <class T>
using MaxHeap = std::priority_queue<T>;
template <class T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

