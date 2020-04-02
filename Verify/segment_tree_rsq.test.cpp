#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../DataStructure/segment_tree.cpp"

#include <iostream>

using lint = long long;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;
    SegmentTree<lint> seg(xs, 0, [](auto a, auto b) { return a + b; });

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int i;
            lint x;
            std::cin >> i >> x;
            seg.update(i, seg.get(i) + x);

        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.query(l, r) << "\n";
        }
    }

    return 0;
}
