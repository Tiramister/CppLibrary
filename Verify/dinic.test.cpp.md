---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/dinic.hpp
    title: Graph/dinic.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A
  bundledCode: "#line 1 \"Verify/dinic.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A\"\
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
    #line 4 \"Verify/dinic.test.cpp\"\n\n#include <iostream>\n\nint main() {\n   \
    \ std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n    int n, m;\n  \
    \  std::cin >> n >> m;\n\n    MaxFlow<int, true> mf(n);\n    while (m--) {\n \
    \       int u, v, c;\n        std::cin >> u >> v >> c;\n        mf.span(u, v,\
    \ c);\n    }\n\n    std::cout << mf.exec(0, n - 1) << \"\\n\";\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_A\"\
    \n\n#include \"../Graph/dinic.hpp\"\n\n#include <iostream>\n\nint main() {\n \
    \   std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n    int n, m;\n\
    \    std::cin >> n >> m;\n\n    MaxFlow<int, true> mf(n);\n    while (m--) {\n\
    \        int u, v, c;\n        std::cin >> u >> v >> c;\n        mf.span(u, v,\
    \ c);\n    }\n\n    std::cout << mf.exec(0, n - 1) << \"\\n\";\n    return 0;\n\
    }\n"
  dependsOn:
  - Graph/dinic.hpp
  isVerificationFile: true
  path: Verify/dinic.test.cpp
  requiredBy: []
  timestamp: '2020-07-26 22:31:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/dinic.test.cpp
layout: document
redirect_from:
- /verify/Verify/dinic.test.cpp
- /verify/Verify/dinic.test.cpp.html
title: Verify/dinic.test.cpp
---
