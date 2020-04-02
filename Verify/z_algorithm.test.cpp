#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../String/z_algorithm.cpp"

#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    auto ans = zalgo(s);
    for (auto a : ans) std::cout << a << " ";
    std::cout << "\n";

    return 0;
}
