#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"

#include <iostream>
#include "../segment_tree_lambda.cpp"

int main() {
    int n;
    std::cin >> n;
    SegmentTree<int> seg(n, 0, [](int a, int b) { return a + b; });

    int q;
    std::cin >> q;
    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int i, x;
            std::cin >> i >> x;
            --i;
            seg.update(i, seg.query(i, i + 1) + x);
        } else {
            int l, r;
            std::cin >> l >> r;
            --l, --r;
            std::cout << seg.query(l, r + 1) << std::endl;
        }
    }
    return 0;
}
