#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#define __guard__
#include "../String/z_algorithm.cpp"
#undef __guard__

#include <iostream>
#include <string>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    auto ans = zalgo(s);
    for (auto a : ans) std::cout << a << " ";
    std::cout << std::endl;

    return 0;
}
