---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/dinic.hpp
    title: Graph/dinic.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: Verify/bipartite_matching.test.cpp
    title: Verify/bipartite_matching.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Graph/bipartite_matching.hpp\"\n\n#line 2 \"Graph/dinic.hpp\"\
    \n\n#include <vector>\n#include <queue>\n#include <limits>\n\ntemplate <class\
    \ Cap, bool isDirect>\nstruct MaxFlow {\n    struct Edge {\n        int src, dst;\n\
    \        Cap cap;\n        Edge(int src, int dst, Cap cap)\n            : src(src),\
    \ dst(dst), cap(cap){};\n    };\n\n    std::vector<Edge> edges;\n    std::vector<std::vector<int>>\
    \ graph;\n    std::vector<int> dist, iter;\n\n    explicit MaxFlow(int n) : graph(n),\
    \ dist(n), iter(n) {}\n\n    void span(int u, int v, Cap cap) {\n        graph[u].push_back(edges.size());\n\
    \        edges.emplace_back(u, v, cap);\n\n        graph[v].push_back(edges.size());\n\
    \        edges.emplace_back(v, u, (isDirect ? 0 : cap));\n    }\n\n    void bfs(int\
    \ s) {\n        std::fill(dist.begin(), dist.end(), -1);\n        dist[s] = 0;\n\
    \        std::queue<int> que;\n        que.push(s);\n\n        while (!que.empty())\
    \ {\n            auto v = que.front();\n            que.pop();\n\n           \
    \ for (auto eidx : graph[v]) {\n                const auto& edge = edges[eidx];\n\
    \n                if (edge.cap > 0 && dist[edge.dst] == -1) {\n              \
    \      dist[edge.dst] = dist[v] + 1;\n                    que.push(edge.dst);\n\
    \                }\n            }\n        }\n    }\n\n    Cap dfs(int v, int\
    \ g, Cap f) {\n        if (v == g) return f;\n\n        for (auto& itr = iter[v];\
    \ itr < (int)graph[v].size(); ++itr) {\n            auto eidx = graph[v][itr];\n\
    \            auto& edge = edges[eidx];\n\n            if (edge.cap > 0 && dist[v]\
    \ < dist[edge.dst]) {\n                auto df = dfs(edge.dst, g, std::min(f,\
    \ edge.cap));\n\n                if (df > 0) {\n                    edge.cap -=\
    \ df;\n                    auto& redge = edges[eidx ^ 1];\n                  \
    \  redge.cap += df;\n                    return df;\n                }\n     \
    \       }\n        }\n        return 0;\n    }\n\n    Cap flow(int s, int g) {\n\
    \        const Cap INF = std::numeric_limits<Cap>::max();\n\n        Cap ret =\
    \ 0;\n        while (true) {\n            bfs(s);\n            if (dist[g] < 0)\
    \ return ret;\n\n            std::fill(iter.begin(), iter.end(), 0);\n       \
    \     while (true) {\n                Cap f = dfs(s, g, INF);\n              \
    \  if (f == 0) break;\n                ret += f;\n            }\n        }\n \
    \   }\n};\n#line 4 \"Graph/bipartite_matching.hpp\"\n\nstruct BipartiteMatching\
    \ {\n    MaxFlow<int, true> mf;\n    int n, m, s, g;\n\n    int enc(int v, bool\
    \ side) const { return v + (side ? n : 0); }\n\n    explicit BipartiteMatching(int\
    \ n, int m)\n        : mf(n + m + 2), n(n), m(m), s(n + m), g(n + m + 1) {\n \
    \       for (int u = 0; u < n; ++u) {\n            mf.span(s, enc(u, false), 1);\n\
    \        }\n        for (int v = 0; v < m; ++v) {\n            mf.span(enc(v,\
    \ true), g, 1);\n        }\n    }\n\n    void span(int u, int v) {\n        mf.span(enc(u,\
    \ false), enc(v, true), 1);\n    }\n\n    int size() { return mf.flow(s, g); }\n\
    \n    std::vector<std::pair<int, int>> matching() {\n        mf.flow(s, g);\n\n\
    \        std::vector<std::pair<int, int>> ret;\n        for (auto e : mf.edges)\
    \ {\n            if (e.src < e.dst &&\n                e.src < n && e.dst < n\
    \ + m &&\n                e.cap == 0) {\n                ret.emplace_back(e.src,\
    \ e.dst - n);\n            }\n        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n\n#include \"dinic.hpp\"\n\nstruct BipartiteMatching {\n  \
    \  MaxFlow<int, true> mf;\n    int n, m, s, g;\n\n    int enc(int v, bool side)\
    \ const { return v + (side ? n : 0); }\n\n    explicit BipartiteMatching(int n,\
    \ int m)\n        : mf(n + m + 2), n(n), m(m), s(n + m), g(n + m + 1) {\n    \
    \    for (int u = 0; u < n; ++u) {\n            mf.span(s, enc(u, false), 1);\n\
    \        }\n        for (int v = 0; v < m; ++v) {\n            mf.span(enc(v,\
    \ true), g, 1);\n        }\n    }\n\n    void span(int u, int v) {\n        mf.span(enc(u,\
    \ false), enc(v, true), 1);\n    }\n\n    int size() { return mf.flow(s, g); }\n\
    \n    std::vector<std::pair<int, int>> matching() {\n        mf.flow(s, g);\n\n\
    \        std::vector<std::pair<int, int>> ret;\n        for (auto e : mf.edges)\
    \ {\n            if (e.src < e.dst &&\n                e.src < n && e.dst < n\
    \ + m &&\n                e.cap == 0) {\n                ret.emplace_back(e.src,\
    \ e.dst - n);\n            }\n        }\n        return ret;\n    }\n};\n"
  dependsOn:
  - Graph/dinic.hpp
  isVerificationFile: false
  path: Graph/bipartite_matching.hpp
  requiredBy: []
  timestamp: '2020-11-03 10:32:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - Verify/bipartite_matching.test.cpp
documentation_of: Graph/bipartite_matching.hpp
layout: document
redirect_from:
- /library/Graph/bipartite_matching.hpp
- /library/Graph/bipartite_matching.hpp.html
title: Graph/bipartite_matching.hpp
---
