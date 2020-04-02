#include <chrono>

struct Random {
    using ulint = uint64_t;
    ulint x;

    explicit Random() {
        x = std::chrono::steady_clock::now()
                .time_since_epoch()
                .count();
    }

    ulint next() {
        x ^= (x << 13);
        x ^= (x >> 7);
        x ^= (x << 17);
        return x;
    }
};
