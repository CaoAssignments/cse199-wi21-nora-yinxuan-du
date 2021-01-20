#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PP;

char g[10][10];
bool isvisited[10][10];
int dx[4] = {0, 0, 1, -1}; // four directions for the next move
int dy[4] = {-1, 1, 0, 0};

int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);

    // input
    for (int i = 0; i < 10; i++)
        scanf("%s", g[i]);

    // find and denote the starting grid by (si, sj)
    int si = -1, sj = -1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (g[i][j] == 'B') {
                si = i;
                sj = j;
                break;
            }
        }
        if (si >= 0) break;
    }

    queue<PP> q;
    isvisited[si][sj] = true;
    q.push(PP(0, P(si, sj)));

    // BFS
    while (!q.empty()) {
        PP tmp = q.front(); q.pop();
        int num = tmp.first;  // number of steps from the starting grid
        int ii = tmp.second.first;  // row of the current grid
        int jj = tmp.second.second;  // column of the current grid
        for (int k = 0; k < 4; k++) {
            int nexti = ii + dx[k];
            int nextj = jj + dy[k];

            // check if the next grid is out of bound
            if (nexti < 0 || nexti >= 10 || nextj < 0 || nextj >= 10) continue;
            // check if the next grid has been visited or is a rock
            if (isvisited[nexti][nextj] || g[nexti][nextj] == 'R') continue;

            // any next grid (nexti, nextj) that gets here is isvalid
            // first check if it is the 'Lake' grid
            if (g[nexti][nextj] == 'L') {
                printf("%d\n", num);
                return 0;
            }

            // if not, then push the next grid into the queue q
            // continue this operation until we get to any neighboring grid
            // to the 'Lake' grid
            isvisited[nexti][nextj] = true;
            q.push(PP(num + 1, P(nexti, nextj)));
        }
    }
    return 0;
}
