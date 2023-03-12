#include <bits/stdc++.h>

using namespace std;

int n, res = INT_MIN;
int args[100005], f1[100005], f2[100005], s[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("beadsnb.inp", "r", stdin);
    freopen("beadsnb.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> args[i];
    }

    int k = 1;
    s[1] = args[n];
    f1[n] = 1;

    for (int i = n - 1; i >= 1; i--) {
        int j = k;
        while (j > 0 && args[i] >= s[j]) j--;
        if (j == k) s[++k] = 0;
        s[j + 1] = max(s[j + 1], args[i]);
        f1[i] = j + 1;
    }

    k = 1;
    memset(s, 0, sizeof(s));
    s[1] = args[n];
    f2[n] = 1;

    for (int i = n - 1; i >= 1; i--) {
        int j = k;
        while (j > 0 && args[i] <=s[j]) j--;
        if (j == k) s[++k] = 1e9+7;
        s[j + 1] = min(s[j + 1], args[i]);
        f2[i] = j + 1;
    }

    for (int i = 1; i <= n; i++) {
        res = max(res, f1[i] + f2[i] - 1);
    }

    cout << res << endl;
    return 0;
}