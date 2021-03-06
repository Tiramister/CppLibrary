#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A"

#include "../Number/prime.hpp"

#include <iostream>

const Prime P(100000);

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;
    std::cout << n << ":";

    auto facts = P.factorize(n);
    for (auto p : facts) {
        while (p.second--) {
            std::cout << " " << p.first;
        }
    }
    std::cout << "\n";

    return 0;
}
