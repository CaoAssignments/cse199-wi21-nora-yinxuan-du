#include <bits/stdc++.h>
using namespace std;

string str;
int len;
int pre[50005]; // the number of "((" before the index i

int main() {
    freopen("cowfind.in", "r", stdin);
    freopen("cowfind.out", "w", stdout);

    cin >> str;
    len = str.length();

    for (int i = 0; i < len - 1; i++) {
        pre[i + 1] = pre[i];
        if (str[i] == '(' && str[i + 1] == '(') {
            pre[i + 1]++;
        }
    }

    long long ans = 0;
    for (int i = len - 2; i >= 0; i--) {
        if (str[i] == ')' && str[i + 1] == ')') {
            ans += (long long)pre[i];
        }
    }
    cout << ans << endl;
    return 0;
}
