#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"

#include "../DataStructure/potentialized_union_find.hpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;
    PotentializedUnionFind<int> puf(n);

    while (q--) {
        int t, u, v;
        std::cin >> t >> u >> v;

        if (t == 0) {
            int d;
            std::cin >> d;
            puf.unite(v, u, d);

        } else {
            if (!puf.same(u, v)) {
                std::cout << "?\n";
            } else {
                std::cout << puf.diff(u, v) << "\n";
            }
        }
    }

    return 0;
}
