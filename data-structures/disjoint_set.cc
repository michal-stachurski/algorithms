#include <stddef.h>

class disjoint_set {
private:
    int* rep;

public:
    disjoint_set(size_t n) {
        rep = new int[n+1];
        for (size_t v = 1; v <= n; v++) {
            rep[v] = v;
        }
    }
    int find(int v) {
        if (rep[v] == v) {
            return v;
        }
        return rep[v] = find(rep[v]);
    }
    void merge(int u, int v) {
        rep[find(u)] = find(v);
    }
};
