#include <vector>
#include <functional>

template <class T>
struct SegmentTree {
    using Merger = std::function<T(T, T)>;

    int length;
    std::vector<T> dat;
    T unit;
    Merger merge;

    explicit SegmentTree(int n, T unit, Merger merge)
        : length(1), unit(unit), merge(merge) {
        while (length < n) length <<= 1;
        dat.assign(length * 2 - 1, unit);
    }

    T query(int ql, int qr, int nidx, int nl, int nr) {
        if (nr <= ql || qr <= nl) return unit;
        if (ql <= nl && nr <= qr) return dat[nidx];

        int nm = (nl + nr) / 2;
        T vl = query(ql, qr, nidx * 2 + 1, nl, nm);
        T vr = query(ql, qr, nidx * 2 + 2, nm, nr);
        return merge(vl, vr);
    }

    T query(int ql, int qr) { return query(ql, qr, 0, 0, length); }

    void update(int nidx, T elem) {
        nidx += length - 1;
        dat[nidx] = elem;

        while (nidx > 0) {
            nidx = (nidx - 1) >> 1;
            T vl = dat[nidx * 2 + 1];
            T vr = dat[nidx * 2 + 2];
            dat[nidx] = merge(vl, vr);
        }
    }
};

// example:
// SegmentTree<int>(n, 0, [](int a, int b) { return a + b; });
