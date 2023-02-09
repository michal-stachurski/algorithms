const int N = 1e6 + 1;

struct table {
private:
    int f[N];

public:
    void init(int n) {}
    void insert(int l, int r) {
        for (int i = l; i <= r; i++) {
            f[i] += 1;
        }
    }
    void erase(int l, int r) {
        for (int i = l; i <= r; i++) {
            f[i] -= 1;
        }
    }
    int count(int l, int r) const {
        int c = 0;
        for (int i = l; i <= r; i++) {
            c += (f[i] == 0);
        }
        return c;
    }
};
