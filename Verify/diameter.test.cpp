#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A"

#include "../Graph/graph.hpp"
#include "../Graph/bfs.hpp"
#include "../Graph/diameter.hpp"

#include <iostream>

int main() {
    int n;
    std::cin >> n;

    Graph<int> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, d;
        std::cin >> u >> v >> d;
        graph.span(false, u, v, d);
    }

    std::cout << diameter(graph).first << "\n";

    return 0;
}
