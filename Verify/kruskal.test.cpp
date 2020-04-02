#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_2_A"

#include "../Graph/kruskal.cpp"

#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;

    Edges<int> edges(m);
    for (auto& e : edges) {
        std::cin >> e.src >> e.dst >> e.cost;
    }

    std::cout << kruskal(n, edges) << std::endl;
    return 0;
}
