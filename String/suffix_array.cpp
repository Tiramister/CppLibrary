#include <algorithm>
#include <numeric>
#include <vector>

template <class T>
struct SuffixArray {
    std::vector<int> ord, rank;

    template <class It>
    explicit SuffixArray(const It& begin, const It& end) {
        std::vector<T> dat(begin, end);
        int n = dat.size();

        ord.resize(n);
        std::iota(ord.begin(), ord.end(), 0);
        std::sort(ord.begin(), ord.end(),
                  [&](int i, int j) { return dat[i] < dat[j]; });

        rank.resize(n);
        {
            int cnt = 1;
            rank[ord[0]] = 1;
            for (int i = 1; i < n; ++i) {
                if (dat[ord[i - 1]] != dat[ord[i]]) ++cnt;
                rank[ord[i]] = cnt;
            }
        }

        // sentinel
        ord.insert(ord.begin(), n);
        rank.push_back(0);

        std::vector<int> bucket(n + 1), nrank(n + 1), idxs(n + 1);

        for (int k = 1; k < n; k <<= 1) {
            std::fill(bucket.begin(), bucket.end(), 0);

            // idxs is in acsending order by the last k characters
            for (int i = 0; i <= n; ++i) {
                idxs[i] = (ord[i] - k + n + 1) % (n + 1);
                ++bucket[rank[idxs[i]]];
            }

            for (int i = 1; i <= n; ++i) {
                bucket[i] += bucket[i - 1];
            }
            for (int i = n; i >= 0; --i) {
                ord[--bucket[rank[idxs[i]]]] = idxs[i];
            }

            int cnt = 0;
            for (int i = 0;; ++i) {
                nrank[ord[i]] = cnt;
                if (i == n) break;

                if (rank[ord[i]] != rank[ord[i + 1]] ||
                    rank[(ord[i] + k) % (n + 1)] !=
                        rank[(ord[i + 1] + k) % (n + 1)]) ++cnt;
            }
            std::swap(rank, nrank);
        }
    }
};
