#include <iostream>
#include <map>

template <class K, class T>
std::ostream& operator<<(std::ostream& os, const std::map<K, T>& map) {
    os << "{";
    for (const auto& elem : map) {
        os << "(" << elem.first << "->" << elem.second << "),";
    }
    return os << "}";
}
