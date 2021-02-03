#include <bits/stdc++.h>
using namespace std;

string str;
int len;
int l[100005], r[100005];

int main() {
    freopen("typo.in", "r", stdin);
    freopen("typo.out", "w", stdout);

    cin >> str;
    len = str.length();

    if (len == 1) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (i > 0) l[i] = l[i - 1];
        if (str[i] == '(') l[i]++; else l[i]--;
    }
    for (int i = len - 1; i >= 0; i--) {
        if (i < len - 1) r[i] = r[i + 1];
        if (str[i] == ')') r[i]++; else r[i]--;
    }

    int ans = 0;
    if (l[len - 1] > 0) { // need to change ( to )
        for (int i = len - 1; i >= 1; i--) {
            if (str[i] == ')') continue;
            if (l[i - 1] > 0) ans++;
            if (r[i] < 0) break;
        }
    } else { // need to change ) to (
        for (int i = 0; i < len - 1; i++) {
            if (str[i] == '(') continue;
            if (r[i + 1] > 0) ans++;
            if (l[i] < 0) break;
        }
    }

    cout << ans << endl;
    return 0;
}
