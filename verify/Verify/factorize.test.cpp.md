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


# :heavy_check_mark: Verify/factorize.test.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5a750f86ef41f22f852c43351e3ff383">Verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/Verify/factorize.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 22:31:04+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A">https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../library/Number/prime.hpp.html">Number/prime.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A"

#include "../Number/prime.hpp"

#include <iostream>

const Prime P(100000);

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::cout << n << ":";

    auto facts = P.factorize(n);
    for (auto p : facts) {
        while (p.second--) {
            std::cout << " " << p.first;
        }
    }
    std::cout << "\n";

    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "Verify/factorize.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A"

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
    std::vector<T> divisors(T n) const {
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
#line 4 "Verify/factorize.test.cpp"

#include <iostream>

const Prime P(100000);

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::cout << n << ":";

    auto facts = P.factorize(n);
    for (auto p : facts) {
        while (p.second--) {
            std::cout << " " << p.first;
        }
    }
    std::cout << "\n";

    return 0;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

