#pragma once

#include "../Tools/heap_alias.hpp"
#include "graph.hpp"

#include <queue>

template <class Cost, class Cap = int>
Cost prim(const Graph<Cost>& graph) {
    std::vector<bool> used(graph.size(), false);
    used[0] = true;

    MinHeap<Edge<Cost>> heap;
    for (const auto& e : graph[0]) {
        heap.push(e);
    }

    Cost sum = 0;
    while (!heap.empty()) {
        auto e = heap.top();
        heap.pop();
        if (used[e.dst]) continue;

        sum += e.cost;
        used[e.dst] = true;
        for (const auto& se : graph[e.dst]) {
            heap.push(se);
        }
    }
    return sum;
}
