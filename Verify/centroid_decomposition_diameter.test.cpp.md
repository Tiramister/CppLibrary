---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/centroid_decomposition.hpp
    title: Graph/centroid_decomposition.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A
  bundledCode: "#line 1 \"Verify/centroid_decomposition_diameter.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A\"\
    \n\n#line 2 \"Graph/centroid_decomposition.hpp\"\n\n#line 2 \"Graph/graph.hpp\"\
    \n\n#include <vector>\n\ntemplate <class Cost = int>\nstruct Edge {\n    int src,\
    \ dst;\n    Cost cost;\n\n    Edge() = default;\n    Edge(int src, int dst, Cost\
    \ cost = 1)\n        : src(src), dst(dst), cost(cost){};\n\n    bool operator<(const\
    \ Edge<Cost>& e) const { return cost < e.cost; }\n    bool operator>(const Edge<Cost>&\
    \ e) const { return cost > e.cost; }\n};\n\ntemplate <class Cost = int>\nstruct\
    \ Graph : public std::vector<std::vector<Edge<Cost>>> {\n    Graph(int n = 0)\
    \ : std::vector<std::vector<Edge<Cost>>>(n) {}\n\n    void span(bool direct, int\
    \ src, int dst, Cost cost = 1) {\n        (*this)[src].emplace_back(src, dst,\
    \ cost);\n        if (!direct) (*this)[dst].emplace_back(dst, src, cost);\n  \
    \  }\n};\n#line 4 \"Graph/centroid_decomposition.hpp\"\n\ntemplate <class Cost\
    \ = int>\nstruct Centroid {\n    Graph<Cost> graph;\n    std::vector<bool> deleted;\n\
    \    std::vector<int> sz;\n\n    explicit Centroid(const Graph<Cost>& graph)\n\
    \        : graph(graph), deleted(graph.size(), false), sz(graph.size()) {}\n\n\
    \    int szdfs(int v, int p = -1) {\n        sz[v] = 1;\n        for (auto e :\
    \ graph[v]) {\n            if (e.dst == p || deleted[e.dst]) continue;\n     \
    \       sz[v] += szdfs(e.dst, v);\n        }\n        return sz[v];\n    }\n\n\
    \    int find(int v) {\n        int n = szdfs(v);\n\n        int p = -1;\n   \
    \     while (true) {\n            int nxt = -1;\n            for (auto e : graph[v])\
    \ {\n                if (e.dst == p || deleted[e.dst]) continue;\n           \
    \     if (nxt == -1 || sz[e.dst] > sz[nxt]) nxt = e.dst;\n            }\n\n  \
    \          if (nxt == -1 || sz[nxt] <= n / 2) return v;\n            p = v;\n\
    \            v = nxt;\n        }\n    }\n};\n#line 4 \"Verify/centroid_decomposition_diameter.test.cpp\"\
    \n\n#include <iostream>\n#include <algorithm>\n#include <queue>\n#include <tuple>\n\
    \nint main() {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n\
    \    int n;\n    std::cin >> n;\n\n    Graph<int> graph(n);\n    for (int i =\
    \ 0; i < n - 1; ++i) {\n        int u, v, w;\n        std::cin >> u >> v >> w;\n\
    \        graph.span(false, u, v, w);\n    }\n\n    Centroid<int> cent(graph);\n\
    \n    int ans = 0;\n    std::queue<int> cents;\n    cents.push(0);\n\n    std::vector<int>\
    \ dist(n);\n    while (!cents.empty()) {\n        int r = cents.front();\n   \
    \     cents.pop();\n        r = cent.find(r);\n        cent.deleted[r] = true;\n\
    \n        std::vector<int> fars({0, 0});\n        for (auto e : graph[r]) {\n\
    \            if (cent.deleted[e.dst]) continue;\n            cents.push(e.dst);\n\
    \n            // BFS\n            std::queue<std::pair<int, int>> que;\n     \
    \       que.emplace(e.dst, -1);\n            dist[e.dst] = e.cost;\n\n       \
    \     int far = 0;\n            while (!que.empty()) {\n                int v,\
    \ p;\n                std::tie(v, p) = que.front();\n                que.pop();\n\
    \                far = std::max(far, dist[v]);\n\n                for (auto f\
    \ : graph[v]) {\n                    if (f.dst == p || cent.deleted[f.dst]) continue;\n\
    \                    dist[f.dst] = dist[v] + f.cost;\n                    que.emplace(f.dst,\
    \ v);\n                }\n            }\n            fars.push_back(far);\n  \
    \      }\n\n        std::sort(fars.rbegin(), fars.rend());\n        if (fars.size()\
    \ >= 2) ans = std::max(ans, fars[0] + fars[1]);\n    }\n\n    std::cout << ans\
    \ << \"\\n\";\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A\"\
    \n\n#include \"../Graph/centroid_decomposition.hpp\"\n\n#include <iostream>\n\
    #include <algorithm>\n#include <queue>\n#include <tuple>\n\nint main() {\n   \
    \ std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n    int n;\n    std::cin\
    \ >> n;\n\n    Graph<int> graph(n);\n    for (int i = 0; i < n - 1; ++i) {\n \
    \       int u, v, w;\n        std::cin >> u >> v >> w;\n        graph.span(false,\
    \ u, v, w);\n    }\n\n    Centroid<int> cent(graph);\n\n    int ans = 0;\n   \
    \ std::queue<int> cents;\n    cents.push(0);\n\n    std::vector<int> dist(n);\n\
    \    while (!cents.empty()) {\n        int r = cents.front();\n        cents.pop();\n\
    \        r = cent.find(r);\n        cent.deleted[r] = true;\n\n        std::vector<int>\
    \ fars({0, 0});\n        for (auto e : graph[r]) {\n            if (cent.deleted[e.dst])\
    \ continue;\n            cents.push(e.dst);\n\n            // BFS\n          \
    \  std::queue<std::pair<int, int>> que;\n            que.emplace(e.dst, -1);\n\
    \            dist[e.dst] = e.cost;\n\n            int far = 0;\n            while\
    \ (!que.empty()) {\n                int v, p;\n                std::tie(v, p)\
    \ = que.front();\n                que.pop();\n                far = std::max(far,\
    \ dist[v]);\n\n                for (auto f : graph[v]) {\n                   \
    \ if (f.dst == p || cent.deleted[f.dst]) continue;\n                    dist[f.dst]\
    \ = dist[v] + f.cost;\n                    que.emplace(f.dst, v);\n          \
    \      }\n            }\n            fars.push_back(far);\n        }\n\n     \
    \   std::sort(fars.rbegin(), fars.rend());\n        if (fars.size() >= 2) ans\
    \ = std::max(ans, fars[0] + fars[1]);\n    }\n\n    std::cout << ans << \"\\n\"\
    ;\n    return 0;\n}\n"
  dependsOn:
  - Graph/centroid_decomposition.hpp
  - Graph/graph.hpp
  isVerificationFile: true
  path: Verify/centroid_decomposition_diameter.test.cpp
  requiredBy: []
  timestamp: '2020-10-13 21:34:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/centroid_decomposition_diameter.test.cpp
layout: document
redirect_from:
- /verify/Verify/centroid_decomposition_diameter.test.cpp
- /verify/Verify/centroid_decomposition_diameter.test.cpp.html
title: Verify/centroid_decomposition_diameter.test.cpp
---
