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


# :heavy_check_mark: Graph/kruskal.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/kruskal.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-29 13:22:44+09:00




## Depends on

* :heavy_check_mark: <a href="../DataStructure/union_find.cpp.html">DataStructure/union_find.cpp</a>
* :heavy_check_mark: <a href="graph.cpp.html">Graph/graph.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/kruskal.test.cpp.html">Verify/kruskal.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef __guard__
#define __guard__
#include "graph.cpp"
#include "../DataStructure/union_find.cpp"
#undef __guard__
#endif

#include <algorithm>

template <class Cost>
Cost kruskal(int vnum, std::vector<Edge<Cost>>& edges) {
    std::sort(edges.begin(), edges.end(),
              [](const auto& lhs, const auto& rhs) { return lhs.cost < rhs.cost; });

    UnionFind uf(vnum);
    Cost sum = 0;
    for (const auto& e : edges) {
        if (uf.same(e.src, e.dst)) continue;
        sum += e.cost;
        uf.unite(e.src, e.dst);
    }
    return sum;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: Graph/kruskal.cpp: line 7: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

