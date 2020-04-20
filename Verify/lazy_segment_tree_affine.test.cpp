#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../DataStructure/lazy_segment_tree.cpp"
#include "../Number/modint.cpp"

constexpr int MOD = 998244353;
using mint = ModInt<MOD>;

template <class T>
struct Affine {
    T a, b;
    Affine() = default;
    Affine(T a, T b) : a(a), b(b) {}

    T operator()(T x) const { return a * x + b; }
    bool operator==(const Affine<T>& rhs) const {
        return a == rhs.a && b == rhs.b;
    }
};

using affine = Affine<mint>;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    std::vector<mint> xs(n);
    for (auto& x : xs) std::cin >> x;

    LazySegmentTree<mint, affine>
        seg(
            xs, 0, affine(1, 0),
            [](mint a, mint b) { return a + b; },
            [](affine f, affine g) { return affine(f.a * g.a, g.a * f.b + g.b); },
            [](mint a, affine f, int k) { return f.a * a + f.b * k; });

    while (q--) {
        int t;
        std::cin >> t;

        if (t == 0) {
            int l, r, a, b;
            std::cin >> l >> r >> a >> b;
            seg.update(l, r, affine(a, b));

        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.fold(l, r) << "\n";
        }
    }

    return 0;
}
