#pragma once

#include <vector>
#include <array>
#include <functional>

template <int K, class T>
struct Trie {
    struct Node {
        std::array<int, K> nxt;
        explicit Node() { nxt.fill(-1); }
    };

    std::vector<Node> nodes;
    std::function<int(T)> enc;

    explicit Trie(T base)
        : nodes(1), enc([=](T c) { return c - base; }) {}

    template <class Container>
    void add(const Container& s) {
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
    }

    template <class Container>
    int find(const Container& s) const {
        int pos = 0;
        for (char c : s) {
            int ci = enc(c);
            pos = nodes[pos].nxt[ci];
            if (pos == -1) return -1;
        }
        return pos;
    }

    Node& operator[](int pos) { return nodes[pos]; }
    Node operator[](int pos) const { return nodes[pos]; }
};
