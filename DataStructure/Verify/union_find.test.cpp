#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../union_find.cpp"
#include <iostream>

int main() {
    int n, q;
    std::cin >> n >> q;

    UnionFind uf(n);
    while (q--) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            uf.unite(u, v);
        } else {
            std::cout << uf.same(u, v) << std::endl;
        }
    }
    return 0;
}
