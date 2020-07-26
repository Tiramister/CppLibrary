#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "../String/suffix_array.hpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    SuffixArray<char> sa(s.begin(), s.end());
    for (int i = 1; i <= (int)s.length(); ++i) {
        std::cout << sa.ord[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
