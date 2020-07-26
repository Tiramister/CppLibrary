#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C"

#include "../Number/modint.hpp"
#include "../Number/combination.hpp"

constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

const Combination<mint> C(1000);

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, k;
    std::cin >> n >> k;

    mint ans = 0;
    for (int i = 0; i <= k; ++i) {
        ans += mint(-1).pow(k - i) * C.comb(k, i) * mint(i).pow(n);
    }
    std::cout << ans << "\n";

    return 0;
}
