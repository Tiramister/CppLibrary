---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructure/segment_tree.hpp
    title: DataStructure/segment_tree.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/heavy_light_decomposition.hpp
    title: Graph/heavy_light_decomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"Verify/hld_path.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\
    \n\n#line 2 \"DataStructure/segment_tree.hpp\"\n\n#include <vector>\n#include\
    \ <functional>\n\ntemplate <class T>\nstruct SegmentTree {\n    using Merger =\
    \ std::function<T(T, T)>;\n\n    int length;\n    std::vector<T> dat;\n    T unit;\n\
    \    Merger merge;\n\n    SegmentTree() = default;\n\n    SegmentTree(int n, const\
    \ T& unit, const Merger& merge)\n        : length(1), unit(unit), merge(merge)\
    \ {\n        while (length < n) length <<= 1;\n        dat.assign(length * 2,\
    \ unit);\n    }\n\n    template <class Container>\n    SegmentTree(const Container&\
    \ elems, const T& unit, const Merger& merge)\n        : length(1), unit(unit),\
    \ merge(merge) {\n        int n = elems.size();\n        while (length < n) length\
    \ <<= 1;\n\n        dat.assign(length * 2, unit);\n\n        std::copy(elems.begin(),\
    \ elems.end(), dat.begin() + length);\n\n        for (int nidx = length - 1; nidx\
    \ >= 1; --nidx) {\n            T vl = dat[nidx * 2 + 0];\n            T vr = dat[nidx\
    \ * 2 + 1];\n            dat[nidx] = merge(vl, vr);\n        }\n    }\n\n    void\
    \ update(int nidx, const T& elem) {\n        nidx += length;\n        dat[nidx]\
    \ = elem;\n\n        while (nidx > 0) {\n            nidx >>= 1;\n           \
    \ T vl = dat[nidx * 2 + 0];\n            T vr = dat[nidx * 2 + 1];\n         \
    \   dat[nidx] = merge(vl, vr);\n        }\n    }\n\n    T fold(int ql, int qr)\
    \ const {\n        ql = std::max(ql, 0);\n        qr = std::min(qr, length);\n\
    \        ql += length, qr += length;\n\n        T lacc = unit, racc = unit;\n\
    \        while (ql < qr) {\n            if (ql & 1) {\n                lacc =\
    \ merge(lacc, dat[ql]);\n                ++ql;\n            }\n            if\
    \ (qr & 1) {\n                --qr;\n                racc = merge(dat[qr], racc);\n\
    \            }\n            ql >>= 1, qr >>= 1;\n        }\n\n        return merge(lacc,\
    \ racc);\n    }\n\n    T get(int idx) const { return dat[idx + length]; }\n  \
    \  T fold_all() const { return dat[1]; }\n};\n#line 2 \"Graph/heavy_light_decomposition.hpp\"\
    \n\n#line 2 \"Graph/graph.hpp\"\n\n#line 4 \"Graph/graph.hpp\"\n\ntemplate <class\
    \ Cost = int>\nstruct Edge {\n    int src, dst;\n    Cost cost;\n\n    Edge()\
    \ = default;\n    Edge(int src, int dst, Cost cost = 1)\n        : src(src), dst(dst),\
    \ cost(cost){};\n\n    bool operator<(const Edge<Cost>& e) const { return cost\
    \ < e.cost; }\n    bool operator>(const Edge<Cost>& e) const { return cost > e.cost;\
    \ }\n};\n\ntemplate <class Cost = int>\nstruct Graph : public std::vector<std::vector<Edge<Cost>>>\
    \ {\n    Graph(int n = 0) : std::vector<std::vector<Edge<Cost>>>(n) {}\n\n   \
    \ void span(bool direct, int src, int dst, Cost cost = 1) {\n        (*this)[src].emplace_back(src,\
    \ dst, cost);\n        if (!direct) (*this)[dst].emplace_back(dst, src, cost);\n\
    \    }\n};\n#line 4 \"Graph/heavy_light_decomposition.hpp\"\n\n#line 6 \"Graph/heavy_light_decomposition.hpp\"\
    \n\ntemplate <class Cost>\nstruct HeavyLightDecomposition {\n    // indexing\n\
    \    // v: a vertex in original graph\n    // i: assigned label of a vertex\n\n\
    \    Graph<Cost> graph;\n    std::vector<int> id, vs;  // id: v -> i, vs: i ->\
    \ v\n    std::vector<int> par, sz, head, dep, out;\n    // these are all v-indexed\n\
    \    // in equals to id\n    int time;\n\n    explicit HeavyLightDecomposition(const\
    \ Graph<Cost>& graph)\n        : graph(graph),\n          id(graph.size()),\n\
    \          vs(graph.size()),\n          par(graph.size()),\n          sz(graph.size()),\n\
    \          head(graph.size()),\n          dep(graph.size()),\n          out(graph.size()),\n\
    \          time(0) {\n        dfs_sz(0, -1, 0);\n        head[0] = 0;\n      \
    \  dfs_hld(0, -1);\n    }\n\n    void dfs_sz(int v, int p, int d) {\n        par[v]\
    \ = p;\n        sz[v] = 1;\n        dep[v] = d;\n\n        if (!graph[v].empty()\
    \ && graph[v].front().dst == p) {\n            std::swap(graph[v].front(), graph[v].back());\n\
    \        }\n\n        for (auto& e : graph[v]) {\n            if (e.dst == p)\
    \ continue;\n\n            dfs_sz(e.dst, v, d + 1);\n            sz[v] += sz[e.dst];\n\
    \n            // heavy edge first\n            if (sz[graph[v].front().dst] <\
    \ sz[e.dst]) {\n                std::swap(graph[v].front(), e);\n            }\n\
    \        }\n    }\n\n    void dfs_hld(int v, int p) {\n        id[v] = time++;\n\
    \        vs[id[v]] = v;\n\n        bool first = true;\n        for (auto e : graph[v])\
    \ {\n            if (e.dst == p) continue;\n\n            head[e.dst] = (first\
    \ ? head[v] : e.dst);\n            first = false;\n            dfs_hld(e.dst,\
    \ v);\n        }\n\n        out[v] = time;\n    }\n\n    int lca(int u, int v)\
    \ {\n        while (true) {\n            if (id[u] > id[v]) std::swap(u, v);\n\
    \            if (head[u] == head[v]) return u;\n            v = par[head[v]];\n\
    \        }\n    }\n\n    int dist(int u, int v) {\n        return dep[u] + dep[v]\
    \ - dep[lca(u, v)] * 2;\n    }\n\n    std::vector<std::pair<int, int>> path(int\
    \ u, int v, bool is_edge) {\n        std::vector<std::pair<int, int>> segs;\n\n\
    \        while (true) {\n            if (id[u] > id[v]) std::swap(u, v);\n\n \
    \           if (head[u] == head[v]) {\n                // when edge path, the\
    \ lca has to be excluded\n                segs.emplace_back(id[u] + is_edge, id[v]\
    \ + 1);\n                return segs;\n            }\n\n            segs.emplace_back(id[head[v]],\
    \ id[v] + 1);\n            v = par[head[v]];\n        }\n    }\n\n    std::pair<int,\
    \ int> subtree(int v, bool is_edge) {\n        // when edge path, the root has\
    \ to be excluded\n        return {id[v] + is_edge, out[v]};\n    }\n};\n#line\
    \ 5 \"Verify/hld_path.test.cpp\"\n\n#include <iostream>\n\nusing lint = long long;\n\
    \nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \n    int n, q;\n    std::cin >> n >> q;\n\n    std::vector<lint> xs(n);\n   \
    \ for (auto& x : xs) std::cin >> x;\n\n    Graph<> graph(n);\n    for (int i =\
    \ n - 1; i--;) {\n        int u, v;\n        std::cin >> u >> v;\n        graph.span(false,\
    \ u, v);\n    }\n\n    HeavyLightDecomposition hld(graph);\n    {\n        auto\
    \ pxs = xs;\n        for (int i = 0; i < n; ++i) xs[i] = pxs[hld.vs[i]];\n   \
    \ }\n\n    SegmentTree<lint> seg(xs, 0, [](auto a, auto b) { return a + b; });\n\
    \n    while (q--) {\n        int t;\n        std::cin >> t;\n\n        switch\
    \ (t) {\n            case 0: {\n                int v, x;\n                std::cin\
    \ >> v >> x;\n\n                int i = hld.id[v];\n                seg.update(i,\
    \ seg.get(i) + x);\n                break;\n            }\n            case 1:\
    \ {\n                int u, v;\n                std::cin >> u >> v;\n\n      \
    \          lint sum = 0;\n                for (auto [l, r] : hld.path(u, v, false))\
    \ {\n                    sum += seg.fold(l, r);\n                }\n         \
    \       std::cout << sum << \"\\n\";\n                break;\n            }\n\
    \        }\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../DataStructure/segment_tree.hpp\"\n#include \"../Graph/heavy_light_decomposition.hpp\"\
    \n\n#include <iostream>\n\nusing lint = long long;\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n\n    int n, q;\n    std::cin >> n >>\
    \ q;\n\n    std::vector<lint> xs(n);\n    for (auto& x : xs) std::cin >> x;\n\n\
    \    Graph<> graph(n);\n    for (int i = n - 1; i--;) {\n        int u, v;\n \
    \       std::cin >> u >> v;\n        graph.span(false, u, v);\n    }\n\n    HeavyLightDecomposition\
    \ hld(graph);\n    {\n        auto pxs = xs;\n        for (int i = 0; i < n; ++i)\
    \ xs[i] = pxs[hld.vs[i]];\n    }\n\n    SegmentTree<lint> seg(xs, 0, [](auto a,\
    \ auto b) { return a + b; });\n\n    while (q--) {\n        int t;\n        std::cin\
    \ >> t;\n\n        switch (t) {\n            case 0: {\n                int v,\
    \ x;\n                std::cin >> v >> x;\n\n                int i = hld.id[v];\n\
    \                seg.update(i, seg.get(i) + x);\n                break;\n    \
    \        }\n            case 1: {\n                int u, v;\n               \
    \ std::cin >> u >> v;\n\n                lint sum = 0;\n                for (auto\
    \ [l, r] : hld.path(u, v, false)) {\n                    sum += seg.fold(l, r);\n\
    \                }\n                std::cout << sum << \"\\n\";\n           \
    \     break;\n            }\n        }\n    }\n\n    return 0;\n}\n"
  dependsOn:
  - DataStructure/segment_tree.hpp
  - Graph/heavy_light_decomposition.hpp
  - Graph/graph.hpp
  isVerificationFile: true
  path: Verify/hld_path.test.cpp
  requiredBy: []
  timestamp: '2020-11-04 08:09:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/hld_path.test.cpp
layout: document
redirect_from:
- /verify/Verify/hld_path.test.cpp
- /verify/Verify/hld_path.test.cpp.html
title: Verify/hld_path.test.cpp
---
