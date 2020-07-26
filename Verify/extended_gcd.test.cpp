#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E"

#include "../Number/extended_gcd.hpp"

#include <iostream>
#include <cassert>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int a, b;
    std::cin >> a >> b;

    int x, y;
    int g = extgcd(a, b, x, y);
    assert(a * x + b * y == g);

    std::cout << x << " " << y << "\n";
    return 0;
}
