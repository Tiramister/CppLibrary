#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_A"

#include "../Graph/lowlink.hpp"

#include <iostream>
#include <algorithm>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    Graph<> graph(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        graph.span(false, u, v);
    }

    Lowlink<> ll(graph);

    auto& ans = ll.artics;
    std::sort(ans.begin(), ans.end());
    for (auto v : ans) std::cout << v << "\n";

    return 0;
}
