#pragma once

#include <deque>
#include <functional>

template <class T>
struct SlidingWindow {
    using Cmp = std::function<bool(T, T)>;

    std::deque<std::pair<T, int>> window;
    Cmp cmp;
    int l, r;

    explicit SlidingWindow(Cmp cmp)
        : window(), cmp(cmp), l(0), r(0) {}

    void push(T val) {
        while (!window.empty() && cmp(val, window.back().first)) {
            window.pop_back();
        }
        window.emplace_back(val, r++);
    }

    T get() {
        return window.front().first;
    }

    void pop() {
        if (window.front().second == l++) {
            window.pop_front();
        }
    }
};
