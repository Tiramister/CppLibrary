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
    \ Node {\n        std::array<int, K> nxt;\n        explicit Node() { nxt.fill(-1);\
    \ }\n    };\n\n    std::vector<Node> nodes;\n    std::function<int(T)> enc;\n\n\
    \    explicit Trie(T base)\n        : nodes(1), enc([=](T c) { return c - base;\
    \ }) {}\n\n    template <class Container>\n    void add(const Container& s) {\n\
    \        int pos = 0;\n        for (T ci : s) {\n            int c = enc(ci);\n\
    \n            int npos = nodes[pos].nxt[c];\n            if (npos == -1) {\n \
    \               npos = nodes.size();\n                nodes[pos].nxt[c] = npos;\n\
    \                nodes.emplace_back(c);\n            }\n            pos = npos;\n\
    \        }\n    }\n\n    template <class Container>\n    int find(const Container&\
    \ s) const {\n        int pos = 0;\n        for (char c : s) {\n            int\
    \ ci = enc(c);\n            pos = nodes[pos].nxt[ci];\n            if (pos ==\
    \ -1) return -1;\n        }\n        return pos;\n    }\n\n    Node& operator[](int\
    \ pos) { return nodes[pos]; }\n    Node operator[](int pos) const { return nodes[pos];\
    \ }\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <array>\n#include <functional>\n\
    \ntemplate <int K, class T>\nstruct Trie {\n    struct Node {\n        std::array<int,\
    \ K> nxt;\n        explicit Node() { nxt.fill(-1); }\n    };\n\n    std::vector<Node>\
    \ nodes;\n    std::function<int(T)> enc;\n\n    explicit Trie(T base)\n      \
    \  : nodes(1), enc([=](T c) { return c - base; }) {}\n\n    template <class Container>\n\
    \    void add(const Container& s) {\n        int pos = 0;\n        for (T ci :\
    \ s) {\n            int c = enc(ci);\n\n            int npos = nodes[pos].nxt[c];\n\
    \            if (npos == -1) {\n                npos = nodes.size();\n       \
    \         nodes[pos].nxt[c] = npos;\n                nodes.emplace_back(c);\n\
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
  timestamp: '2020-10-29 01:24:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/trie.hpp
layout: document
redirect_from:
- /library/String/trie.hpp
- /library/String/trie.hpp.html
title: String/trie.hpp
---
