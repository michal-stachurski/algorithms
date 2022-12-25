#include <algorithm>
#include <vector>
#include <cstdint>
#include <cstdio>

#include "../data-structures/disjoint_set.cc"

struct edge {
    int from, to, weight;
};

void kruskal() {
    int n, m; // nodes and edges
    scanf("%d%d", &n, &m);

    disjoint_set groups(n);
    std::vector<edge> edges;

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        edges.push_back({u, v, c});
    }

    sort(edges.begin(), edges.end(),
        [](const edge& e, const edge& f) -> bool {
            return e.weight < f.weight;
        }
    );

    std::vector<edge> mst;
    int w = 0;
    for (edge e : edges) {
        if (groups.find(e.from) != groups.find(e.to)) {
            groups.merge(e.from, e.to);
            mst.push_back(e);
            w += e.weight;
        }
    }
}
