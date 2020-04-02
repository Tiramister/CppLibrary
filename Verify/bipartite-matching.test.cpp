#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#define __guard__
#include "../Graph/dinic.cpp"
#include "../Graph/bimatching.cpp"
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

    auto match = bm.matching();
    std::cout << match.size() << std::endl;
    for (auto p : match) {
        std::cout << p.first << ' ' << p.second << std::endl;
    }
    return 0;
}
