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


# :heavy_check_mark: Convolution/number_theoretical_transform.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#fa0f0ae43fdca46d1d68255409ec0b89">Convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/Convolution/number_theoretical_transform.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-29 16:26:48+09:00




## Depends on

* :heavy_check_mark: <a href="../Number/modint.cpp.html">Number/modint.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/Verify/number_theoretical_transform.test.cpp.html">Verify/number_theoretical_transform.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#ifndef __guard__
#define __guard__
#include "../Number/modint.cpp"
#undef __guard__
#endif

#include <vector>

template <int MOD, int Root>
struct NumberTheoreticalTransform {
    using mint = ModInt<MOD>;
    using mints = std::vector<mint>;

    std::vector<mint> zetas;

    explicit NumberTheoreticalTransform() {
        int exp = MOD - 1;
        while (true) {
            mint zeta = mint(Root).pow(exp);
            zetas.push_back(zeta);
            if (exp % 2 != 0) break;
            exp /= 2;
        }
    }

    void bitrev(mints& f) const {
        int n = f.size();

        for (int i = 0; i < n; ++i) {
            int ti = i, ni = 0;
            for (int k = 0; (1 << k) < n; ++k) {
                int b = (ti & 1);
                ti >>= 1;
                ni <<= 1;
                ni += b;
            }

            if (i < ni) {
                std::swap(f[i], f[ni]);
            }
        }
    }

    void udft(mints& f, bool isinv) const {
        if (f.size() <= 1) return;

        int l = 1;
        int k = 1 << l;
        int n = f.size();

        while (k <= n) {
            mint zeta = zetas[l];
            if (isinv) zeta = zeta.inv();

            for (int r = 0; r < n / k; ++r) {
                mint zetapow = 1;

                for (int j = 0; j < k / 2; ++j) {
                    int b = r * k + j;
                    mint t = zetapow * f[b + k / 2];

                    f[b + k / 2] = f[b] - t;
                    f[b] = f[b] + t;

                    zetapow *= zeta;
                }
            }

            ++l;
            k <<= 1;
        }
    }

    void dft(mints& f, bool isinv) const {
        bitrev(f);
        udft(f, isinv);
    }

    mints ntt(mints f, mints g) const {
        int fdeg = f.size(),
            gdeg = g.size();

        int k = 0;
        while ((1 << k) < fdeg + gdeg) {
            ++k;
        }

        int n = (1 << k);
        f.resize(n, mint(0));
        g.resize(n, mint(0));

        dft(f, false);
        dft(g, false);

        mints h(n);
        for (int i = 0; i < n; ++i) {
            h[i] = f[i] * g[i];
        }

        dft(h, true);
        while (h.size() > fdeg + gdeg - 1) {
            h.pop_back();
        }
        for (auto& x : h) x /= n;
        return h;
    }
};

// constexpr int MOD = 998244353;
// using NTT = NumberTheoreticalTransform<MOD, 3>;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 340, in write_contents
    bundler.update(self.file_class.file_path)
  File "/opt/hostedtoolcache/Python/3.8.0/x64/lib/python3.8/site-packages/onlinejudge_verify/bundle.py", line 123, in update
    raise BundleError(path, i + 1, "found codes out of include guard")
onlinejudge_verify.bundle.BundleError: Convolution/number_theoretical_transform.cpp: line 6: found codes out of include guard

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

