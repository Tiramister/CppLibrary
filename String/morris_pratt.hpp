#pragma once

#include <vector>

template <class Container>
struct PatternMatching {
    Container pat;
    std::vector<int> fail;

    explicit PatternMatching(const Container& pat) : pat(pat) {
        fail.resize(pat.size() + 1, -1);

        int fpos = -1;
        for (int pos = 0; pos < (int)pat.size(); ++pos) {
            while (fpos >= 0 && pat[pos] != pat[fpos]) {
                fpos = fail[fpos];
            }
            fail[pos + 1] = ++fpos;
        }
    }

    std::vector<int> find(const Container& s) {
        std::vector<int> ret;
        int pos = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            while (pos >= 0 && pat[pos] != s[i]) {
                pos = fail[pos];
            }
            if (++pos == (int)pat.size()) {
                ret.push_back(i - (int)pat.size() + 1);
                pos = fail[pos];
            }
        }
        return ret;
    }
};
