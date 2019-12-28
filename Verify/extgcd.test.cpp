#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E"

#define __guard__
#include "../Number/extgcd.cpp"
#undef __guard__

#include <iostream>
#include <cassert>

int main() {
    int a, b;
    std::cin >> a >> b;

    int x, y;
    int g = extgcd(a, b, x, y);
    assert(a * x + b * y == g);

    std::cout << x << " " << y << std::endl;
    return 0;
}
