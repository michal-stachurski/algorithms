// Breadth first search
#include <vector>
#include <queue>

std::vector<int> graph[];
int dist[]; // initially set to INF

void bfs(int s) {
    std::queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : graph[v]) {
            if (dist[u] == INFINITY) {
                q.push(u);
                dist[u] = dist[v] + 1;
            }
        }
    }
}
