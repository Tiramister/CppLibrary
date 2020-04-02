#pragma once

#include <vector>

template <class Container>
std::vector<int> zalgo(const Container& dat) {
    int n = dat.size();

    std::vector<int> ret(n);
    ret[0] = n;

    int i = 1, len = 0;
    while (i < n) {
        while (i + len < n && dat[len] == dat[i + len]) {
            ++len;
        }
        ret[i] = len;

        if (len == 0) {
            ++i;
            continue;
        }

        int nlen = 1;
        while (i + nlen < n && nlen + ret[nlen] < len) {
            ret[i + nlen] = ret[nlen];
            ++nlen;
        }

        i += nlen;
        len -= nlen;
    }

    return ret;
}
