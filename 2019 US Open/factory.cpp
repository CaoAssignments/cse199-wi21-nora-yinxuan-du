#include <bits/stdc++.h>
using namespace std;

int n;
int c[105]; // c[i] saves the current parent of node i

int fnd(int x) // return the ancestor (root) of node x
{
    return c[x] == x ? x : c[x] = fnd(c[x]);
}

int main() {
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    scanf("%d", &n);

    // initialize all nodes by setting all their parents as themselves
    for (int i = 1; i <= n; i++) {
        c[i] = i;
	}

	// Union Find
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        // let v become u and all its descendants' ancestor (root)
        if(fnd(u)!=fnd(v)) {
            c[u] = fnd(c[v]);
        }
    }

    // check if all nodes share the same ancestor (root)
    // if yes, then the final answer is this ancestor (root)
    int ans = fnd(c[1]);
    for (int i = 2; i <= n; i++) {
        if (ans != fnd(c[i])) {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}
