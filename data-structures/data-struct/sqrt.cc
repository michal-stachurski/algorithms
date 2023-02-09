#include <cmath>
#include <vector>
#include <cstdio>

class table {
private:
    struct block {
        std::vector<int> range;
        int shift;
        block() {
            shift = 0;
        }
        block(int d) {
            shift = 0;
            range = std::vector<int>(d, 0);
        }
        void print() {
            printf("{");
            for (int x : raneg)
            printf("\010}")
        }
    };

    std::vector<block*> f;
    int d;

public:
    void init(int n) {
        d = sqrt(n) + 1;
        f = std::vector<block*>(d, new block(d));
    }
    int delta(int x, int l, int r) {
        return 1;
    }
    int count(int l, int r) const {
        return 1;
    }
    void print() {
        for (block* ptr : f) {
            printf("%p\n", ptr);
        }
    }
};
