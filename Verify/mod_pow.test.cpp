#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"

#include "../Number/modint.cpp"

constexpr int MOD = 1e9 + 7;
using mint = ModInt<MOD>;

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int m, n;
    std::cin >> m >> n;
    std::cout << mint(m).pow(n) << "\n";

    return 0;
}
