#pragma once

#include <vector>

template <class Cost = int>
struct Edge {
    int src, dst;
    Cost cost;

    Edge() = default;
    Edge(int src, int dst, Cost cost = 1)
        : src(src), dst(dst), cost(cost){};

    bool operator<(const Edge<Cost>& e) const { return cost < e.cost; }
    bool operator>(const Edge<Cost>& e) const { return cost > e.cost; }
};

template <class Cost = int>
struct Graph : public std::vector<std::vector<Edge<Cost>>> {
    using std::vector<std::vector<Edge<Cost>>>::vector;

    void span(bool direct, int src, int dst, Cost cost = 1) {
        (*this)[src].emplace_back(src, dst, cost);
        if (!direct) (*this)[dst].emplace_back(dst, src, cost);
    }
};
