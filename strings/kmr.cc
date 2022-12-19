// Karp-Miller-Rosenberg algorithm (KMR)
// inits on string in O(n log^2 n) time
// answer queries for lexicographic order of substrings in O(1) time

// Same task can be done using rolling hash and binary search
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

class dictionary {
private:
    struct pair {
        int l, r, index;
        pair(int _l, int _r, int i = 0) {
            l = _l, r = _r, index = i;
        }
        bool operator<(const pair& p) const {
            return (l == p.l) ? (r < p.r) : (l < p.l);
        }
        bool operator!=(const pair& p) const {
            return !((l == p.l) && (r == p.r));
        }
    };

    static const int LOG = 18, SIZE = 2e5;
    int h[LOG][SIZE];
    int size, log;

public:
    void init(const std::string& str) {
        size = str.size();
        log = ceil(log2(size));
        for (int i = 0; i < size; i++) {
            h[0][i] = str[i] - 'a';
        }
        for (int i = 1; i < log; i++) {
            int len = 1 << (i-1);
            std::vector<pair> vec;
            for (int j = 0; j <= size - 2*len; j++) {
                pair p = pair(h[i-1][j], h[i-1][j+len], j);
                vec.push_back(p);
            }
            // This can be linear using bucket sort
            std::sort(vec.begin(), vec.end());
            int idx = 0;
            h[i][vec[0].index] = idx;
            for (int j = 1; j < vec.size(); j++) {
                idx += (vec[j-1] != vec[j]);
                h[i][vec[j].index] = idx;
            }
        }
    }
    char comp(int i, int j, int len) { // first index is zero
        int pow = log2(len);
        int base = 1 << pow;
        if ((h[pow][i] == h[pow][j]) && (h[pow][i+len-base] == h[pow][j+len-base])) {
            return '=';
        }
        return pair(h[pow][i], h[pow][i+len-base]) < pair(h[pow][j], h[pow][j+len-base]) ? '<' : '>';
    }
};

dictionary dict;

int main() {
    std::string s;
    std::cin >> s;

    dict.init(s);

    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, l;
        std::cin >> a >> b >> l;
        a--, b--;
        std::cout << dict.comp(a, b, l) << '\n';
    }
}
