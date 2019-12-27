#include <vector>
#include <functional>

template <class T, class E>
struct LazySegmentTree {
    using DMerger = std::function<T(T, T)>;
    using OMerger = std::function<E(E, E)>;
    using Applier = std::function<T(T, E, int)>;

    int length;

    T d_unit;
    E o_unit;

    std::vector<T> dat;
    std::vector<E> ope;

    DMerger dmerge;
    OMerger omerge;
    Applier app;

    void eval(int nidx, int len) {
        if (ope[nidx] == o_unit) return;

        // propagate
        if (len > 1) {
            ope[nidx * 2 + 1] = omerge(ope[nidx * 2 + 1], ope[nidx]);
            ope[nidx * 2 + 2] = omerge(ope[nidx * 2 + 2], ope[nidx]);
        }

        // update data
        dat[nidx] = app(dat[nidx], ope[nidx], len);
        ope[nidx] = o_unit;
    }

    void update(int ql, int qr, E e, int nidx, int nl, int nr) {
        eval(nidx, nr - nl);

        if (nr <= ql || qr <= nl) return;
        if (ql <= nl && nr <= qr) {
            ope[nidx] = omerge(ope[nidx], e);
            eval(nidx, nr - nl);
            return;
        }

        int nm = (nl + nr) / 2;
        update(ql, qr, e, nidx * 2 + 1, nl, nm);
        update(ql, qr, e, nidx * 2 + 2, nm, nr);

        // update data
        dat[nidx] = dmerge(dat[nidx * 2 + 1], dat[nidx * 2 + 2]);
    }

    void update(int ql, int qr, E e) { return update(ql, qr, e, 0, 0, length); }

    T query(int ql, int qr, int nidx, int nl, int nr) {
        eval(nidx, nr - nl);
        if (nr <= ql || qr <= nl) return d_unit;
        if (ql <= nl && nr <= qr) return dat[nidx];

        int nm = (nl + nr) / 2;
        T vl = query(ql, qr, nidx * 2 + 1, nl, nm);
        T vr = query(ql, qr, nidx * 2 + 2, nm, nr);
        return dmerge(vl, vr);
    }

    T query(int ql, int qr) { return query(ql, qr, 0, 0, length); }

    explicit LazySegmentTree(int n, T d_unit, E o_unit,
                             DMerger dmerge,
                             OMerger omerge,
                             Applier app)
        : length(1),
          d_unit(d_unit),
          o_unit(o_unit),
          dmerge(dmerge),
          omerge(omerge),
          app(app) {
        while (length < n) length <<= 1;
        dat.assign(length * 2 - 1, d_unit);
        ope.assign(length * 2 - 1, o_unit);
    }
};
