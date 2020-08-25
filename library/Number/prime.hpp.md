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


# :heavy_check_mark: Number/prime.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b2ee912b91d69b435159c7c3f6df7f5f">Number</a>
* <a href="{{ site.github.repository_url }}/blob/master/Number/prime.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-25 16:54:35+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/factorize.test.cpp.html">Verify/factorize.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

#include <vector>

struct Prime {
    int max_n;
    std::vector<int> primes;
    std::vector<bool> isp;

    explicit Prime(int max_n)
        : max_n(max_n), isp(max_n + 1, true) {
        isp[0] = isp[1] = false;
        for (int i = 2; i * i <= max_n; ++i) {
            if (isp[i]) {
                for (int j = i; i * j <= max_n; ++j) {
                    isp[i * j] = false;
                }
            }
        }

        for (int p = 2; p <= max_n; ++p) {
            if (isp[p]) primes.push_back(p);
        }
    }

    template <class T>
    bool isprime(T n) const {
        if (n <= max_n) return isp[n];
        for (T p : primes) {
            if (p * p > n) break;
            if (n % p == 0) return false;
        }
        return true;
    }

    template <class T>
    std::vector<std::pair<T, int>> factorize(T n) const {
        std::vector<std::pair<T, int>> facts;
        for (T p : primes) {
            if (p * p > n) break;
            if (n % p != 0) continue;
            int exp = 0;
            while (n % p == 0) {
                n /= p;
                ++exp;
            }
            facts.emplace_back(p, exp);
        }
        if (n > 1) {
            facts.emplace_back(n, 1);
        }
        return facts;
    }

    template <class T>
    static std::vector<T> divisors(T n) {
        std::vector<T> ret;
        for (T p = 1; p * p <= n; ++p) {
            if (n % p != 0) continue;
            ret.push_back(p);
            if (n / p == p) continue;
            ret.push_back(n / p);
        }
        return ret;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Number/prime.hpp"

#include <vector>

struct Prime {
    int max_n;
    std::vector<int> primes;
    std::vector<bool> isp;

    explicit Prime(int max_n)
        : max_n(max_n), isp(max_n + 1, true) {
        isp[0] = isp[1] = false;
        for (int i = 2; i * i <= max_n; ++i) {
            if (isp[i]) {
                for (int j = i; i * j <= max_n; ++j) {
                    isp[i * j] = false;
                }
            }
        }

        for (int p = 2; p <= max_n; ++p) {
            if (isp[p]) primes.push_back(p);
        }
    }

    template <class T>
    bool isprime(T n) const {
        if (n <= max_n) return isp[n];
        for (T p : primes) {
            if (p * p > n) break;
            if (n % p == 0) return false;
        }
        return true;
    }

    template <class T>
    std::vector<std::pair<T, int>> factorize(T n) const {
        std::vector<std::pair<T, int>> facts;
        for (T p : primes) {
            if (p * p > n) break;
            if (n % p != 0) continue;
            int exp = 0;
            while (n % p == 0) {
                n /= p;
                ++exp;
            }
            facts.emplace_back(p, exp);
        }
        if (n > 1) {
            facts.emplace_back(n, 1);
        }
        return facts;
    }

    template <class T>
    static std::vector<T> divisors(T n) {
        std::vector<T> ret;
        for (T p = 1; p * p <= n; ++p) {
            if (n % p != 0) continue;
            ret.push_back(p);
            if (n / p == p) continue;
            ret.push_back(n / p);
        }
        return ret;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

