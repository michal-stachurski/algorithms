#include <iostream>
using std::cin, std::cout;

const int N = 1e6 + 1;
constexpr long P = 11777, MOD = 2147483399;
long hash[N], power[N];

constexpr long sub(long a, long b) {
    return (a < b) ? (a + MOD - b) : (a - b);
}
constexpr long sum(long a, long b) {
    return (a + b >= MOD) ? (a + b - MOD) : (a + b);
}

// Used only for initialize fenwick_t
void init_hash(const char* str, int n) {
    power[0] = 1;
    for (int i = 1; i <= n; i++) {
        power[i] = (power[i-1] * P) % MOD;
        hash[i] = (hash[i-1] * P + str[i]) % MOD;
    }
}
long static_substr(int l, int r) {
    int len = r - l + 1;
    return sub(hash[r], (hash[l-1] * power[len]) % MOD);
}

class fenwick_t {
private:
    long F[N];
    int n;

    constexpr int lsb(int x) const {
        return x & -x;
    }
public:
    void init(const char* str, int size) {
        init_hash(str, n);
        n = size;
        for (int i = 1; i <= n; i++) {
            F[i] = static_substr(i - lsb(i) + 1, i);
        }
    }
    void update(int i, char x, char y) {
        if (x == y) {
            return;
        }
        int index = i;
        while (i <= n) {
            F[i] = sub(F[i], (power[i - index] * long(x)) % MOD);
            F[i] = sum(F[i], (power[i - index] * long(y)) % MOD);
            i += lsb(i);
        }
    }
    long prefix(int i) const {
        long r = 0;
        int len = 0;
        while (i > 0) {
            r = sum(r, F[i] * power[len] % MOD);
            len += lsb(i);
            i -= lsb(i);
        }
        return r;
    }
    long get_hash(int l, int r) const {
        int len = r - l + 1;
        return sub(prefix(r), (prefix(l-1) * power[len]) % MOD);
    }
};


fenwick_t tree;
char str[N];
int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> str[i];
    }
    tree.init(str, n);
}
