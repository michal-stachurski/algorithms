#include <vector>
#include <set>

struct pair {
    int to, weight;
};
std::vector<pair> graph[];
int d[]; // initially assigned to INF
int n, m;

void dijkstra(int s) {
    auto cmp = [](int u, int v) {
        return d[u] <= d[v];
    };
    std::set<int, decltype(cmp)> q; // C++20
    // std::set<int, decltype(cmp)> q(cmp); // C++11
    d[s] = 0;
    q.insert(s);
    while (!q.empty()) {
        int v = *q.begin();
        q.erase(q.begin());
        for (auto edge : graph[v]) {
            if (d[edge.to] > d[v] + edge.weight) {
                q.erase(edge.to);
                d[edge.to] = d[v] + edge.weight;
                q.insert(edge.to);
            }
        }
    }
}
