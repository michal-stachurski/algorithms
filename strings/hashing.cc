// Polynomial rolling hash function
// Used by Rabin-Karp string search algorithm
#include <string>

constexpr long P = 11777, MOD = 2147483399;
long hash[], pow[];

// Initialize rolling hash
void hash_string(const std::string& str) {
    pow[0] = 1;
    for (int i = 1; i <= str.size(); i++) {
        pow[i] = (pow[i-1] * P) % MOD;
        hash[i] = (hash[i-1] * P + str[i-1]) % MOD;
    }
}

constexpr long sub(long a, long b) {
    return (a < b) ? (a + MOD - b) : (a - b);
}

// Get hash of substring
long substr_hash(int l, int r) {
    int len = r - l + 1;
    return sub(hash[r], (hash[l-1] * pow[len]) % MOD);
}
