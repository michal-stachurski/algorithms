
#include "exp.cc"
constexpr uint64_t MOD = 1e9 + 7;

constexpr uint64_t mod_inv(uint64_t x) {
    return pow(x, MOD - 2); // Little Fermat Theorem, MOD must be prime
}


uint64_t inverse[];
void compute_inv(int m) { // computing modular invers of m from [1, m-1]
    inverse[1] = 1;       // m also must be prime
    for (int i = 2; i < m; i++) {
        inverse[i] = m - ((m/i) * inverse[m%i]) % m;
    }
}

#include "extended_euclidean.cc"