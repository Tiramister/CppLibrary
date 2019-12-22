#include <iostream>

template <class L, class R>
std::ostream& operator<<(std::ostream& os, const std::pair<L, R>& p) {
    return os << "(" << p.first << "," << p.second << ")";
}
