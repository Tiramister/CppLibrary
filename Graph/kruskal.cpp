#ifndef __guard__
#define __guard__
#include "graph.cpp"
#include "../DataStructure/union_find.cpp"
#undef __guard__
#endif

template <class Cost>
Cost kruskal(int vnum, std::vector<Edge<Cost>>& edges) {
    std::sort(edges.begin(), edges.end(),
              [](const auto& lhs, const auto& rhs) { return lhs.cost < rhs.cost; });

    UnionFind uf(vnum);
    Cost sum = 0;
    for (const auto& e : edges) {
        if (uf.same(e.src, e.dst)) continue;
        sum += e.cost;
        uf.unite(e.src, e.dst);
    }
    return sum;
}
