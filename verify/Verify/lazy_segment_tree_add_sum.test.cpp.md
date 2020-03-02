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


# :heavy_check_mark: Verify/lazy_segment_tree_add_sum.test.cpp

<a href="../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/Verify/lazy_segment_tree_add_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-29 02:37:49+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G</a>


## Depends on

* :heavy_check_mark: <a href="../../library/DataStructure/lazy_segment_tree.cpp.html">DataStructure/lazy_segment_tree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G"

#ifndef __guard__
#define __guard__
#include "../DataStructure/lazy_segment_tree.cpp"
#undef __guard__
#endif

#include <iostream>

using lint = long long;

int main() {
    int n, q;
    std::cin >> n >> q;

    LazySegmentTree<lint, lint> seg(
        n, 0, 0,
        [](auto a, auto b) { return a + b; },
        [](auto e, auto f) { return e + f; },
        [](auto a, auto e, int l) { return a + e * l; });

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int l, r;
            lint x;
            std::cin >> l >> r >> x;
            --l, --r;
            seg.update(l, r + 1, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            --l, --r;
            std::cout << seg.query(l, r + 1) << std::endl;
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 347, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=self.cpp_source_path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 68, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 181, in update
    raise BundleError(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: Verify/lazy_segment_tree_add_sum.test.cpp: line 5: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

