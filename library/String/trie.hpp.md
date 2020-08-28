---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: String/trie.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#27118326006d3829667a400ad23d5d98">String</a>
* <a href="{{ site.github.repository_url }}/blob/master/String/trie.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 19:10:31+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <vector>
#include <array>
#include <functional>

template <int K, class T>
struct Trie {
    struct Node {
        int c;
        std::array<int, K> nxt;
        explicit Node(int c) : c(c) { nxt.fill(-1); }
    };

    std::vector<Node> nodes;
    std::function<int(T)> enc;

    explicit Trie(T base) {
        nodes.emplace_back(-1);
        enc = [=](T c) { return c - base; };
    }

    explicit Trie(const std::function<int(T)>& enc)
        : enc(enc) { nodes.emplace_back(-1); }

    template <class Container>
    void add(const Container& s) {
        int pos = 0;
        for (T c : s) {
            int ci = enc(c);

            int npos = nodes[pos].nxt[ci];
            if (npos == -1) {
                npos = nodes.size();
                nodes[pos].nxt[ci] = npos;
                nodes.emplace_back(ci);
            }
            pos = npos;
        }
    }

    template <class Container>
    int find(const Container& s) const {
        int pos = 0;
        for (char c : s) {
            int ci = enc(c);
            pos = nodes[pos].nxt[ci];
            if (pos == -1) return -1;
        }
        return pos;
    }

    Node& operator[](int pos) { return nodes[pos]; }
    Node operator[](int pos) const { return nodes[pos]; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "String/trie.hpp"

#include <vector>
#include <array>
#include <functional>

template <int K, class T>
struct Trie {
    struct Node {
        int c;
        std::array<int, K> nxt;
        explicit Node(int c) : c(c) { nxt.fill(-1); }
    };

    std::vector<Node> nodes;
    std::function<int(T)> enc;

    explicit Trie(T base) {
        nodes.emplace_back(-1);
        enc = [=](T c) { return c - base; };
    }

    explicit Trie(const std::function<int(T)>& enc)
        : enc(enc) { nodes.emplace_back(-1); }

    template <class Container>
    void add(const Container& s) {
        int pos = 0;
        for (T c : s) {
            int ci = enc(c);

            int npos = nodes[pos].nxt[ci];
            if (npos == -1) {
                npos = nodes.size();
                nodes[pos].nxt[ci] = npos;
                nodes.emplace_back(ci);
            }
            pos = npos;
        }
    }

    template <class Container>
    int find(const Container& s) const {
        int pos = 0;
        for (char c : s) {
            int ci = enc(c);
            pos = nodes[pos].nxt[ci];
            if (pos == -1) return -1;
        }
        return pos;
    }

    Node& operator[](int pos) { return nodes[pos]; }
    Node operator[](int pos) const { return nodes[pos]; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

