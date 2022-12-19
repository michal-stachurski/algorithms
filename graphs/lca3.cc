// Find lca(u, v) in rooted tree in O(log n)
// with O(n) preprocesing making Eulerian tour
// and O(log(n)) to find lca using segment tree (minimum on range)


/* NOT WORKING AS EXPECTED */
#include <cmath>
#include <vector>
#include <cstdio>
class tree_t {
private:
    const int INF = 2e9;
    int T[1<<22], index[1<<22];
    int base, size;

public:
    void init(int n, int* arr) {
        base = ceil(log2(n));
        size = 1 << base;
        int i = 0;
        for (i = 0; i < n; i++) {
            T[i + size] = arr[i];
            index[i + size] = i;
        } for (i; i < size; i++) {
            T[i + size] = INF;
            index[i + size] = i;
        }
        for (int b = base -1; b >= 0; b--) {
            for (int i = 1<<b; i < 2<<b; i++) {
                if (T[2*i] < T[2*i+1]) {
                    T[i] = T[2*i]; index[i] = index[2*i];
                } else {
                    T[i] = T[2*i+1]; index[i] = index[2*i+1];
                }
            }
        }
    }
    int min_index(int l, int r) { // zero based indexing
        l += size;
        r += size;
        if (l == r) return T[l];
        int m = std::min(T[l], T[r]);
        int i = (T[l] < T[r]) ? (index[l]) : (index[r]);
        while (l != r-1) {
            if (l % 2 == 0 && T[l+1] < m) {
                m = T[l+1]; i = index[l+1];
            }
            if (r % 2 == 1 && T[r-1] < m) {
                m = T[r-1]; i = index[r-1];
            }
            l /= 2;
            r /= 2;
        }
        return i;
    }
    void print() {
        for (int i = 1; i < 2*size; i++) {
            if (__builtin_popcount(i) == 1) printf("\n");
            printf("%d ", T[i]);
        }
        printf("\n\n");
        for (int i = 1; i < 2*size; i++) {
            if (__builtin_popcount(i) == 1) printf("\n");
            printf("%d ", index[i]);
        }
    }
};



constexpr int N = 1e6 + 1;
int n, k, depth[2*N], last[N], path[2*N];
std::vector<int> tree[N];
tree_t t;


void dfs(int v, int p, int d = 0) { // make Eulerian tour
    static int i = 0;
    path[i] = v; printf("%d ", v);
    depth[i] = d;
    last[v] = i;
    i++;
    for (int u : tree[v]) {
        if (u != p) {
            dfs(u, v, d + 1);
            path[i] = v; printf("%d ", v);
            depth[i] = d;
            last[v] = i;
            i++;
        }
    }
}
void init() {
    dfs(k, k); // where k is root node
    printf("\n\n");
    for (int i = 0; i < 2*n; i++) {
        printf("%d ", depth[i]);
    }
    printf("\n\n");
    t.init(2*n-1, depth);
    t.print();
    printf("\n");
}
int lca(int u, int v) {
    if (last[u] > last[v]) std::swap(u, v);
    // printf("(%d,%d)\n", last[u], last[v]);
    return path[t.min_index(last[u], last[v])];
}

#include <cstdio>

int main() {
    int q; scanf("%d%d%d", &n, &k, &q);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    init();
    while (q--) {
        int u, v; scanf("%d%d", &u, &v);
        printf("%d\n", lca(u, v));
    }
}