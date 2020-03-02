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


# :heavy_check_mark: Graph/lowlink.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/lowlink.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-29 14:42:46+09:00




## Depends on

* :heavy_check_mark: <a href="graph.cpp.html">Graph/graph.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/articulation_points.test.cpp.html">Verify/articulation_points.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Verify/bridges.test.cpp.html">Verify/bridges.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef __guard__
#define __guard__
#include "graph.cpp"
#undef __guard__
#endif

template <class Cost = int>
struct Lowlink {
    Graph<Cost> graph;
    int time;
    std::vector<int> order, low;

    std::vector<int> artics;
    std::vector<Edge<Cost>> bridges;

    explicit Lowlink(const Graph<Cost>& graph)
        : graph(graph), order(graph.size(), -1), low(graph.size(), graph.size()) {
        time = 0;
        for (int v = 0; v < (int)graph.size(); ++v) {
            if (order[v] < 0) dfs(v, -1);
        }
    }

    void dfs(int v, int r) {
        order[v] = low[v] = time++;
        int deg = 0;
        bool is_artic = false;

        for (auto e : graph[v]) {
            if (order[e.dst] < 0) {
                ++deg;
                dfs(e.dst, e.src);
                low[e.src] = std::min(low[e.src], low[e.dst]);

                if (order[e.src] <= low[e.dst]) is_artic = true;
                if (order[e.src] < low[e.dst]) bridges.push_back(e);
            } else if (e.dst != r) {
                low[e.src] = std::min(low[e.src], order[e.dst]);
            }
        }

        if (r < 0) is_artic = (deg > 1);
        if (is_artic) artics.push_back(v);
    }
};

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
  File "/opt/hostedtoolcache/Python/3.8.1/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 151, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.languages.cplusplus_bundle.BundleError: Graph/lowlink.cpp: line 6: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

