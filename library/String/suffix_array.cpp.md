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


# :heavy_check_mark: String/suffix_array.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#27118326006d3829667a400ad23d5d98">String</a>
* <a href="{{ site.github.repository_url }}/blob/master/String/suffix_array.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-02 22:58:51+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/suffix_array.test.cpp.html">Verify/suffix_array.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <algorithm>
#include <numeric>
#include <vector>

template <class T>
struct SuffixArray {
    std::vector<int> ord, rank;

    template <class It>
    explicit SuffixArray(const It& begin, const It& end) {
        std::vector<T> dat(begin, end);
        int n = dat.size();

        ord.resize(n);
        std::iota(ord.begin(), ord.end(), 0);
        std::sort(ord.begin(), ord.end(),
                  [&](int i, int j) { return dat[i] < dat[j]; });

        rank.resize(n);
        {
            int cnt = 1;
            rank[ord[0]] = 1;
            for (int i = 1; i < n; ++i) {
                if (dat[ord[i - 1]] != dat[ord[i]]) ++cnt;
                rank[ord[i]] = cnt;
            }
        }

        ord.insert(ord.begin(), n);
        rank.push_back(0);

        std::vector<int> bucket(n + 1), nrank(n + 1), idxs(n + 1);

        for (int k = 1; k < n; k <<= 1) {
            std::fill(bucket.begin(), bucket.end(), 0);

            for (int i = 0; i <= n; ++i) {
                idxs[i] = (ord[i] - k + n + 1) % (n + 1);
                ++bucket[rank[idxs[i]]];
            }

            for (int i = 1; i <= n; ++i) {
                bucket[i] += bucket[i - 1];
            }
            for (int i = n; i >= 0; --i) {
                ord[--bucket[rank[idxs[i]]]] = idxs[i];
            }

            int cnt = 0;
            for (int i = 0;; ++i) {
                nrank[ord[i]] = cnt;
                if (i == n) break;

                if (rank[ord[i]] != rank[ord[i + 1]] ||
                    rank[(ord[i] + k) % (n + 1)] !=
                        rank[(ord[i + 1] + k) % (n + 1)]) ++cnt;
            }
            std::swap(rank, nrank);
        }
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "String/suffix_array.cpp"

#include <algorithm>
#include <numeric>
#include <vector>

template <class T>
struct SuffixArray {
    std::vector<int> ord, rank;

    template <class It>
    explicit SuffixArray(const It& begin, const It& end) {
        std::vector<T> dat(begin, end);
        int n = dat.size();

        ord.resize(n);
        std::iota(ord.begin(), ord.end(), 0);
        std::sort(ord.begin(), ord.end(),
                  [&](int i, int j) { return dat[i] < dat[j]; });

        rank.resize(n);
        {
            int cnt = 1;
            rank[ord[0]] = 1;
            for (int i = 1; i < n; ++i) {
                if (dat[ord[i - 1]] != dat[ord[i]]) ++cnt;
                rank[ord[i]] = cnt;
            }
        }

        ord.insert(ord.begin(), n);
        rank.push_back(0);

        std::vector<int> bucket(n + 1), nrank(n + 1), idxs(n + 1);

        for (int k = 1; k < n; k <<= 1) {
            std::fill(bucket.begin(), bucket.end(), 0);

            for (int i = 0; i <= n; ++i) {
                idxs[i] = (ord[i] - k + n + 1) % (n + 1);
                ++bucket[rank[idxs[i]]];
            }

            for (int i = 1; i <= n; ++i) {
                bucket[i] += bucket[i - 1];
            }
            for (int i = n; i >= 0; --i) {
                ord[--bucket[rank[idxs[i]]]] = idxs[i];
            }

            int cnt = 0;
            for (int i = 0;; ++i) {
                nrank[ord[i]] = cnt;
                if (i == n) break;

                if (rank[ord[i]] != rank[ord[i + 1]] ||
                    rank[(ord[i] + k) % (n + 1)] !=
                        rank[(ord[i + 1] + k) % (n + 1)]) ++cnt;
            }
            std::swap(rank, nrank);
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

