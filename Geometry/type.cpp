#pragma once

#include <cmath>

using Real = long double;
constexpr Real EPS = 1e-10L;
constexpr Real PI = 3.14159265358979323846L;

template <class T>
T sq(T x) { return x * x; }

int compare(Real a, Real b) {
    if (std::abs(a - b) < EPS) return 0;
    return a - b > 0 ? 1 : -1;
}

Real deg2rad(Real theta) { return theta / 180 * PI; }
Real rad2deg(Real theta) { return theta / PI * 180; }
