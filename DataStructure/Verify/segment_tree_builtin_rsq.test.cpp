#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"

#include <iostream>
#include "../segment_tree_builtin.cpp"

int main() {
    int n;
    std::cin >> n;
    SegmentTree<int> seg(n);

    int q;
    std::cin >> q;
    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int i, x;
            std::cin >> i >> x;
            --i;
            seg.update(i, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.query(l - 1, r) << std::endl;
        }
    }
    return 0;
}
