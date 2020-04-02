#pragma once

#include <algorithm>
#include <vector>

template <class T>
void bool_elimination(std::vector<std::vector<T>>& mat) {
    int n = mat.size(), m = mat.front().size();

    for (int l = 0; l < n; ++l) {
        {
            auto& v = *std::max_element(mat.begin() + l, mat.end());
            std::swap(v, mat[l]);
        }

        const auto& v = mat[l];
        for (int i = l + 1; i < n; ++i) {
            auto u = mat[i];
            for (int j = 0; j < m; ++j) u[j] ^= v[j];
            if (u < mat[i]) std::swap(u, mat[i]);
        }
    }
}
