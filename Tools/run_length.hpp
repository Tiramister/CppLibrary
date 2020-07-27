#pragma once

#include <vector>
#include <string>

template <class It>
std::vector<std::pair<typename It::value_type, int>> runlength(
    It begin, It end) {
    using T = typename It::value_type;

    std::vector<std::pair<T, int>> res;
    while (begin != end) {
        const T& c = *(begin++);
        if (res.empty() || c != res.back().first) {
            res.emplace_back(c, 1);
        } else {
            ++res.back().second;
        }
    }

    return res;
}
