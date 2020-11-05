---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/graph.hpp
    title: Graph/graph.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/strongly_connected_component.hpp
    title: Graph/strongly_connected_component.hpp
  - icon: ':heavy_check_mark:'
    path: Graph/two_sat.hpp
    title: Graph/two_sat.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"Verify/two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n\n#line 2 \"Graph/two_sat.hpp\"\n\n#line 2 \"Graph/strongly_connected_component.hpp\"\
    \n\n#line 2 \"Graph/graph.hpp\"\n\n#include <vector>\n\ntemplate <class Cost =\
    \ int>\nstruct Edge {\n    int src, dst;\n    Cost cost;\n\n    Edge() = default;\n\
    \    Edge(int src, int dst, Cost cost = 1)\n        : src(src), dst(dst), cost(cost){};\n\
    \n    bool operator<(const Edge<Cost>& e) const { return cost < e.cost; }\n  \
    \  bool operator>(const Edge<Cost>& e) const { return cost > e.cost; }\n};\n\n\
    template <class Cost = int>\nstruct Graph : public std::vector<std::vector<Edge<Cost>>>\
    \ {\n    using std::vector<std::vector<Edge<Cost>>>::vector;\n\n    void span(bool\
    \ direct, int src, int dst, Cost cost = 1) {\n        (*this)[src].emplace_back(src,\
    \ dst, cost);\n        if (!direct) (*this)[dst].emplace_back(dst, src, cost);\n\
    \    }\n};\n#line 4 \"Graph/strongly_connected_component.hpp\"\n\n#line 6 \"Graph/strongly_connected_component.hpp\"\
    \n\ntemplate <class Cost = int>\nstruct StronglyConnectedComponents {\n    Graph<Cost>\
    \ graph, rgraph;\n    std::vector<bool> visited;\n    std::vector<int> stk;\n\n\
    \    // id[v] = \u9802\u70B9v\u306Fgroups[id[v]]\u306B\u5C5E\u3059\u308B\n   \
    \ std::vector<int> id;\n    std::vector<std::vector<int>> groups;\n\n    explicit\
    \ StronglyConnectedComponents(const Graph<Cost>& g)\n        : graph(g), visited(graph.size(),\
    \ false), id(graph.size(), -1) {\n        revinit();\n\n        for (int v = 0;\
    \ v < (int)graph.size(); ++v) dfs(v);\n\n        while (!stk.empty()) {\n    \
    \        int v = stk.back();\n            stk.pop_back();\n            if (id[v]\
    \ < 0) {\n                groups.emplace_back();\n                rdfs(v);\n \
    \           }\n        }\n    }\n\n    void revinit() {\n        rgraph = Graph<Cost>(graph.size());\n\
    \        for (int v = 0; v < (int)graph.size(); ++v) {\n            for (const\
    \ auto& e : graph[v]) {\n                rgraph[e.dst].emplace_back(e.dst, v,\
    \ e.cost);\n            }\n        }\n    }\n\n    void dfs(int v) {\n       \
    \ if (visited[v]) return;\n        visited[v] = true;\n        for (const auto&\
    \ e : graph[v]) dfs(e.dst);\n        stk.push_back(v);\n    }\n\n    void rdfs(int\
    \ v) {\n        if (id[v] >= 0) return;\n        id[v] = groups.size() - 1;\n\
    \        groups.back().push_back(v);\n        for (const auto& e : rgraph[v])\
    \ rdfs(e.dst);\n    }\n};\n#line 4 \"Graph/two_sat.hpp\"\n\nstruct TwoSat {\n\
    \    int vnum;\n    Graph<> graph;\n    std::vector<bool> assign;\n\n    explicit\
    \ TwoSat(int n) : vnum(n), graph(n * 2), assign(n) {}\n\n    int enc(int x, bool\
    \ t) { return x + (t ? vnum : 0); }\n\n    // (v_x = tx) or (v_y = ty)\n    void\
    \ add(int x, bool tx, int y, bool ty) {\n        graph.span(true, enc(x, !tx),\
    \ enc(y, ty));\n        graph.span(true, enc(y, !ty), enc(x, tx));\n    }\n\n\
    \    // assign is also updated\n    bool judge() {\n        StronglyConnectedComponents\
    \ scc(graph);\n\n        for (int x = 0; x < vnum; ++x) {\n            int fid\
    \ = scc.id[enc(x, false)],\n                tid = scc.id[enc(x, true)];\n\n  \
    \          if (fid == tid) {\n                return false;\n            } else\
    \ {\n                assign[x] = (fid < tid);\n            }\n        }\n    \
    \    return true;\n    }\n};\n#line 4 \"Verify/two_sat.test.cpp\"\n\n#include\
    \ <iostream>\n#include <string>\n\nint main() {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\
    \n    std::string tmp;\n    int n, m;\n    std::cin >> tmp >> tmp >> n >> m;\n\
    \n    TwoSat ts(n);\n    while (m--) {\n        int x, y;\n        std::cin >>\
    \ x >> y >> tmp;\n        ts.add(std::abs(x) - 1, x > 0, std::abs(y) - 1, y >\
    \ 0);\n    }\n\n    if (!ts.judge()) {\n        std::cout << \"s UNSATISFIABLE\\\
    n\";\n    } else {\n        std::cout << \"s SATISFIABLE\\n\";\n\n        std::cout\
    \ << \"v \";\n        for (int x = 1; x <= n; ++x) {\n            std::cout <<\
    \ (ts.assign[x - 1] ? x : -x) << \" \";\n        }\n        std::cout << \"0\\\
    n\";\n    }\n\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include \"\
    ../Graph/two_sat.hpp\"\n\n#include <iostream>\n#include <string>\n\nint main()\
    \ {\n    std::cin.tie();\n    std::ios::sync_with_stdio(false);\n\n    std::string\
    \ tmp;\n    int n, m;\n    std::cin >> tmp >> tmp >> n >> m;\n\n    TwoSat ts(n);\n\
    \    while (m--) {\n        int x, y;\n        std::cin >> x >> y >> tmp;\n  \
    \      ts.add(std::abs(x) - 1, x > 0, std::abs(y) - 1, y > 0);\n    }\n\n    if\
    \ (!ts.judge()) {\n        std::cout << \"s UNSATISFIABLE\\n\";\n    } else {\n\
    \        std::cout << \"s SATISFIABLE\\n\";\n\n        std::cout << \"v \";\n\
    \        for (int x = 1; x <= n; ++x) {\n            std::cout << (ts.assign[x\
    \ - 1] ? x : -x) << \" \";\n        }\n        std::cout << \"0\\n\";\n    }\n\
    \n    return 0;\n}\n"
  dependsOn:
  - Graph/two_sat.hpp
  - Graph/strongly_connected_component.hpp
  - Graph/graph.hpp
  isVerificationFile: true
  path: Verify/two_sat.test.cpp
  requiredBy: []
  timestamp: '2020-11-05 12:15:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: Verify/two_sat.test.cpp
layout: document
redirect_from:
- /verify/Verify/two_sat.test.cpp
- /verify/Verify/two_sat.test.cpp.html
title: Verify/two_sat.test.cpp
---
