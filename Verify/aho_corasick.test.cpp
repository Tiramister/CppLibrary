#define PROBLEM "https://yukicoder.me/problems/no/1269"

#include "../Number/modint.hpp"
#include "../String/aho_corasick.hpp"

#include <iostream>
#include <numeric>
#include <string>

using lint = long long;
using mint = ModInt<1000000007>;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    lint l, r;
    std::cin >> n >> l >> r;

    PatternsMatching<10, char> pm('0');
    {
        lint a = 1, b = 1;
        while (a <= r) {
            if (l <= a && a <= r)
                pm.add(std::to_string(a), 0);
            lint s = a + b;
            b = a;
            a = s;
        }
    }

    pm.build();
    int m = pm.nodes.size();

    std::vector<mint> dp(m, 0);
    dp[0] = 1;
    auto ndp = dp;

    while (n--) {
        std::fill(ndp.begin(), ndp.end(), 0);

        for (int i = 0; i < m; ++i) {
            for (int d = 0; d < 10; ++d) {
                int j = pm.next(i, d);
                if (!pm[j].ids.empty()) continue;
                ndp[j] += dp[i];
            }
        }

        std::swap(dp, ndp);
    }

    std::cout << std::accumulate(dp.begin(), dp.end(), mint(0)) - 1 << "\n";
}
