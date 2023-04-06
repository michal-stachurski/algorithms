// Extended Euclidean Algorithm

// gcd(a, b) = g = k*a + l*b

#include <cstdio>
#include <algorithm>
using namespace std;

int extended_euclidean(int a, int b) {
    int A = a, B = b;
    printf("gcd(%d,%d) = ", a, b);
    int x = 1, y = 0;
    int z = 0, t = 1;
    while (min(a, b)) {
        if (a > b) {
            swap(a, b);
            swap(x, y);
            swap(z, t);
        }
        z -= b / a;
        b = b % a;
    }
    int g = a;
    printf("%d = %d*%d + %d*%d\n", g, A, x, B, y);
    return g;
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    extended_euclidean(a, b);
}