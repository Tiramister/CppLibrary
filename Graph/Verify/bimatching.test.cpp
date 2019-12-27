#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_7_A"

#define __guard__
#include "../dinic.cpp"
#include "../bimatching.cpp"
#undef __guard__

#include <iostream>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    BiMatching bm(n, m);
    while (k--) {
        int u, v;
        std::cin >> u >> v;
        bm.span(u, v);
    }

    std::cout << bm.exec() << std::endl;
    return 0;
}
