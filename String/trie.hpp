#pragma once

#include <vector>
#include <array>
#include <functional>

template <int K, class T>
struct Trie {
    struct Node {
        int c;
        std::array<int, K> nxt;
        explicit Node(int c) : c(c) { nxt.fill(-1); }
    };

    std::vector<Node> nodes;
    std::function<int(T)> enc;

    explicit Trie(T base) {
        nodes.emplace_back(-1);
        enc = [=](T c) { return c - base; };
    }

    explicit Trie(const std::function<int(T)>& enc)
        : enc(enc) { nodes.emplace_back(-1); }

    template <class Container>
    void add(const Container& s) {
        int pos = 0;
        for (T c : s) {
            int ci = enc(c);

            int npos = nodes[pos].nxt[ci];
            if (npos == -1) {
                npos = nodes.size();
                nodes[pos].nxt[ci] = npos;
                nodes.emplace_back(ci);
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
