#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#define __guard__
#include "../String/suffix_array.cpp"
#undef __guard__

#include <iostream>

int main() {
    std::string s;
    std::cin >> s;

    SuffixArray<char> sa(s.begin(), s.end());
    for (int i = 1; i <= (int)s.length(); ++i) {
        std::cout << sa.ord[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
