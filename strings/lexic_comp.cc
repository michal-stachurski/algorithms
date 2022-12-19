// performing same operations as KMR, but using rolling hash
// and binary search
// init O(n) query O(log n)
#include <string>
#include "hashing.cc"

char comp(int a, int b, int len, const std::string& str) {
    if (substr_hash(a, a+len-1) == substr_hash(b, b+len-1)) {
        return '=';
    }
    int l = 0, r = len-1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (substr_hash(a, a+mid) == substr_hash(b, b+mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    // -1 because of 0-based indexing in std::string
    return (str[a+l-1] < str[b+l-1]) ? ('<') : ('>');
}

#include <iostream>

int main() {
    std::string s;
    std::cin >> s;

    hash_string(s);

    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b, l;
        std::cin >> a >> b >> l;
        std::cout << comp(a, b, l, s) << '\n';
    }
}
