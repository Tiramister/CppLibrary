#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"

#include "../DataStructure/weighted_union_find.cpp"

#include <iostream>

int main() {
    int n, q;
    std::cin >> n >> q;
    WeightedUnionFind<int> wuf(n);

    while (q--) {
        int t, u, v;
        std::cin >> t >> u >> v;

        if (t == 0) {
            int d;
            std::cin >> d;
            wuf.unite(v, u, d);
        } else {
            if (!wuf.same(u, v)) {
                std::cout << '?' << std::endl;
            } else {
                std::cout << wuf.diff(u, v) << std::endl;
            }
        }
    }
    return 0;
}
