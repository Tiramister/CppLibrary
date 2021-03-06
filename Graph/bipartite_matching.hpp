#pragma once

#include "dinic.hpp"

struct BipartiteMatching {
    MaxFlow<int, true> mf;
    int n, m, s, g;

    int enc(int v, bool side) const { return v + (side ? n : 0); }

    explicit BipartiteMatching(int n, int m)
        : mf(n + m + 2), n(n), m(m), s(n + m), g(n + m + 1) {
        for (int u = 0; u < n; ++u) {
            mf.span(s, enc(u, false), 1);
        }
        for (int v = 0; v < m; ++v) {
            mf.span(enc(v, true), g, 1);
        }
    }

    void span(int u, int v) {
        mf.span(enc(u, false), enc(v, true), 1);
    }

    int size() { return mf.flow(s, g); }

    std::vector<std::pair<int, int>> matching() {
        mf.flow(s, g);

        std::vector<std::pair<int, int>> ret;
        for (auto e : mf.edges) {
            if (e.src < e.dst &&
                e.src < n && e.dst < n + m &&
                e.cap == 0) {
                ret.emplace_back(e.src, e.dst - n);
            }
        }
        return ret;
    }
};
