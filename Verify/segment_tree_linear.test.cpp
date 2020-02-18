#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#define __guard__
#include "../DataStructure/segment_tree.cpp"
#include "../Number/modint.cpp"
#undef __guard__

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

template <class T>
struct Linear {
    T a, b;
    explicit Linear(T a, T b) : a(a), b(b) {}
    T operator()(T x) const { return a * x + b; }
};

using linear = Linear<mint>;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    SegmentTree<linear>
        seg(n, linear(1, 0),
            [](linear f, linear g) { return linear(f.a * g.a, g.a * f.b + g.b); });
    for (int i = 0; i < n; ++i) {
        int a, b;
        std::cin >> a >> b;
        seg.update(i, linear(a, b));
    }

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int i, a, b;
            std::cin >> i >> a >> b;
            seg.update(i, linear(a, b));
        } else {
            int l, r, x;
            std::cin >> l >> r >> x;
            auto f = seg.query(l, r);
            std::cout << f(x) << "\n";
        }
    }
    return 0;
}
