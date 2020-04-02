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


# :heavy_check_mark: Verify/centroid_decomposition_diameter.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/centroid_decomposition_diameter.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-02-13 16:35:43+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Graph/centroid_decomposition.cpp.html">Graph/centroid_decomposition.cpp</a>
* :heavy_check_mark: <a href="../../library/Graph/graph.cpp.html">Graph/graph.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A"

#define __guard__
#include "../Graph/graph.cpp"
#include "../Graph/centroid_decomposition.cpp"
#undef __guard__

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

int main() {
    int n;
    std::cin >> n;

    Graph<int> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u].emplace_back(u, v, w);
        graph[v].emplace_back(v, u, w);
    }

    Centroid<int> cent(graph);

    int ans = 0;
    std::queue<int> cents;
    cents.push(0);

    std::vector<int> dist(n);
    while (!cents.empty()) {
        int r = cents.front();
        cents.pop();
        r = cent.find(r);
        cent.deleted[r] = true;

        std::vector<int> fars({0, 0});
        for (auto e : graph[r]) {
            if (cent.deleted[e.dst]) continue;
            cents.push(e.dst);

            // BFS
            std::queue<std::pair<int, int>> que;
            que.emplace(e.dst, -1);
            dist[e.dst] = e.cost;

            int far = 0;
            while (!que.empty()) {
                int v, p;
                std::tie(v, p) = que.front();
                que.pop();
                far = std::max(far, dist[v]);

                for (auto f : graph[v]) {
                    if (f.dst == p || cent.deleted[f.dst]) continue;
                    dist[f.dst] = dist[v] + f.cost;
                    que.emplace(f.dst, v);
                }
            }
            fars.push_back(far);
        }

        std::sort(fars.rbegin(), fars.rend());
        if (fars.size() >= 2) ans = std::max(ans, fars[0] + fars[1]);
    }

    std::cout << ans << std::endl;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleError: Graph/centroid_decomposition.cpp: line 6: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
