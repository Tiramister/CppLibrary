#pragma once

#include "strongly_connected_component.hpp"

#include <iostream>

struct TwoSat {
    int vnum;
    Graph<> graph;

    explicit TwoSat(int n) : vnum(n), graph(n * 2) {}

    // t=1 <=> true
    int enc(int x, bool t) {
        return x + (t ? vnum : 0);
    }

    // [tx]x V [ty]y
    void span(int x, bool tx, int y, bool ty) {
        graph[enc(x, !tx)].emplace_back(enc(x, !tx), enc(y, ty));
        graph[enc(y, !ty)].emplace_back(enc(y, !ty), enc(x, tx));
    }

    // if unsatisfiable, return an empty vector
    std::vector<bool> exec() {
        StronglyConnectedComponents scc(graph);

        std::vector<bool> assign(vnum);
        for (int x = 0; x < vnum; ++x) {
            int fid = scc.id[enc(x, false)],
                tid = scc.id[enc(x, true)];

            if (fid == tid) {
                assign.clear();
                break;
            } else {
                assign[x] = (fid < tid);
            }
        }
        return assign;
    }
};
