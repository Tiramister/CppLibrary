#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../String/z_algorithm.hpp"

#include <iostream>
#include <string>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    auto ans = zalgo(s);
    for (auto a : ans) std::cout << a << " ";
    std::cout << "\n";

    return 0;
}
