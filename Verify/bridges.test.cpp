#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_3_B"

#include "../Graph/lowlink.cpp"

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

    std::vector<std::pair<int, int>> ans;

    for (auto& e : ll.bridges) {
        if (e.src > e.dst) std::swap(e.src, e.dst);
        ans.emplace_back(e.src, e.dst);
    }
    std::sort(ans.begin(), ans.end());

    for (const auto& p : ans) {
        std::cout << p.first << ' ' << p.second << "\n";
    }

    return 0;
}
