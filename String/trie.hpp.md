---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"String/trie.hpp\"\n\n#include <vector>\n#include <array>\n\
    #include <functional>\n\ntemplate <int K, class T>\nstruct Trie {\n    struct\
    \ Node {\n        int c;\n        std::array<int, K> nxt;\n        explicit Node(int\
    \ c) : c(c) { nxt.fill(-1); }\n    };\n\n    std::vector<Node> nodes;\n    std::function<int(T)>\
    \ enc;\n\n    explicit Trie(T base) {\n        nodes.emplace_back(-1);\n     \
    \   enc = [=](T c) { return c - base; };\n    }\n\n    explicit Trie(const std::function<int(T)>&\
    \ enc)\n        : enc(enc) { nodes.emplace_back(-1); }\n\n    template <class\
    \ Container>\n    void add(const Container& s) {\n        int pos = 0;\n     \
    \   for (T c : s) {\n            int ci = enc(c);\n\n            int npos = nodes[pos].nxt[ci];\n\
    \            if (npos == -1) {\n                npos = nodes.size();\n       \
    \         nodes[pos].nxt[ci] = npos;\n                nodes.emplace_back(ci);\n\
    \            }\n            pos = npos;\n        }\n    }\n\n    template <class\
    \ Container>\n    int find(const Container& s) const {\n        int pos = 0;\n\
    \        for (char c : s) {\n            int ci = enc(c);\n            pos = nodes[pos].nxt[ci];\n\
    \            if (pos == -1) return -1;\n        }\n        return pos;\n    }\n\
    \n    Node& operator[](int pos) { return nodes[pos]; }\n    Node operator[](int\
    \ pos) const { return nodes[pos]; }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <array>\n#include <functional>\n\
    \ntemplate <int K, class T>\nstruct Trie {\n    struct Node {\n        int c;\n\
    \        std::array<int, K> nxt;\n        explicit Node(int c) : c(c) { nxt.fill(-1);\
    \ }\n    };\n\n    std::vector<Node> nodes;\n    std::function<int(T)> enc;\n\n\
    \    explicit Trie(T base) {\n        nodes.emplace_back(-1);\n        enc = [=](T\
    \ c) { return c - base; };\n    }\n\n    explicit Trie(const std::function<int(T)>&\
    \ enc)\n        : enc(enc) { nodes.emplace_back(-1); }\n\n    template <class\
    \ Container>\n    void add(const Container& s) {\n        int pos = 0;\n     \
    \   for (T c : s) {\n            int ci = enc(c);\n\n            int npos = nodes[pos].nxt[ci];\n\
    \            if (npos == -1) {\n                npos = nodes.size();\n       \
    \         nodes[pos].nxt[ci] = npos;\n                nodes.emplace_back(ci);\n\
    \            }\n            pos = npos;\n        }\n    }\n\n    template <class\
    \ Container>\n    int find(const Container& s) const {\n        int pos = 0;\n\
    \        for (char c : s) {\n            int ci = enc(c);\n            pos = nodes[pos].nxt[ci];\n\
    \            if (pos == -1) return -1;\n        }\n        return pos;\n    }\n\
    \n    Node& operator[](int pos) { return nodes[pos]; }\n    Node operator[](int\
    \ pos) const { return nodes[pos]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: String/trie.hpp
  requiredBy: []
  timestamp: '2020-08-28 19:10:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/trie.hpp
layout: document
redirect_from:
- /library/String/trie.hpp
- /library/String/trie.hpp.html
title: String/trie.hpp
---
