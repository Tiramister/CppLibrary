#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_1_B"

#include <iostream>
#include "../gcd.cpp"

int main() {
    int x, y;
    std::cin >> x >> y;
    std::cout << gcd(x, y) << std::endl;
}
