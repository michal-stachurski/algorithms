// O(n log n) sorting algorithm, divide & conquer appraoch
#include <algorithm>

int a[], buffer[];

void dq(int l, int r) {
    if (l == r) {
        return;
    }
    int m = (l+r)/2;
    dq(l, m), dq(m+1, r);
    for (int i = l, x = l, y = m+1; i <= r; i++) {
        buffer[i] = ((x <= m && a[x] <= a[y]) || y > r) ? a[x++] : a[y++];
    }
    std::copy(buffer+l, buffer+r+1, a+l);
}
