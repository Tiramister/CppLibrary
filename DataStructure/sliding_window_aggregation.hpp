#pragma once

#include <stack>

template <class M>
struct SlidingWindowAggregation {
    using T = typename M::T;

    std::stack<std::pair<T, T>> front, back;

    explicit SlidingWindowAggregation() = default;

    void push(const T& x) {
        T acc = M::op(back.empty() ? M::id : back.top().second, x);
        back.emplace(x, acc);
    }

    void pop() {
        if (front.empty()) {
            T acc = M::id;
            while (!back.empty()) {
                acc = M::op(back.top().first, acc);
                front.emplace(back.top().first, acc);
                back.pop();
            }
        }
        front.pop();
    }

    T fold() {
        return M::op((front.empty() ? M::id : front.top().second),
                     (back.empty() ? M::id : back.top().second));
    }
};
