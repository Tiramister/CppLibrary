#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_E"

#include "../modint.cpp"
#include "../combination.cpp"

constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

const Combination<mint> C(1000);

int main() {
    int n, k;
    std::cin >> n >> k;
    std::cout << C.comb(k, n) << std::endl;
    return 0;
}
