#include <cstdio>

// #include "table.cc"
// #include "sqrt.cc"
#include "tree.cc"

tree t;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    t.init(n);
    while (q--) {
        int type, l, r;
        scanf("%d%d%d", &type, &l, &r);
        if (type == 1) {
            t.delta(+1, l, r);
        } else if (type == 2) {
            t.delta(-1, l, r);
        } else {
            printf("%d\n", t.query(l, r));
        }
        t.print();
        
    }
}