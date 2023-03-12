#include <bits/stdc++.h>

using namespace std;

int n, res = INT_MIN, res1;
int args[100005], f[100005], g[100005], s[100005];

int lis(int i) {
    int l = 1, r = res1, j = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (args[i] > args[s[m]]) {
            j = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
        if (j == res1) s[++res1] = i;
        if (args[i] < args[s[j + 1]]) s[j + 1] = i;
    }
    return j;
}

int main() {

    freopen("spseq.inp", "r", stdin);
    freopen("spseq.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> args[i];
    }

    f[1] = 1;
    s[1] = 1;
    res1 = 1;

    for (int i = 2; i <= n; i++) {
        int j = lis(i);
        f[i] = j + 1;
    }

    g[1] = 1;
    s[1] = n;
    res1 = 1;

    for (int i = n - 1; i >= 1; i--) {
        int j = lis(i);
        g[i] = j + 1;
    }

    for (int i = 1; i <= n; i++) {
        res = max(res, 2 * min(f[i], g[i]) - 1);
    }

    cout << res;
    return 0;
}