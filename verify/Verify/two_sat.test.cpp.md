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


# :heavy_check_mark: Verify/two_sat.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/two_sat.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-29 13:22:44+09:00


* see: <a href="https://judge.yosupo.jp/problem/two_sat">https://judge.yosupo.jp/problem/two_sat</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/graph.cpp.html">Graph/graph.cpp</a>
* :heavy_check_mark: <a href="../../library/Graph/strongly_connected_component.cpp.html">Graph/strongly_connected_component.cpp</a>
* :heavy_check_mark: <a href="../../library/Graph/two_sat.cpp.html">Graph/two_sat.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#define __guard__
#include "../Graph/graph.cpp"
#include "../Graph/strongly_connected_component.cpp"
#include "../Graph/two_sat.cpp"
#undef __guard__

#include <iostream>
#include <cmath>
#include <string>

int main() {
    std::string tmp;
    int n, m;
    std::cin >> tmp >> tmp >> n >> m;

    TwoSat ts(n);
    while (m--) {
        int x, y;
        std::cin >> x >> y >> tmp;
        ts.span(std::abs(x) - 1, x > 0, std::abs(y) - 1, y > 0);
    }

    auto assign = ts.exec();
    if (assign.empty()) {
        std::cout << "s UNSATISFIABLE" << std::endl;
    } else {
        std::cout << "s SATISFIABLE" << std::endl;
        std::cout << "v ";
        for (int x = 1; x <= n; ++x) {
            std::cout << (assign[x - 1] ? x : -x) << " ";
        }
        std::cout << "0" << std::endl;
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 170, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 282, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.2/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 257, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: Graph/strongly_connected_component.cpp: line 6: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
