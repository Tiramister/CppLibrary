#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A"

#define __guard__
#include "../Misc/heap_alias.cpp"
#include "../Graph/graph.cpp"
#include "../Graph/prim.cpp"
#undef __guard__

#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    Graph<int> graph(n);
    while (m--) {
        int u, v, d;
        std::cin >> u >> v >> d;
        graph[u].emplace_back(u, v, d);
        graph[v].emplace_back(v, u, d);
    }

    std::cout << prim(graph) << std::endl;
    return 0;
}
