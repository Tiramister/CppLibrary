#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../DataStructure/union_find.hpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    UnionFind uf(n);
    while (q--) {
        int t, u, v;
        std::cin >> t >> u >> v;

        if (t == 0) {
            uf.unite(u, v);
        } else {
            std::cout << uf.same(u, v) << "\n";
        }
    }

    return 0;
}
