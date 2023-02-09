#include <cstdio>
#include <cmath>
using std::min;

const int N = 1e6 + 1;

class tree {
private:
    int tree[4*N], f[4*N], lazy[4*N];
    int base, size;

    inline int left(int v, int h) {
        return v * (1<<h);
    }
    inline int right(int v, int h) {
        return (v+1) * (1<<h) - 1;
    }

    void pushdown(int v, int h) {
        if (h) {
            tree[2*v] += lazy[v];
            tree[2*v+1] += lazy[v];

            lazy[2*v] += lazy[v];
            lazy[2*v+1] += lazy[v];

            lazy[v] = 0;
        }
    }
    void update(int v) {
        tree[v] = min(tree[2*v], tree[2*v+1]);
        if (tree[2*v] == tree[2*v+1]) {
            f[v] = f[2*v] + f[2*v+1];
        } else if (tree[2*v] < tree[2*v+1]) {
            f[v] = f[2*v];
        } else {
            f[v] = f[2*v+1];
        }
    }
    void build(int n, int v = 1) {
        if (v >= size) {
            f[v] = (v - size < n);
            return;
        }
        build(n, 2*v);
        build(n, 2*v+1);
        f[v] = f[2*v] + f[2*v+1];
    }
    void delta(int x, int l, int r, int v, int h) {
        int L = v * (1<<h);
        int R = L + (1<<h) - 1;
        pushdown(v, h);
        if (L > r || R < l) {
            return;
        } else if (l <= L && r >= R) {
            tree[v] += x;
            lazy[v] += x;
            return;
        } else {
            delta(x, l, r, 2*v, h-1);
            delta(x, l, r, 2*v+1, h-1);
        }
        update(v);
    }
    int query(int l, int r, int v, int h) {
        int L = v * (1<<h);
        int R = L + (1<<h) - 1;
        pushdown(v, h);
        if (L > r || R < l) {
            return 0;
        } else if (l <= L && r >= R) {
            return (tree[v] == 0) ? (f[v]) : (0);
        } else {
            return query(l, r, 2*v, h-1) + query(l, r, 2*v+1, h-1);
        }
        update(v);
    }
public:
    void init(int n) {
        base = ceil(log2(n));
        size = 1 << base;
        build(n);
    }
    void delta(int x, int l, int r) {
        l += size - 1;
        r += size - 1;
        delta(x, l, r, 1, base);
    }
    int query(int l, int r) {
        l += size - 1;
        r += size - 1;
        return query(l, r, 1, base);
    }
    void print() const {
        for (int v = 1; v < 2*size; v++) {
            if (__builtin_popcount(v) == 1) {
                printf("\n");
            }
            printf("%d ", tree[v]);
        }
        printf("\n");
    }
};

/*
tree count;

int main() {
    int n;
    scanf("%d", &n);
    count.init(n);
    count.print();
}*/