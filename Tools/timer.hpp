#pragma once

#include <chrono>

struct Timer {
    std::chrono::time_point<std::chrono::system_clock> begin;

    void init() {
        begin = std::chrono::system_clock::now();
    }

    int get_ms() {
        auto cur = std::chrono::system_clock::now();
        return std::chrono::
            duration_cast<std::chrono::milliseconds>(cur - begin)
                .count();
    }
};
