#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../DataStructure/segment_tree.cpp"
#include "../Number/modint.cpp"

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

template <class T>
struct Affine {
    T a, b;
    Affine() = default;
    Affine(T a, T b) : a(a), b(b) {}

    T operator()(T x) const { return a * x + b; }
};

using affine = Affine<mint>;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    std::vector<affine> xs(n);
    for (auto& x : xs) std::cin >> x.a >> x.b;

    SegmentTree<affine>
        seg(xs, affine(1, 0),
            [](affine f, affine g) { return affine(f.a * g.a, g.a * f.b + g.b); });

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int i, a, b;
            std::cin >> i >> a >> b;
            seg.update(i, affine(a, b));

        } else {
            int l, r, x;
            std::cin >> l >> r >> x;
            auto f = seg.query(l, r);
            std::cout << f(x) << "\n";
        }
    }

    return 0;
}
