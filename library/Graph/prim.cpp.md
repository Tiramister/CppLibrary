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


# :heavy_check_mark: Graph/prim.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/prim.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-29 13:23:01+09:00




## Depends on

* :heavy_check_mark: <a href="graph.cpp.html">Graph/graph.cpp</a>
* :heavy_check_mark: <a href="../Misc/heap_alias.cpp.html">Misc/heap_alias.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/prim.test.cpp.html">Verify/prim.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef __guard__
#define __guard__
#include "../Misc/heap_alias.cpp"
#include "graph.cpp"
#undef __guard__
#endif

#include <queue>

template <class Cost, class Cap = int>
Cost prim(const Graph<Cost>& graph) {
    std::vector<bool> used(graph.size(), false);
    used[0] = true;

    MinHeap<Edge<Cost>> heap;
    for (const auto& e : graph[0]) {
        heap.push(e);
    }

    Cost sum = 0;
    while (!heap.empty()) {
        auto e = heap.top();
        heap.pop();
        if (used[e.dst]) continue;

        sum += e.cost;
        used[e.dst] = true;
        for (const auto& se : graph[e.dst]) {
            heap.push(se);
        }
    }
    return sum;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 123, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: Graph/prim.cpp: line 7: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

