#include <vector>

// update: overwrite
// query : minimun
// unit  : 2^31 - 1
template <class T>
struct SegmentTree {
    int length;
    std::vector<T> dat;
    T unit = (1U << 31) - 1;  // unit

    explicit SegmentTree(int n) : length(1) {
        while (length < n) {
            length <<= 1;
        }
        dat.assign(length * 2 - 1, unit);
    }

    T query(int ql, int qr, int nidx, int nl, int nr) {
        if (nr <= ql || qr <= nl) return unit;
        if (ql <= nl && nr <= qr) return dat[nidx];

        int nm = (nl + nr) / 2;
        T vl = query(ql, qr, nidx * 2 + 1, nl, nm);
        T vr = query(ql, qr, nidx * 2 + 2, nm, nr);
        return std::min(vl, vr);  // query
    }

    T query(int ql, int qr) { return query(ql, qr, 0, 0, length); }

    void update(int nidx, T elem) {
        nidx += length - 1;
        dat[nidx] = elem;  // update

        while (nidx > 0) {
            nidx = (nidx - 1) >> 1;
            T vl = dat[nidx * 2 + 1];
            T vr = dat[nidx * 2 + 2];
            dat[nidx] = std::min(vl, vr);  // query
        }
    }
};
