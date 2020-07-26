#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_A"

#include "../Graph/centroid_decomposition.hpp"

#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

int main() {
    std::cin.tie();
    std::ios::sync_with_stdio(false);

    int n;
    std::cin >> n;

    Graph<int> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph.span(false, u, v, w);
    }

    Centroid<int> cent(graph);

    int ans = 0;
    std::queue<int> cents;
    cents.push(0);

    std::vector<int> dist(n);
    while (!cents.empty()) {
        int r = cents.front();
        cents.pop();
        r = cent.find(r);
        cent.deleted[r] = true;

        std::vector<int> fars({0, 0});
        for (auto e : graph[r]) {
            if (cent.deleted[e.dst]) continue;
            cents.push(e.dst);

            // BFS
            std::queue<std::pair<int, int>> que;
            que.emplace(e.dst, -1);
            dist[e.dst] = e.cost;

            int far = 0;
            while (!que.empty()) {
                int v, p;
                std::tie(v, p) = que.front();
                que.pop();
                far = std::max(far, dist[v]);

                for (auto f : graph[v]) {
                    if (f.dst == p || cent.deleted[f.dst]) continue;
                    dist[f.dst] = dist[v] + f.cost;
                    que.emplace(f.dst, v);
                }
            }
            fars.push_back(far);
        }

        std::sort(fars.rbegin(), fars.rend());
        if (fars.size() >= 2) ans = std::max(ans, fars[0] + fars[1]);
    }

    std::cout << ans << "\n";
    return 0;
}
