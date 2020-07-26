#pragma once

#include <vector>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }
