---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"String/aho_corasick.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\n#include <array>\n#include <queue>\n#include <functional>\n\ntemplate\
    \ <int K, class T>\nstruct PatternsMatching {\n    struct Node {\n        int\
    \ c;\n        std::array<int, K> nxt;\n        int fail;\n        std::vector<int>\
    \ ids;\n\n        explicit Node(int c) : c(c), fail(0) { nxt.fill(-1); }\n   \
    \ };\n\n    std::vector<Node> nodes;\n    std::function<int(T)> enc;\n\n    explicit\
    \ PatternsMatching(T base) {\n        nodes.emplace_back(-1);\n        enc = [=](T\
    \ c) { return c - base; };\n    }\n\n    explicit PatternsMatching(const std::function<int(T)>&\
    \ enc)\n        : enc(enc) { nodes.emplace_back(-1); }\n\n    template <class\
    \ Container>\n    void add(const Container& s, int id) {\n        int pos = 0;\n\
    \        for (T ci : s) {\n            int c = enc(ci);\n\n            int npos\
    \ = nodes[pos].nxt[c];\n            if (npos == -1) {\n                npos =\
    \ nodes.size();\n                nodes[pos].nxt[c] = npos;\n                nodes.emplace_back(c);\n\
    \            }\n            pos = npos;\n        }\n        nodes[pos].ids.push_back(id);\n\
    \    }\n\n    void build() {\n        std::queue<int> que;\n        for (int&\
    \ pos : nodes[0].nxt) {\n            if (pos == -1) {\n                pos = 0;\n\
    \            } else {\n                que.push(pos);\n            }\n       \
    \ }\n\n        while (!que.empty()) {\n            int pos = que.front();\n  \
    \          que.pop();\n\n            for (int c = 0; c < K; ++c) {\n         \
    \       int npos = nodes[pos].nxt[c];\n                if (npos == -1) continue;\n\
    \n                int p = nodes[pos].fail;\n                while (nodes[p].nxt[c]\
    \ == -1) p = nodes[p].fail;\n                int fpos = next(nodes[pos].fail,\
    \ c);\n\n                nodes[npos].fail = fpos;\n                std::copy(nodes[fpos].ids.begin(),\
    \ nodes[fpos].ids.end(),\n                          std::back_inserter(nodes[npos].ids));\n\
    \n                que.push(npos);\n            }\n        }\n    }\n\n    int\
    \ next(int pos, int c) const {\n        while (nodes[pos].nxt[c] == -1) pos =\
    \ nodes[pos].fail;\n        return nodes[pos].nxt[c];\n    }\n\n    // (id, end\
    \ of matching)\n    template <class Container>\n    std::vector<std::pair<int,\
    \ int>> matching(const Container& s) const {\n        std::vector<std::pair<int,\
    \ int>> ret;\n\n        int pos = 0;\n        for (int i = 0; i < (int)s.size();\
    \ ++i) {\n            pos = next(pos, enc(s[i]));\n            for (auto id :\
    \ nodes[pos].ids) {\n                ret.emplace_back(id, i + 1);\n          \
    \  }\n        }\n\n        return ret;\n    }\n\n    Node& operator[](int pos)\
    \ { return nodes[pos]; }\n    Node operator[](int pos) const { return nodes[pos];\
    \ }\n};\n"
  code: "#include <algorithm>\n#include <vector>\n#include <array>\n#include <queue>\n\
    #include <functional>\n\ntemplate <int K, class T>\nstruct PatternsMatching {\n\
    \    struct Node {\n        int c;\n        std::array<int, K> nxt;\n        int\
    \ fail;\n        std::vector<int> ids;\n\n        explicit Node(int c) : c(c),\
    \ fail(0) { nxt.fill(-1); }\n    };\n\n    std::vector<Node> nodes;\n    std::function<int(T)>\
    \ enc;\n\n    explicit PatternsMatching(T base) {\n        nodes.emplace_back(-1);\n\
    \        enc = [=](T c) { return c - base; };\n    }\n\n    explicit PatternsMatching(const\
    \ std::function<int(T)>& enc)\n        : enc(enc) { nodes.emplace_back(-1); }\n\
    \n    template <class Container>\n    void add(const Container& s, int id) {\n\
    \        int pos = 0;\n        for (T ci : s) {\n            int c = enc(ci);\n\
    \n            int npos = nodes[pos].nxt[c];\n            if (npos == -1) {\n \
    \               npos = nodes.size();\n                nodes[pos].nxt[c] = npos;\n\
    \                nodes.emplace_back(c);\n            }\n            pos = npos;\n\
    \        }\n        nodes[pos].ids.push_back(id);\n    }\n\n    void build() {\n\
    \        std::queue<int> que;\n        for (int& pos : nodes[0].nxt) {\n     \
    \       if (pos == -1) {\n                pos = 0;\n            } else {\n   \
    \             que.push(pos);\n            }\n        }\n\n        while (!que.empty())\
    \ {\n            int pos = que.front();\n            que.pop();\n\n          \
    \  for (int c = 0; c < K; ++c) {\n                int npos = nodes[pos].nxt[c];\n\
    \                if (npos == -1) continue;\n\n                int p = nodes[pos].fail;\n\
    \                while (nodes[p].nxt[c] == -1) p = nodes[p].fail;\n          \
    \      int fpos = next(nodes[pos].fail, c);\n\n                nodes[npos].fail\
    \ = fpos;\n                std::copy(nodes[fpos].ids.begin(), nodes[fpos].ids.end(),\n\
    \                          std::back_inserter(nodes[npos].ids));\n\n         \
    \       que.push(npos);\n            }\n        }\n    }\n\n    int next(int pos,\
    \ int c) const {\n        while (nodes[pos].nxt[c] == -1) pos = nodes[pos].fail;\n\
    \        return nodes[pos].nxt[c];\n    }\n\n    // (id, end of matching)\n  \
    \  template <class Container>\n    std::vector<std::pair<int, int>> matching(const\
    \ Container& s) const {\n        std::vector<std::pair<int, int>> ret;\n\n   \
    \     int pos = 0;\n        for (int i = 0; i < (int)s.size(); ++i) {\n      \
    \      pos = next(pos, enc(s[i]));\n            for (auto id : nodes[pos].ids)\
    \ {\n                ret.emplace_back(id, i + 1);\n            }\n        }\n\n\
    \        return ret;\n    }\n\n    Node& operator[](int pos) { return nodes[pos];\
    \ }\n    Node operator[](int pos) const { return nodes[pos]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: String/aho_corasick.hpp
  requiredBy: []
  timestamp: '2020-08-28 19:11:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/aho_corasick.hpp
layout: document
redirect_from:
- /library/String/aho_corasick.hpp
- /library/String/aho_corasick.hpp.html
title: String/aho_corasick.hpp
---
