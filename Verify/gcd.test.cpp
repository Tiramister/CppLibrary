#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B"

#include "../Number/gcd.hpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int x, y;
    std::cin >> x >> y;
    std::cout << gcd(x, y) << "\n";

    return 0;
}
