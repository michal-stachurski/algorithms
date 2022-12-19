// Find lca(u, v) in rooted tree with preprocesing using jump pointers (binary lifting)
// Time: O(log n); Preprocessing: O(n log n)
// Space: O(n log n)

#include <vector>

constexpr int N = 1e6 + 1, LOG = 20;
int n, k, depth[N], jump_ptr[LOG][N];
std::vector<int> tree[N];

void dfs(int v, int p) {
    jump_ptr[0][v] = p;
    for (int u : tree[v]) {
        if (u != p) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
}
void init() {
    dfs(k, k); // where k is root node
    for (int i = 1; i < LOG; i++) {
        for (int v = 1; v <= n; v++) {
            jump_ptr[i][v] = jump_ptr[i-1][jump_ptr[i-1][v]];
        }
    }
}

int jump(int v, int d) { // jump d steps up from v
    int i = 0;
    while (d > 0) {
        if (d & 1) v = jump_ptr[i][v];
        d /= 2;
        i++;
    }
    return v;
}
int lca(int u, int v) {
    if (depth[u] > depth[v]) std::swap(u, v);
    v = jump(v, depth[v] - depth[u]);
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (jump_ptr[i][u] != jump_ptr[i][v]) {
            u = jump_ptr[i][u], v = jump_ptr[i][v];
        }
    }
    return jump_ptr[0][u];
}
