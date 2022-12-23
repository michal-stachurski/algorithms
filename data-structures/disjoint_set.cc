class disjoint_set {
private:
    int *rep;

public:
    void init(int n) {
        rep = new int[n+1];
        for (int v = 1; v <= n; v++) {
            rep[v] = v;
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
    void merge(int u, int v) {
        rep[find(u)] = find(v);
    }
};
