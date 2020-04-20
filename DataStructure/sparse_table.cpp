#pragma once

#include <vector>
#include <functional>

template <class T>
struct SparseTable {
    using Merger = std::function<T(T, T)>;

    int length;
    std::vector<std::vector<T>> table;
    Merger merge;
    std::vector<int> logs;

    SparseTable(const std::vector<T>& dat, const Merger& merge)
        : length(dat.size()), table{dat}, merge(merge), logs(length + 1) {
        int kmax = 0;
        for (int d = 0; d <= length; ++d) {
            if (d >= (1 << (kmax + 1))) ++kmax;
            logs[d] = kmax;
        }

        table.resize(kmax + 1);
        for (int k = 1; k <= kmax; ++k) {
            table[k].resize(length - (1 << k) + 1);
            for (int i = 0; i + (1 << k) <= length; ++i) {
                table[k][i] = merge(table[k - 1][i],
                                    table[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    T fold(int l, int r) {
        l = std::max(l, 0);
        r = std::min(r, length);

        int k = logs[r - l];
        return merge(table[k][l], table[k][r - (1 << k)]);
    }
};
