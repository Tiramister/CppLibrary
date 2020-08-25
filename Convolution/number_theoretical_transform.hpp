#pragma once

#include "../Number/modint.hpp"

#include <vector>

template <int MOD, int Root>
struct NumberTheoreticalTransform {
    using mint = ModInt<MOD>;
    using mints = std::vector<mint>;

    // the 2^k-th root of 1
    std::vector<mint> zetas;
    mint unit_i;

    explicit NumberTheoreticalTransform() {
        int exp = MOD - 1;
        while (true) {
            mint zeta = mint(Root).pow(exp);
            zetas.push_back(zeta);
            if (exp & 1) break;
            exp /= 2;
        }
        unit_i = zetas[2];
    }

    // ceil(log_2 n)
    static int clog2(int n) {
        int k = 0;
        while ((1 << k) < n) ++k;
        return k;
    }

    // 4-radix cooley-tukey algorithm without bit reverse
    // the size of f must be a power of 4
    void ntt(mints& f) const {
        int n = f.size();

        for (int m = n >> 1; m >= 1; m >>= 1) {
            auto zeta = zetas[clog2(m) + 1];
            mint zetapow(1);

            for (int p = 0; p < m; ++p) {
                for (int s = 0; s < n; s += (m << 1)) {
                    auto l = f[s + p],
                         r = f[s + p + m];

                    f[s + p] = l + r;
                    f[s + p + m] = (l - r) * zetapow;
                }
                zetapow = zetapow * zeta;
            }
        }
    }

    // the inverse of above function
    void intt(mints& f) const {
        int n = f.size();

        for (int m = 1; m <= (n >> 1); m <<= 1) {
            auto zeta = zetas[clog2(m) + 1].inv();
            mint zetapow(1);

            for (int p = 0; p < m; ++p) {
                for (int s = 0; s < n; s += (m << 1)) {
                    auto l = f[s + p],
                         r = f[s + p + m] * zetapow;

                    f[s + p] = l + r;
                    f[s + p + m] = l - r;
                }
                zetapow = zetapow * zeta;
            }
        }

        auto ninv = mint(n).inv();
        for (auto& x : f) x *= ninv;
    }

    mints convolute(mints f, mints g) const {
        int fsz = f.size(),
            gsz = g.size();

        // simple convolution in small cases
        if (std::min(fsz, gsz) < 8) {
            mints ret(fsz + gsz - 1, 0);
            for (int i = 0; i < fsz; ++i) {
                for (int j = 0; j < gsz; ++j) {
                    ret[i + j] += f[i] * g[j];
                }
            }
            return ret;
        }

        int n = 1 << clog2(fsz + gsz - 1);
        f.resize(n, mint(0));
        g.resize(n, mint(0));

        ntt(f);
        ntt(g);

        for (int i = 0; i < n; ++i) f[i] *= g[i];

        intt(f);

        f.resize(fsz + gsz - 1);
        return f;
    }
};
