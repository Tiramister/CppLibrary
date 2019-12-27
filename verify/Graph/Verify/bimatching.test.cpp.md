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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: Graph/Verify/bimatching.test.cpp

<a href="../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/Graph/Verify/bimatching.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-28 04:02:17+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_7_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_7_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/Graph/bimatching.cpp.html">Graph/bimatching.cpp</a>
* :heavy_check_mark: <a href="../../../library/Graph/dinic.cpp.html">Graph/dinic.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_7_A"

#define __guard__
#include "../dinic.cpp"
#include "../bimatching.cpp"
#undef __guard__

#include <iostream>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    BiMatching bm(n, m);
    while (k--) {
        int u, v;
        std::cin >> u >> v;
        bm.span(u, v);
    }

    std::cout << bm.exec() << std::endl;
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 328, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 154, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 123, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: Graph/bimatching.cpp: line 6: found codes out of include guard

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

