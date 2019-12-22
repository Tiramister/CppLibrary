#include <iostream>
#include <set>

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& set) {
    os << "{";
    for (const auto& elem : set) {
        os << elem << ",";
    }
    return os << "}";
}
