#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include "../Convolution/number_theoretical_transform.cpp"

#include <iostream>

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;
const NumberTheoreticalTransform<MOD, 3> NTT;

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    std::vector<mint> xs(n), ys(m);
    for (auto& x : xs) std::cin >> x;
    for (auto& y : ys) std::cin >> y;

    auto zs = NTT.ntt(xs, ys);
    for (auto z : zs) std::cout << z << ' ';
    std::cout << "\n";

    return 0;
}
