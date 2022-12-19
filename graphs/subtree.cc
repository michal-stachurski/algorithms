// Building segment tree on tree
// Performing such operations:
// add value to subtree, get value in node (both in O(log n))

#include <vector>
#include <cmath>

class seg_tree {
private:
    int T[1<<18];
    int size, base;
    int back = 0;

public:
    void init(int n) {
        base = ceil(log2(n));
        size = 1 << base;
        back = 0;
    }
    void push(int x) {
        T[back + size] = x;
        back++;
    }
    void add(int l, int r, int x) {
        l += size - 1;
        r += size - 1;
        if (l == r) {
            T[l] += x;
            return;
        }
        T[l] += x;
        T[r] += x;
        while (l != r-1) {
            if (l % 2 == 0) {
                T[l+1] += x;
            }
            if (r % 2 == 1) {
                T[r-1] += x;
            }
            l /= 2;
            r /= 2;
        }
    }
    int operator[](int i) const {
        i += size - 1;
        int result = T[i];
        while (i /= 2) {
            result += T[i];
        }
        return result;
    }
};

const int N = 100;
std::vector<int> tree[N];
int begin[N], end[N], depth[N];

seg_tree dist;

void dfs(int v, int p) {
    static int idx = 0;

    begin[v] = ++idx;
    dist.push(depth[v]); // can be an value f(v), order matters
    for (int u : tree[v]) {
        if (u != p) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
    end[v] = idx;
}


void init(int n) {
    dist.init(n);
    dfs(1, 1);
}

void update(int u, int v, int d) {
    if (depth[u] > depth[v]) {
        std::swap(u, v);
    }
    dist.add(begin[v], end[v], d); // adding d to lenght of (u, v) edge
}

int get(int v) {
    // returns value for v (distance from 1 in this example)
    return dist[begin[v]];
}
