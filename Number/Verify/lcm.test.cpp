#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_C"

#include <iostream>
#include "../gcd.cpp"

int main() {
    int n;
    std::cin >> n;

    uint ans = 1;
    for (int i = 0; i < n; ++i) {
        uint a;
        std::cin >> a;
        ans *= a / gcd(ans, a);
    }
    std::cout << ans << std::endl;
}
