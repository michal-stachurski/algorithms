// Kuhn's Algorithm for Maximum Bipartite Matching
// Time complexity: O(n*m)

#include <cstdio>
#include <vector>
// #include <cassert>

const int N = 100 + 1;
std::vector<int> graph[N], side[2];
std::vector<bool> visited;
bool color[N];
int match[N];
int n, m;

void bipartite(int v) {
    visited[v] = true;
    side[color[v]].push_back(v);
    for (int u : graph[v]) {
        if (!visited[u]) {
            color[u] = !color[v];
            bipartite(u);
        }
    }
}

bool find_path(int v) {
    if (visited[v]) {
        return false;
    }
    visited[v] = true;
    for (int u : graph[v]) {
        if (!match[u] || find_path(match[u])) {
            match[u] = v;
            return true;
        }
    }
    return false;
}

int main() {
    // reading the graph
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        // assumption: graph is bipartite
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visited.assign(n+1, false);
    for (int v = 1; v <= n; v++) {
        if (!visited[v]) {
            bipartite(v); // splitting nodes into sides
        }
    }

    for (int v : side[0]) {
        visited.assign(n+1, false);
        find_path(v); // trying to find augmenting path
    }

    size_t size = 0;
    for (int v : side[1]) {
        size += (match[v] != 0); // counting edges in matching
        if (match[v]) {
            printf("(%d,%d)\n", v, match[v]);
        }
    }
    printf("%ld\n", size);
}
