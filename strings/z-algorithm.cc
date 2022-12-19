// Calculating Z-function (prefix array) for string in O(n)
#include <iostream>
using std::min;

constexpr int N = 1e6;
int z[N];

void pref_func(const std::string& str) {
    int n = (int) str.size();
    int r = 0, l = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        } while (i + z[i] < n && str[i + z[i]] == str[z[i]]) {
            z[i]++;
        } if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}
