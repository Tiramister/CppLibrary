#pragma once

#include <algorithm>

template <typename T>
T extgcd(T a, T b, T& x, T& y) {
    T s = a, t = b,
      xs = 1, ys = 0,
      xt = 0, yt = 1;

    while (t != 0) {
        T div = s / t;

        s -= t * div;
        xs -= xt * div;
        ys -= yt * div;

        std::swap(s, t);
        std::swap(xs, xt);
        std::swap(ys, yt);
    }

    x = xs;
    y = ys;
    return s;
}
