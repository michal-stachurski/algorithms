#include <fstream>
// #include <cstdint>
using std::ostream;
using std::istream;

const int MOD = 998244353;
struct mint {
    int val;

    mint(int v) : val(v) {}
    mint(int64_t v = 0) { val = v % MOD; if (val < 0) val += MOD;}

    mint& operator+=(mint const& b) {val += b.val; if (val >= MOD) val -= MOD; return *this;}
    mint& operator-=(mint const& b) {val -= b.val; if (val < 0) val += MOD;return *this;}
    mint& operator*=(mint const& b) {val = (int64_t)val * b.val % MOD;return *this;}
    mint& operator/=(mint const& b) {return *this *= inverse(b);}

    friend mint mexp(mint a, int64_t n) {
        mint res = 1; while (n) { if (n&1) res *= a; a *= a; n >>= 1; }
        return res;
    }
    friend mint inverse(mint a) {return mexp(a, MOD-2);}

    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator-(const mint& a) { return 0 - a; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
    friend mint operator/(mint a, const mint& b) { return a /= b; }
    friend bool operator==(const mint& a, const mint& b) {return a.val == b.val;}
    friend bool operator!=(const mint& a, const mint& b) {return a.val != b.val;}
  
    friend ostream& operator<<(ostream& os, const mint& m) {return os << m.val;}
    friend istream& operator>>(istream& is, mint& m) {return is >> m.val;}
};
