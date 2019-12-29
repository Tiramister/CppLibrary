#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D"

#define __guard__
#include "../DataStructure/sliding_window.cpp"
#undef __guard__

#include <iostream>

int main() {
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
