#include <bits/stdc++.h>
using namespace std;

int n, m;
char col[20][20];
int ans[20][20];

int main() {
    freopen("hopscotch.in", "r", stdin);
    freopen("hopscotch.out", "w", stdout);
    // init
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", col[i]);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            for (int prei = 0; prei < i; prei++) {
                for (int prej = 0; prej < j; prej++) {
                    if (col[prei][prej] == col[i][j]) continue;
                    if (prei == 0 && prej == 0) {
                        ans[i][j]++;
                    } else {
                        ans[i][j] += ans[prei][prej];
                    }
                }
            }
        }
    }
    printf("%d\n", ans[n - 1][m - 1]);

    return 0;
}
