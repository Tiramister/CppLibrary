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


# :heavy_check_mark: Graph/graph.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#4cdbd2bafa8193091ba09509cedf94fd">Graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/Graph/graph.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-29 13:22:44+09:00




## Required by

* :heavy_check_mark: <a href="bellman_ford.cpp.html">Graph/bellman_ford.cpp</a>
* :heavy_check_mark: <a href="centroid_decomposition.cpp.html">Graph/centroid_decomposition.cpp</a>
* :heavy_check_mark: <a href="dijkstra.cpp.html">Graph/dijkstra.cpp</a>
* :heavy_check_mark: <a href="kruskal.cpp.html">Graph/kruskal.cpp</a>
* :heavy_check_mark: <a href="lowlink.cpp.html">Graph/lowlink.cpp</a>
* :heavy_check_mark: <a href="prim.cpp.html">Graph/prim.cpp</a>
* :heavy_check_mark: <a href="strongly_connected_component.cpp.html">Graph/strongly_connected_component.cpp</a>
* :heavy_check_mark: <a href="topological_sort.cpp.html">Graph/topological_sort.cpp</a>
* :heavy_check_mark: <a href="two_sat.cpp.html">Graph/two_sat.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/articulation_points.test.cpp.html">Verify/articulation_points.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Verify/bellman_ford.test.cpp.html">Verify/bellman_ford.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Verify/bridges.test.cpp.html">Verify/bridges.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Verify/centroid_decomposition_diameter.test.cpp.html">Verify/centroid_decomposition_diameter.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Verify/dijkstra.test.cpp.html">Verify/dijkstra.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Verify/kruskal.test.cpp.html">Verify/kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Verify/prim.test.cpp.html">Verify/prim.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Verify/strongly_connected_component.test.cpp.html">Verify/strongly_connected_component.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Verify/topological_sort.test.cpp.html">Verify/topological_sort.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/Verify/two_sat.test.cpp.html">Verify/two_sat.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>

template <class Cost = int>
struct Edge {
    int src, dst;
    Cost cost;
    Edge(int src = -1, int dst = -1, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return this->cost > e.cost; }
};

template <class Cost = int>
using Edges = std::vector<Edge<Cost>>;

template <class Cost = int>
using Graph = std::vector<std::vector<Edge<Cost>>>;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Graph/graph.cpp"
#include <vector>

template <class Cost = int>
struct Edge {
    int src, dst;
    Cost cost;
    Edge(int src = -1, int dst = -1, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return this->cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return this->cost > e.cost; }
};

template <class Cost = int>
using Edges = std::vector<Edge<Cost>>;

template <class Cost = int>
using Graph = std::vector<std::vector<Edge<Cost>>>;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

