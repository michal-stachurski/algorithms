#include <cstdint>

constexpr uint64_t MOD = 1e9 + 7;

constexpr uint64_t pow(uint64_t a, uint64_t n) {
    uint64_t r = 1;
    while (n > 0) {
        if (n & 1) {
            r = (r * a) % MOD;
        }
        a = (a * a) % MOD;
        n /= 2;
    }
    return r;
}
