uint32_t gcd(uint32_t a, uint32_t b) { // recursion
    return (b) ? gcd(b, a % b) : a;
}

uint32_t gcd(uint32_t a, uint32_t b) { // iteration
    while (min(a, b)) {
        if (a > b) {
            swap(a, b);
        }
        b = b % a;
    }
    return a + b;
}

uint32_t gcd(uint32_t a, uint32_t b) { // Stein's algorithm
    if (!a || !b) {
        return a | b;
    }
    uint32_t shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b) {
            swap(a, b);
        }
        b -= a;
    } while (b);
    return a << shift;
}

#include <numeric>

int main() {
    int x = std::gcd(12, 72);
}
