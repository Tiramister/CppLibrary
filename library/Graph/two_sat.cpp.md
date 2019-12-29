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


# :heavy_check_mark: Graph/two_sat.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/two_sat.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-29 13:22:44+09:00




## Depends on

* :heavy_check_mark: <a href="graph.cpp.html">Graph/graph.cpp</a>
* :heavy_check_mark: <a href="strongly_connected_component.cpp.html">Graph/strongly_connected_component.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/two_sat.test.cpp.html">Verify/two_sat.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef __guard__
#define __guard__
#include "graph.cpp"
#include "strongly_connected_component.cpp"
#undef __guard__
#endif

struct TwoSat {
    int vnum;
    Graph<> graph;

    explicit TwoSat(int n) : vnum(n), graph(n * 2) {}

    // t=1 <=> true
    int enc(int x, bool t) {
        return x + (t ? vnum : 0);
    }

    // [tx]x V [ty]y
    void span(int x, bool tx, int y, bool ty) {
        graph[enc(x, !tx)].emplace_back(enc(x, !tx), enc(y, ty));
        graph[enc(y, !ty)].emplace_back(enc(y, !ty), enc(x, tx));
    }

    // if unsatisfiable, return an empty vector
    std::vector<bool> exec() {
        StronglyConnectedComponents scc(graph);

        std::vector<bool> assign(vnum);
        for (int x = 0; x < vnum; ++x) {
            int fid = scc.id[enc(x, false)],
                tid = scc.id[enc(x, true)];

            if (fid == tid) {
                return std::vector<bool>();
            } else {
                assign[x] = (fid < tid);
            }
        }
        return assign;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 154, in update
    self.update(self._resolve(included, included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 123, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: Graph/strongly_connected_component.cpp: line 6: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

