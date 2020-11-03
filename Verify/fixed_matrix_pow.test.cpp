#define PROBLEM "https://yukicoder.me/problems/no/1073"

#include "../Number/modint.hpp"
#include "../Number/fixed_matrix.hpp"

#include <iostream>

constexpr int MOD = 1000000007;
using mint = ModInt<MOD>;
using lint = long long;

int main() {
    Matrix<mint, 6> m;
    for (int i = 0; i < 6; ++i) m[0][i] = mint(6).inv();
    for (int i = 1; i < 6; ++i) m[i][i - 1] = 1;

    lint n;
    std::cin >> n;
    std::cout << (m.pow(n))[0][0] << "\n";

    return 0;
}
