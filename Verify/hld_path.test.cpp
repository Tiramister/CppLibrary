#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../DataStructure/segment_tree.hpp"
#include "../Graph/heavy_light_decomposition.hpp"

#include <iostream>

using lint = long long;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n, q;
    std::cin >> n >> q;

    std::vector<lint> xs(n);
    for (auto& x : xs) std::cin >> x;

    Graph<> graph(n);
    for (int i = n - 1; i--;) {
        int u, v;
        std::cin >> u >> v;
        graph.span(false, u, v);
    }

    HeavyLightDecomposition hld(graph);
    {
        auto pxs = xs;
        for (int i = 0; i < n; ++i) xs[i] = pxs[hld.vs[i]];
    }

    SegmentTree<lint> seg(xs, 0, [](auto a, auto b) { return a + b; });

    while (q--) {
        int t;
        std::cin >> t;

        switch (t) {
            case 0: {
                int v, x;
                std::cin >> v >> x;

                int i = hld.id[v];
                seg.update(i, seg.get(i) + x);
                break;
            }
            case 1: {
                int u, v;
                std::cin >> u >> v;

                lint sum = 0;
                for (auto [l, r] : hld.path(u, v, false)) {
                    sum += seg.fold(l, r);
                }
                std::cout << sum << "\n";
                break;
            }
        }
    }

    return 0;
}
