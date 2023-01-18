// Depth First Search
#include <vector>

std::vector<int> graph[];
bool visited[];

void dfs(int v) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

std::vector<int> tree[];

void dfs(int v, int p = 0) {
    for (int u : tree[v]) {
        if (u != p) {
            dfs(u, v);
        }
    }
}
