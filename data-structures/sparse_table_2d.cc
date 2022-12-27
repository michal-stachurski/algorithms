#include <algorithm>
#include <cmath>
using std::min;

class sparse_table_2d {
private:
    static const int N = 1e3, LOG = 11;
    int tab[LOG][N][N];

public:
    void init(int n, int m, int** grid) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                tab[0][i][j] = grid[i][j];
            }
        }
        for (int k = 1; k < LOG; k++) {
            int l = 1<<(k-1);
            for (int i = 1; i+l <= n; i++) {
                for (int j = 1; j+l <= m; j++) {
                    int l = 1<<(k-1);
                    tab[k][i][j] = min({
                        tab[k-1][i][j],
                        tab[k-1][i+l][j],
                        tab[k-1][i][j+l],
                        tab[k-1][i+l][j+l]
                    });
                }
            }
        }
    }
    int min_subarray(int x, int y, int l) const {
        int k = log2(l);
        return min({
            tab[k][x][y],
            tab[k][x][y+l-(1<<k)],
            tab[k][x+l-(1<<k)][y],
            tab[k][x+l-(1<<k)][y+l-(1<<k)]
        });
    }
};
