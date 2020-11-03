#pragma once

#include "strongly_connected_component.hpp"

struct TwoSat {
    int vnum;
    Graph<> graph;
    std::vector<bool> assign;

    explicit TwoSat(int n) : vnum(n), graph(n * 2), assign(n) {}

    int enc(int x, bool t) { return x + (t ? vnum : 0); }

    // (v_x = tx) or (v_y = ty)
    void add(int x, bool tx, int y, bool ty) {
        graph.span(true, enc(x, !tx), enc(y, ty));
        graph.span(true, enc(y, !ty), enc(x, tx));
    }

    // assign is also updated
    bool judge() {
        StronglyConnectedComponents scc(graph);

        for (int x = 0; x < vnum; ++x) {
            int fid = scc.id[enc(x, false)],
                tid = scc.id[enc(x, true)];

            if (fid == tid) {
                return false;
            } else {
                assign[x] = (fid < tid);
            }
        }
        return true;
    }
};
