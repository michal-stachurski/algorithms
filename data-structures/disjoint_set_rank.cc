#include <utility>
using std::swap;

class disjoint_set {
private:
    int* rep;
    int* rank;

public:
    void init(int n) {
        rep = new int[n+1];
        rank = new int[n+1];
        for (int v = 1; v <= n; v++) {
            rep[v] = v;
            rank[v] = 0;
        }
    }
    int find(int v) {
        if (rep[v] == v) {
            return v;
        }
        int result = find(rep[v]);
        rep[v] = result; // path compression optimization
        return result;
    }
    void merge(int u, int v) { // merge by rank based on the depth of the trees
        u = find(u);
        v = find(v);
        if (u == v) {
            return;
        }
        if (rank[u] < rank[v]) {
            swap(u, v);
        }
        rep[v] = u;
        rank[u] += (rank[u] == rank[v]);
    }
};
