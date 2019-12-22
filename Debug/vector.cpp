#include <iostream>
#include <vector>

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    os << "[";
    for (const auto& elem : vec) {
        os << elem << ",";
    }
    return os << "]";
}
