#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D"

#include "../DataStructure/sliding_window.hpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, l;
    std::cin >> n >> l;

    SlidingWindow<int> sw([](int lhs, int rhs) { return lhs <= rhs; });

    for (int i = 0; i < n; ++i) {
        int a;
        std::cin >> a;
        sw.push(a);

        if (i >= l - 1) {
            std::cout << sw.get() << " \n"[i == n - 1];
            sw.pop();
        }
    }

    return 0;
}
