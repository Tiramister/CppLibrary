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


# :warning: DataStructure/treap.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5e248f107086635fddcead5bf28943fc">DataStructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/DataStructure/treap.cpp">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include "../Tools/random.cpp"

#include <memory>

template <class Key>
struct Treap {
    Random random;

    using Prior = uint64_t;

    struct Node {
        Key key;
        Prior prior;
        std::unique_ptr<Node> lch, rch;

        explicit Node(Key key = 0, Prior prior = 0)
            : key(key), prior(prior), lch(nullptr), rch(nullptr) {}
    };
    using Tree = std::unique_ptr<Node>;

    Tree root;

    explicit Treap() : root(nullptr) {}

    void split(Tree& t, Key key, Tree& lt, Tree& rt) {
        if (!t) {
            lt = nullptr;
            rt = nullptr;
        } else if (key < t->key) {
            split(t->lch, key, lt, t->lch);
            rt = std::move(t);
        } else {
            split(t->rch, key, t->rch, rt);
            lt = std::move(t);
        }
    }

    void merge(Tree& lt, Tree& rt, Tree& t) {
        if (!lt || !rt) {
            t = std::move(lt ? lt : rt);
        } else if (lt->prior < rt->prior) {
            merge(lt->rch, rt, lt->rch);
            t = std::move(lt);
        } else {
            merge(lt, rt->lch, rt->lch);
            t = std::move(rt);
        }
    }

    void insert(Key key) {
        Tree lt, rt;
        split(root, key, lt, rt);
        root = std::make_unique(Node(key, random.next()));
        merge(lt, root, root);
        merge(root, rt, root);
    }

    void erase(Key key) {
        Tree lt, rt;
        split(root, key - 1, lt, rt);
        split(rt, key, root, rt);
        merge(lt, rt, root);
    }

    bool find(Key key) {
        Tree lt, rt;
        split(root, key - 1, lt, rt);
        split(rt, key, root, rt);
        bool result = !root;
        merge(lt, root, root);
        merge(root, rt, root);
        return result;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 307, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 187, in _resolve
    raise BundleErrorAt(path, -1, "no such header")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../Tools/random.cpp: line -1: no such header

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

