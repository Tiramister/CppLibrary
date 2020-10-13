---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/bipartite_matching.hpp
    title: Graph/bipartite_matching.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/dinic.hpp
    title: Graph/dinic.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"Verify/bipartite_matching.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/bipartitematching\"\n\n#line 2 \"Graph/bipartite_matching.hpp\"\
    \n\n#line 2 \"Graph/dinic.hpp\"\n\n#include <vector>\n#include <queue>\n#include\
    \ <limits>\n\ntemplate <class Cap, bool isDirect>\nstruct MaxFlow {\n    struct\
    \ Edge {\n        int src, dst;\n        Cap cap;\n        Edge(int src, int dst,\
    \ Cap cap)\n            : src(src), dst(dst), cap(cap){};\n    };\n\n    using\
    \ Edges = std::vector<Edge>;\n    using Graph = std::vector<std::vector<int>>;\n\
    \n    Edges edges;\n    Graph graph;\n    std::vector<int> dist, iter;\n\n   \
    \ explicit MaxFlow(int n)\n        : graph(n), dist(n), iter(n) {}\n\n    void\
    \ span(int u, int v, Cap cap) {\n        graph[u].push_back(edges.size());\n \
    \       edges.emplace_back(u, v, cap);\n\n        graph[v].push_back(edges.size());\n\
    \        edges.emplace_back(v, u, (isDirect ? 0 : cap));\n    }\n\n    void bfs(int\
    \ s) {\n        std::fill(dist.begin(), dist.end(), -1);\n        dist[s] = 0;\n\
    \        std::queue<int> que;\n        que.push(s);\n\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n\n            for\
    \ (int eidx : graph[v]) {\n                const auto& edge = edges[eidx];\n\n\
    \                if (edge.cap > 0 && dist[edge.dst] < 0) {\n                 \
    \   dist[edge.dst] = dist[v] + 1;\n                    que.push(edge.dst);\n \
    \               }\n            }\n        }\n    }\n\n    int dfs(int v, int g,\
    \ Cap f) {\n        if (v == g) return f;\n\n        for (int& itr = iter[v];\
    \ itr < (int)graph[v].size(); ++itr) {\n            int eidx = graph[v][itr];\n\
    \            auto& edge = edges[eidx];\n\n            if (edge.cap > 0 && dist[v]\
    \ < dist[edge.dst]) {\n                Cap df = dfs(edge.dst, g, std::min(f, edge.cap));\n\
    \n                if (df > 0) {\n                    edge.cap -= df;\n       \
    \             auto& redge = edges[eidx ^ 1];\n                    redge.cap +=\
    \ df;\n                    return df;\n                }\n            }\n    \
    \    }\n        return 0;\n    }\n\n    Cap exec(int s, int g) {\n        const\
    \ Cap INF = std::numeric_limits<Cap>::max();\n\n        Cap ret = 0;\n       \
    \ while (true) {\n            bfs(s);\n            if (dist[g] < 0) return ret;\n\
    \n            std::fill(iter.begin(), iter.end(), 0);\n            while (true)\
    \ {\n                Cap flow = dfs(s, g, INF);\n                if (flow == 0)\
    \ break;\n                ret += flow;\n            }\n        }\n    }\n};\n\
    #line 4 \"Graph/bipartite_matching.hpp\"\n\nstruct BipartiteMatching {\n    MaxFlow<int,\
    \ true> mf;\n    int n, m, s, g;\n\n    explicit BipartiteMatching(int n, int\
    \ m)\n        : mf(n + m + 2), n(n), m(m), s(n + m), g(n + m + 1) {\n        for\
    \ (int u = 0; u < n; ++u) {\n            mf.span(s, enc(u, false), 1);\n     \
    \   }\n        for (int v = 0; v < m; ++v) {\n            mf.span(enc(v, true),\
    \ g, 1);\n        }\n    }\n\n    int enc(int v, bool side) const {\n        return\
    \ v + (side ? n : 0);\n    }\n\n    void span(int u, int v) {\n        mf.span(enc(u,\
    \ false), enc(v, true), 1);\n    }\n\n    int exec() { return mf.exec(s, g); }\n\
    \n    std::vector<std::pair<int, int>> matching() {\n        mf.exec(s, g);\n\n\
    \        std::vector<std::pair<int, int>> ret;\n        for (auto e : mf.edges)\
    \ {\n            if (e.src < e.dst &&\n                e.src < n && e.dst < n\
    \ + m &&\n                e.cap == 0) {\n                ret.emplace_back(e.src,\
    \ e.dst - n);\n            }\n        }\n        return ret;\n    }\n};\n#line\
    \ 4 \"Verify/bipartite_matching.test.cpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n    int n,\
    \ m, k;\n    std::cin >> n >> m >> k;\n\n    BipartiteMatching bm(n, m);\n   \
    \ while (k--) {\n        int u, v;\n        std::cin >> u >> v;\n        bm.span(u,\
    \ v);\n    }\n\n    auto match = bm.matching();\n\n    std::cout << match.size()\
    \ << \"\\n\";\n    for (auto p : match) {\n        std::cout << p.first << ' '\
    \ << p.second << \"\\n\";\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"../Graph/bipartite_matching.hpp\"\n\n#include <iostream>\n\nint main()\
    \ {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n    int n,\
    \ m, k;\n    std::cin >> n >> m >> k;\n\n    BipartiteMatching bm(n, m);\n   \
    \ while (k--) {\n        int u, v;\n        std::cin >> u >> v;\n        bm.span(u,\
    \ v);\n    }\n\n    auto match = bm.matching();\n\n    std::cout << match.size()\
    \ << \"\\n\";\n    for (auto p : match) {\n        std::cout << p.first << ' '\
    \ << p.second << \"\\n\";\n    }\n    return 0;\n}\n"
  dependsOn:
  - Graph/bipartite_matching.hpp
  - Graph/dinic.hpp
  isVerificationFile: true
  path: Verify/bipartite_matching.test.cpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/bipartite_matching.test.cpp
layout: document
redirect_from:
- /verify/Verify/bipartite_matching.test.cpp
- /verify/Verify/bipartite_matching.test.cpp.html
title: Verify/bipartite_matching.test.cpp
---
