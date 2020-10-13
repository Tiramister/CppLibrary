---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/lowlink.hpp
    title: Graph/lowlink.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A
  bundledCode: "#line 1 \"Verify/articulation_points.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A\"\n\n#line\
    \ 2 \"Graph/lowlink.hpp\"\n\n#line 2 \"Graph/graph.hpp\"\n\n#include <vector>\n\
    \ntemplate <class Cost = int>\nstruct Edge {\n    int src, dst;\n    Cost cost;\n\
    \n    Edge() = default;\n    Edge(int src, int dst, Cost cost = 1)\n        :\
    \ src(src), dst(dst), cost(cost){};\n\n    bool operator<(const Edge<Cost>& e)\
    \ const { return cost < e.cost; }\n    bool operator>(const Edge<Cost>& e) const\
    \ { return cost > e.cost; }\n};\n\ntemplate <class Cost = int>\nstruct Graph :\
    \ public std::vector<std::vector<Edge<Cost>>> {\n    Graph(int n = 0) : std::vector<std::vector<Edge<Cost>>>(n)\
    \ {}\n\n    void span(bool direct, int src, int dst, Cost cost = 1) {\n      \
    \  (*this)[src].emplace_back(src, dst, cost);\n        if (!direct) (*this)[dst].emplace_back(dst,\
    \ src, cost);\n    }\n};\n#line 4 \"Graph/lowlink.hpp\"\n\ntemplate <class Cost\
    \ = int>\nstruct Lowlink {\n    Graph<Cost> graph;\n    int time;\n    std::vector<int>\
    \ order, low;\n\n    std::vector<int> artics;\n    std::vector<Edge<Cost>> bridges;\n\
    \n    explicit Lowlink(const Graph<Cost>& graph)\n        : graph(graph), order(graph.size(),\
    \ -1), low(graph.size(), graph.size()) {\n        time = 0;\n        for (int\
    \ v = 0; v < (int)graph.size(); ++v) {\n            if (order[v] < 0) dfs(v, -1);\n\
    \        }\n    }\n\n    void dfs(int v, int r) {\n        order[v] = low[v] =\
    \ time++;\n        int deg = 0;\n        bool is_artic = false;\n\n        for\
    \ (auto e : graph[v]) {\n            if (order[e.dst] < 0) {\n               \
    \ ++deg;\n                dfs(e.dst, e.src);\n                low[e.src] = std::min(low[e.src],\
    \ low[e.dst]);\n\n                if (order[e.src] <= low[e.dst]) is_artic = true;\n\
    \                if (order[e.src] < low[e.dst]) bridges.push_back(e);\n      \
    \      } else if (e.dst != r) {\n                low[e.src] = std::min(low[e.src],\
    \ order[e.dst]);\n            }\n        }\n\n        if (r < 0) is_artic = (deg\
    \ > 1);\n        if (is_artic) artics.push_back(v);\n    }\n};\n#line 4 \"Verify/articulation_points.test.cpp\"\
    \n\n#include <iostream>\n#include <algorithm>\n\nint main() {\n    std::cin.tie();\n\
    \    std::ios::sync_with_stdio(false);\n\n    int n, m;\n    std::cin >> n >>\
    \ m;\n\n    Graph<> graph(n);\n    while (m--) {\n        int u, v;\n        std::cin\
    \ >> u >> v;\n        graph.span(false, u, v);\n    }\n\n    Lowlink<> ll(graph);\n\
    \n    auto& ans = ll.artics;\n    std::sort(ans.begin(), ans.end());\n    for\
    \ (auto v : ans) std::cout << v << \"\\n\";\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A\"\
    \n\n#include \"../Graph/lowlink.hpp\"\n\n#include <iostream>\n#include <algorithm>\n\
    \nint main() {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n\
    \    int n, m;\n    std::cin >> n >> m;\n\n    Graph<> graph(n);\n    while (m--)\
    \ {\n        int u, v;\n        std::cin >> u >> v;\n        graph.span(false,\
    \ u, v);\n    }\n\n    Lowlink<> ll(graph);\n\n    auto& ans = ll.artics;\n  \
    \  std::sort(ans.begin(), ans.end());\n    for (auto v : ans) std::cout << v <<\
    \ \"\\n\";\n\n    return 0;\n}\n"
  dependsOn:
  - Graph/lowlink.hpp
  - Graph/graph.hpp
  isVerificationFile: true
  path: Verify/articulation_points.test.cpp
  requiredBy: []
  timestamp: '2020-10-13 21:34:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/articulation_points.test.cpp
layout: document
redirect_from:
- /verify/Verify/articulation_points.test.cpp
- /verify/Verify/articulation_points.test.cpp.html
title: Verify/articulation_points.test.cpp
---
