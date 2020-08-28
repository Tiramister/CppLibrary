#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_14_B"

#include "../String/morris_pratt.hpp"

#include <iostream>
#include <string>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::string s, p;
    std::cin >> s >> p;

    PatternMatching pm(p);
    for (auto i : pm.find(s)) std::cout << i << "\n";

    return 0;
}
