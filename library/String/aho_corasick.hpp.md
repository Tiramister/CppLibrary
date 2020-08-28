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


# :warning: String/aho_corasick.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#27118326006d3829667a400ad23d5d98">String</a>
* <a href="{{ site.github.repository_url }}/blob/master/String/aho_corasick.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 19:11:58+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <functional>

template <int K, class T>
struct PatternsMatching {
    struct Node {
        int c;
        std::array<int, K> nxt;
        int fail;
        std::vector<int> ids;

        explicit Node(int c) : c(c), fail(0) { nxt.fill(-1); }
    };

    std::vector<Node> nodes;
    std::function<int(T)> enc;

    explicit PatternsMatching(T base) {
        nodes.emplace_back(-1);
        enc = [=](T c) { return c - base; };
    }

    explicit PatternsMatching(const std::function<int(T)>& enc)
        : enc(enc) { nodes.emplace_back(-1); }

    template <class Container>
    void add(const Container& s, int id) {
        int pos = 0;
        for (T ci : s) {
            int c = enc(ci);

            int npos = nodes[pos].nxt[c];
            if (npos == -1) {
                npos = nodes.size();
                nodes[pos].nxt[c] = npos;
                nodes.emplace_back(c);
            }
            pos = npos;
        }
        nodes[pos].ids.push_back(id);
    }

    void build() {
        std::queue<int> que;
        for (int& pos : nodes[0].nxt) {
            if (pos == -1) {
                pos = 0;
            } else {
                que.push(pos);
            }
        }

        while (!que.empty()) {
            int pos = que.front();
            que.pop();

            for (int c = 0; c < K; ++c) {
                int npos = nodes[pos].nxt[c];
                if (npos == -1) continue;

                int p = nodes[pos].fail;
                while (nodes[p].nxt[c] == -1) p = nodes[p].fail;
                int fpos = next(nodes[pos].fail, c);

                nodes[npos].fail = fpos;
                std::copy(nodes[fpos].ids.begin(), nodes[fpos].ids.end(),
                          std::back_inserter(nodes[npos].ids));

                que.push(npos);
            }
        }
    }

    int next(int pos, int c) const {
        while (nodes[pos].nxt[c] == -1) pos = nodes[pos].fail;
        return nodes[pos].nxt[c];
    }

    // (id, end of matching)
    template <class Container>
    std::vector<std::pair<int, int>> matching(const Container& s) const {
        std::vector<std::pair<int, int>> ret;

        int pos = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            pos = next(pos, enc(s[i]));
            for (auto id : nodes[pos].ids) {
                ret.emplace_back(id, i + 1);
            }
        }

        return ret;
    }

    Node& operator[](int pos) { return nodes[pos]; }
    Node operator[](int pos) const { return nodes[pos]; }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "String/aho_corasick.hpp"
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <functional>

template <int K, class T>
struct PatternsMatching {
    struct Node {
        int c;
        std::array<int, K> nxt;
        int fail;
        std::vector<int> ids;

        explicit Node(int c) : c(c), fail(0) { nxt.fill(-1); }
    };

    std::vector<Node> nodes;
    std::function<int(T)> enc;

    explicit PatternsMatching(T base) {
        nodes.emplace_back(-1);
        enc = [=](T c) { return c - base; };
    }

    explicit PatternsMatching(const std::function<int(T)>& enc)
        : enc(enc) { nodes.emplace_back(-1); }

    template <class Container>
    void add(const Container& s, int id) {
        int pos = 0;
        for (T ci : s) {
            int c = enc(ci);

            int npos = nodes[pos].nxt[c];
            if (npos == -1) {
                npos = nodes.size();
                nodes[pos].nxt[c] = npos;
                nodes.emplace_back(c);
            }
            pos = npos;
        }
        nodes[pos].ids.push_back(id);
    }

    void build() {
        std::queue<int> que;
        for (int& pos : nodes[0].nxt) {
            if (pos == -1) {
                pos = 0;
            } else {
                que.push(pos);
            }
        }

        while (!que.empty()) {
            int pos = que.front();
            que.pop();

            for (int c = 0; c < K; ++c) {
                int npos = nodes[pos].nxt[c];
                if (npos == -1) continue;

                int p = nodes[pos].fail;
                while (nodes[p].nxt[c] == -1) p = nodes[p].fail;
                int fpos = next(nodes[pos].fail, c);

                nodes[npos].fail = fpos;
                std::copy(nodes[fpos].ids.begin(), nodes[fpos].ids.end(),
                          std::back_inserter(nodes[npos].ids));

                que.push(npos);
            }
        }
    }

    int next(int pos, int c) const {
        while (nodes[pos].nxt[c] == -1) pos = nodes[pos].fail;
        return nodes[pos].nxt[c];
    }

    // (id, end of matching)
    template <class Container>
    std::vector<std::pair<int, int>> matching(const Container& s) const {
        std::vector<std::pair<int, int>> ret;

        int pos = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            pos = next(pos, enc(s[i]));
            for (auto id : nodes[pos].ids) {
                ret.emplace_back(id, i + 1);
            }
        }

        return ret;
    }

    Node& operator[](int pos) { return nodes[pos]; }
    Node operator[](int pos) const { return nodes[pos]; }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

