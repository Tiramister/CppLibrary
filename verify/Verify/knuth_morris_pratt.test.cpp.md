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


# :heavy_check_mark: Verify/knuth_morris_pratt.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/knuth_morris_pratt.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-28 20:17:14+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B">https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B</a>


## Depends on

* :heavy_check_mark: <a href="../../library/String/knuth_morris_pratt.hpp.html">String/knuth_morris_pratt.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B"

#include "../String/knuth_morris_pratt.hpp"

#include <iostream>
#include <string>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::string s, p;
    std::cin >> s >> p;

    PatternMatching pm(p);
    for (auto i : pm.find(s)) std::cout << i << "\n";

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/knuth_morris_pratt.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B"

#line 2 "String/knuth_morris_pratt.hpp"

#include <vector>

template <class Container>
struct PatternMatching {
    Container pat;
    std::vector<int> fail;

    explicit PatternMatching(const Container& pat) : pat(pat) {
        fail.resize(pat.size() + 1, -1);

        int fpos = -1;
        for (int pos = 0; pos < (int)pat.size(); ++pos) {
            if (fpos >= 0 && pat[pos] == pat[fpos]) fail[pos] = fail[fpos];

            while (fpos >= 0 && pat[pos] != pat[fpos]) {
                fpos = fail[fpos];
            }
            fail[pos + 1] = ++fpos;
        }
    }

    std::vector<int> find(const Container& s) {
        std::vector<int> ret;
        int pos = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            while (pos >= 0 && pat[pos] != s[i]) {
                pos = fail[pos];
            }
            if (++pos == (int)pat.size()) {
                ret.push_back(i - (int)pat.size() + 1);
                pos = fail[pos];
            }
        }
        return ret;
    }
};
#line 4 "Verify/knuth_morris_pratt.test.cpp"

#include <iostream>
#include <string>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::string s, p;
    std::cin >> s >> p;

    PatternMatching pm(p);
    for (auto i : pm.find(s)) std::cout << i << "\n";

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

