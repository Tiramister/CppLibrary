#ifndef __guard__
#define __guard__
#include "../Graph/graph.cpp"
#undef __guard__
#endif

template <class Cost = int>
struct Centroid {
    Graph<Cost> graph;
    std::vector<bool> deleted;
    std::vector<int> sz;

    explicit Centroid(const Graph<Cost>& graph)
        : graph(graph), deleted(graph.size(), false), sz(graph.size()) {}

    int szdfs(int v, int p = -1) {
        sz[v] = 1;
        for (auto e : graph[v]) {
            if (e.dst == p || deleted[e.dst]) continue;
            sz[v] += szdfs(e.dst, v);
        }
        return sz[v];
    }

    int find(int v) {
        int n = szdfs(v);

        int p = -1;
        while (true) {
            int nxt = -1;
            for (auto e : graph[v]) {
                if (e.dst == p || deleted[e.dst]) continue;
                if (nxt == -1 || sz[e.dst] > sz[nxt]) nxt = e.dst;
            }

            if (nxt == -1 || sz[nxt] <= n / 2) return v;
            p = v;
            v = nxt;
        }
    }
};
