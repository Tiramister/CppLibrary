#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../Graph/bipartite_matching.cpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m, k;
    std::cin >> n >> m >> k;

    BiMatching bm(n, m);
    while (k--) {
        int u, v;
        std::cin >> u >> v;
        bm.span(u, v);
    }

    auto match = bm.matching();

    std::cout << match.size() << "\n";
    for (auto p : match) {
        std::cout << p.first << ' ' << p.second << "\n";
    }
    return 0;
}
