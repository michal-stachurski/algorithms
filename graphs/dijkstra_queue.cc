#include <vector>
#include <queue>

struct adjacent {
    int to, weight;
};

struct pair {
    int destination, cost;
    bool operator<(const pair &other) const {
        return cost > other.cost; // force ascending order
    }
};

std::vector<adjacent> graph[];
int dist[]; // initially filled with INF

void dijkstra(int s) {
    dist[s] = 0;
    std::priority_queue<pair> q;
    q.push({s, 0});
    while (!Q.empty()) {
        int v = Q.top().destination;
        int d = Q.top().cost;
        Q.pop();
        if (dist[v] < d) {
            continue;
        }
        for (auto edge : graph[v]) {
            if (dist[edge.to] > dist[v] + edge.weight) {
                dist[edge.to] = dist[v] + edge.weight;
                Q.push({edge.to, dist[edge.to]});
            }
        }
    }
}