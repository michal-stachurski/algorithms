// Finding sum in range and update in point

class fenwick_tree {
private:
    int* F;
    int n;

    constexpr int lsb(int x) {
        return x & -x;
    }
    int prefix(int i) {
        int r = 0;
        while (i > 0) {
            r += F[i];
            i -= lsb(i);
        }
        return r;
    }
public:
    fenwick_tree(int size) {
        n = size;
        F = new int[n+1];
    }
    void add(int i, int delta) {
        while (i <= n) {
            F[i] += delta;
            i += lsb(i);
        }
    }
    int sum(int l, int r) {
        return prefix(r) - prefix(l-1);
    }
};
