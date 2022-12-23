#include <utility>
using std::swap;

class disjoint_set {
private:
    int* rep;
    int* size;

public:
    void init(int n) {
        rep = new int[n+1];
        size = new int[n+1];
        for (int v = 1; v <= n; v++) {
            rep[v] = v;
            size[v] = 1;
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
    void merge(int u, int v) { // merge by size of the trees
        u = find(u);
        v = find(v);
        if (u == v) {
            return;
        }
        if (size[u] < size[v]) {
            swap(u, v);
        }
        rep[v] = u;
        size[u] += size[v];
    }
};
