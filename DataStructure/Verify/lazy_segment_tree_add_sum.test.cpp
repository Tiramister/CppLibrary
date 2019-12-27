#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G"

#include "../lazy_segment_tree.cpp"

#include <iostream>

using lint = long long;

int main() {
    int n, q;
    std::cin >> n >> q;

    LazySegmentTree<lint, lint> seg(
        n, 0, 0,
        [](auto a, auto b) { return a + b; },
        [](auto e, auto f) { return e + f; },
        [](auto a, auto e, int l) { return a + e * l; });

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int l, r;
            lint x;
            std::cin >> l >> r >> x;
            --l, --r;
            seg.update(l, r + 1, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            --l, --r;
            std::cout << seg.query(l, r + 1) << std::endl;
        }
    }
    return 0;
}
