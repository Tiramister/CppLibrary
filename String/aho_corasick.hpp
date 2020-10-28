#pragma once

#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <functional>

template <int K, class T>
struct PatternsMatching {
    struct Node {
        std::array<int, K> nxt;
        int fail;
        std::vector<int> ids;

        explicit Node() : fail(0) { nxt.fill(-1); }
    };

    std::vector<Node> nodes;
    std::function<int(T)> enc;

    explicit PatternsMatching(T base)
        : nodes(1), enc([=](T c) { return c - base; }) {}

    template <class Container>
    void add(const Container& s, int id) {
        int pos = 0;
        for (T ci : s) {
            int c = enc(ci);

            int npos = nodes[pos].nxt[c];
            if (npos == -1) {
                npos = nodes.size();
                nodes[pos].nxt[c] = npos;
                nodes.emplace_back();
            }
            pos = npos;
        }
        nodes[pos].ids.push_back(id);
    }

    void build() {
        std::queue<int> que;
        for (int& pos : nodes[0].nxt) {
            if (pos == -1) {
                pos = 0;
            } else {
                que.push(pos);
            }
        }

        while (!que.empty()) {
            int pos = que.front();
            que.pop();

            for (int c = 0; c < K; ++c) {
                int npos = nodes[pos].nxt[c];
                if (npos == -1) continue;

                int p = nodes[pos].fail;
                while (nodes[p].nxt[c] == -1) p = nodes[p].fail;
                int fpos = next(nodes[pos].fail, c);

                nodes[npos].fail = fpos;
                std::copy(nodes[fpos].ids.begin(), nodes[fpos].ids.end(),
                          std::back_inserter(nodes[npos].ids));

                que.push(npos);
            }
        }
    }

    int next(int pos, int c) const {
        while (nodes[pos].nxt[c] == -1) pos = nodes[pos].fail;
        return nodes[pos].nxt[c];
    }

    // (id, end of matching)
    template <class Container>
    std::vector<std::pair<int, int>> matching(const Container& s) const {
        std::vector<std::pair<int, int>> ret;

        int pos = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            pos = next(pos, enc(s[i]));
            for (auto id : nodes[pos].ids) {
                ret.emplace_back(id, i + 1);
            }
        }

        return ret;
    }

    Node& operator[](int pos) { return nodes[pos]; }
    Node operator[](int pos) const { return nodes[pos]; }
};
