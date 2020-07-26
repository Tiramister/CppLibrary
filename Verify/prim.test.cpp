#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A"

#include "../Graph/prim.hpp"

#include <iostream>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n, m;
    std::cin >> n >> m;

    Graph<int> graph(n);
    while (m--) {
        int u, v, d;
        std::cin >> u >> v >> d;
        graph.span(false, u, v, d);
    }

    std::cout << prim(graph) << "\n";
    return 0;
}
