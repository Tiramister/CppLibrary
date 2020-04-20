#pragma once

#include "../Tools/random.cpp"

#include <memory>

template <class Key>
struct Treap {
    Random random;

    using Prior = uint64_t;

    struct Node {
        Key key;
        Prior prior;
        std::unique_ptr<Node> lch, rch;

        explicit Node(Key key = 0, Prior prior = 0)
            : key(key), prior(prior), lch(nullptr), rch(nullptr) {}
    };
    using Tree = std::unique_ptr<Node>;

    Tree root;

    explicit Treap() : root(nullptr) {}

    void split(Tree& t, Key key, Tree& lt, Tree& rt) {
        if (!t) {
            lt = nullptr;
            rt = nullptr;
        } else if (key < t->key) {
            split(t->lch, key, lt, t->lch);
            rt = std::move(t);
        } else {
            split(t->rch, key, t->rch, rt);
            lt = std::move(t);
        }
    }

    void merge(Tree& lt, Tree& rt, Tree& t) {
        if (!lt || !rt) {
            t = std::move(lt ? lt : rt);
        } else if (lt->prior < rt->prior) {
            merge(lt->rch, rt, lt->rch);
            t = std::move(lt);
        } else {
            merge(lt, rt->lch, rt->lch);
            t = std::move(rt);
        }
    }

    void insert(Key key) {
        Tree lt, rt;
        split(root, key, lt, rt);
        root = std::make_unique(Node(key, random.next()));
        merge(lt, root, root);
        merge(root, rt, root);
    }

    void erase(Key key) {
        Tree lt, rt;
        split(root, key - 1, lt, rt);
        split(rt, key, root, rt);
        merge(lt, rt, root);
    }

    bool find(Key key) {
        Tree lt, rt;
        split(root, key - 1, lt, rt);
        split(rt, key, root, rt);
        bool result = !root;
        merge(lt, root, root);
        merge(root, rt, root);
        return result;
    }
};
