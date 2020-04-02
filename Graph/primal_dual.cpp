#include "../Tools/heap_alias.cpp"

#include <vector>
#include <tuple>
#include <limits>

template <class Cap, class Cost>
struct MinCostFlow {
    struct Edge {
        int src, dst;
        Cap cap;
        Cost cost;
        Edge(int src, int dst, Cap cap, Cost cost)
            : src(src), dst(dst), cap(cap), cost(cost){};
    };

    using Edges = std::vector<Edge>;
    using Graph = std::vector<std::vector<int>>;

    Edges edges;
    Graph graph;
    std::vector<Cost> dist, pot;
    std::vector<int> rev;

    const Cost INF = std::numeric_limits<Cost>::max() / 2;

    explicit MinCostFlow(int n) : graph(n), dist(n), pot(n), rev(n) {}

    void span(int u, int v, Cap cap, Cost cost) {
        graph[u].push_back(edges.size());
        edges.emplace_back(u, v, cap, cost);

        graph[v].push_back(edges.size());
        edges.emplace_back(v, u, 0, -cost);
    }

    void dijkstra(int s) {
        std::fill(dist.begin(), dist.end(), INF);
        dist[s] = 0;
        MinHeap<std::pair<Cost, int>> heap;
        heap.emplace(0, s);

        while (!heap.empty()) {
            int u;
            Cost d;
            std::tie(d, u) = heap.top();
            heap.pop();
            if (d > dist[u]) continue;

            for (auto eidx : graph[u]) {
                const auto& edge = edges[eidx];
                int v = edge.dst;

                if (edge.cap > 0 &&
                    dist[u] < INF &&
                    dist[v] > dist[u] + edge.cost + pot[u] - pot[v]) {
                    dist[v] = dist[u] + edge.cost + pot[u] - pot[v];
                    rev[v] = eidx;
                    heap.emplace(dist[v], v);
                }
            }
        }
    }

    Cost exec(int s, int g, Cap flow) {
        Cost ret = 0;
        std::fill(pot.begin(), pot.end(), 0);

        while (flow > 0) {
            dijkstra(s);
            if (dist[g] == INF) break;

            for (int v = 0; v < (int)graph.size(); ++v) {
                pot[v] = std::min(pot[v] + dist[v], INF);
            }

            Cap f = flow;
            int v = g;
            while (v != s) {
                const auto& edge = edges[rev[v]];
                f = std::min(f, edge.cap);
                v = edge.src;
            }

            flow -= f;
            ret += f * pot[g];

            v = g;
            while (v != s) {
                auto& edge = edges[rev[v]];
                auto& redge = edges[rev[v] ^ 1];
                edge.cap -= f;
                redge.cap += f;
                v = edge.src;
            }
        }
        return (flow > 0 ? -1 : ret);
    }
};
