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


# :heavy_check_mark: Graph/bimatching.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/bimatching.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-29 00:18:07+09:00




## Depends on

* :heavy_check_mark: <a href="dinic.cpp.html">Graph/dinic.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/bimatching.test.cpp.html">Verify/bimatching.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef __guard__
#define __guard__
#include "dinic.cpp"
#undef __guard__
#endif

struct BiMatching {
    MaxFlow<int, true> mf;
    int n, m, s, g;

    explicit BiMatching(int n, int m)
        : mf(n + m + 2), n(n), m(m), s(n + m), g(n + m + 1) {
        for (int u = 0; u < n; ++u) {
            mf.span(s, enc(u, false), 1);
        }
        for (int v = 0; v < m; ++v) {
            mf.span(enc(v, true), g, 1);
        }
    }

    int enc(int v, bool side) {
        return v + (side ? n : 0);
    }

    void span(int u, int v) {
        mf.span(enc(u, false), enc(v, true), 1);
    }

    int exec() {
        return mf.exec(s, g);
    }

    std::vector<std::pair<int, int>> matching() {
        mf.exec(s, g);
        std::vector<std::pair<int, int>> ret;
        for (auto e : mf.edges) {
            if (e.src < e.dst &&
                e.src < n && e.dst < n + m &&
                e.cap == 0) {
                ret.emplace_back(e.src, e.dst - n);
            }
        }
        return ret;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 343, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 63, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: Graph/bimatching.cpp: line 6: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

