#include <bits/stdc++.h>
using namespace std;

int st, ed, n;
int ans;
bool stvisited;

int main() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);

    scanf("%d%d%d", &st, &ed, &n);

    ans = -1;
    for (int i = 0; i < n; i++) {
        int cst, m, stop;
        stvisited = false;
        scanf("%d%d", &cst, &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &stop);
            if (stop == st) stvisited = true;
            if (stop == ed && stvisited) {
                if (ans == -1 || ans > cst) ans = cst;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
