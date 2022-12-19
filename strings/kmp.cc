#include <string>

int n, pi[];

void kmp(const std::string& str) { // string indexed from one!
    pi[0] = -1;
    for (int i = 1; i <= n; i++) {
        int l = pi[i-1];
        while (l != -1 && str[i] != str[l+1]) {
            l = pi[l];
        }
        pi[i-1] = l + 1;
    }
}
