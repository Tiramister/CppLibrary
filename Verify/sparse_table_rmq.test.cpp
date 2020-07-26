#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../DataStructure/sparse_table.hpp"

#include <iostream>

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> xs(n);
    for (auto& x : xs) std::cin >> x;

    SparseTable<int> st(xs, [](auto a, auto b) { return std::min(a, b); });

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << st.fold(l, r) << "\n";
    }

    return 0;
}
