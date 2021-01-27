#include <bits/stdc++.h>
using namespace std;

int st, ed, n;
int ans;
int cst_st[10005], cst_ed[10005];

int main() {
    freopen("cowroute.in", "r", stdin);
    freopen("cowroute.out", "w", stdout);

    // init
    ans = -1;
    memset(cst_st, -1, sizeof(cst_st));
    memset(cst_ed, -1, sizeof(cst_ed));

    scanf("%d%d%d", &st, &ed, &n);
    for (int i = 0; i < n; i++) {
        int cst, m;
        scanf("%d%d", &cst, &m);

        int stop[m];
        int idx_st, idx_ed; idx_st = idx_ed = -1;
        for (int j = 0; j < m; j++) {
            scanf("%d", &stop[j]);
            if (idx_st == -1 && st == stop[j]) idx_st = j;
            if (ed == stop[j]) {
                idx_ed = j;
                if (idx_st != -1) {
                    if (ans == -1 || ans > cst)
                        ans = cst;
                }
            }
        }
        for (int j = 0; j < m; j++) {
            if (idx_st != -1 && j > idx_st) {
                if (cst_st[stop[j]] == -1 || cst_st[stop[j]] > cst)
                    cst_st[stop[j]] = cst;
            }
            if (idx_ed != -1 && j < idx_ed) {
                if (cst_ed[stop[j]] == -1 || cst_ed[stop[j]] > cst)
                    cst_ed[stop[j]] = cst;
            }
        }
    }

    for (int i = 1; i <= 10000; i++) {
        if (cst_st[i] != -1 && cst_ed[i] != -1) {
            if (ans == -1 || ans > cst_st[i] + cst_ed[i])
                ans = cst_st[i] + cst_ed[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
