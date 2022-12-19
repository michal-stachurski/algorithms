// Find lca(u, v) in rooted tree with preprocesing using
// jump pointers (binary lifting) and ancestor method
// Time: O(log n); Preprocessing: O(n log n)
// Space: O(n log n)


#include <vector>

constexpr int N = 1e6 + 1, LOG = 20;
int n, k, pre[N], post[N], jump_ptr[LOG][N];
std::vector<int> tree[N];

void dfs(int v, int p) {
    static int i = 0, j = 0;
    
    jump_ptr[0][v] = p;
    pre[v] = i++;
    for (int u : tree[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
    post[v] = j++;
}
void init() {
    dfs(k, k); // where k is root node
    for (int i = 1; i < LOG; i++) {
        for (int v = 1; v <= n; v++) {
            jump_ptr[i][v] = jump_ptr[i-1][jump_ptr[i-1][v]];
        }
    }
}

bool ancestor(int u, int v) { // if u is ancestor of v
    return (u == v) || (pre[u] < pre[v] && post[u] > post[v]);
}
int lca(int u, int v) {
    if (ancestor(u, v)) return u;
    if (ancestor(v, u)) return v;
    for (int i = LOG - 1; i >= 0; i--) {
        if (!ancestor(jump_ptr[i][u], v)) {
            u = jump_ptr[i][u];
        }
    }
    return jump_ptr[0][u];
}
