#include <bits/stdc++.h>

using namespace std;

const long long maxN = 1e6 + 5;
int n, args[maxN], f[maxN], g[maxN], res1 = INT_MIN, res = INT_MIN, m1 = INT_MAX, m2 = INT_MIN;

int main() {
    freopen("seq2.inp", "r", stdin);
    freopen("seq2.out", "w", stdout);

    cin >> n;

    args[0] = INT_MIN;
    g[0] = INT_MIN;
    for (int i = 1; i <= n; i++) {
        cin >> args[i];
    }

    for (int i = n; i >= 1; i--) {
        f[i] = min(f[i+1], args[i+1]);
    }

    for (int i = 1; i <= n; i++) {
        g[i] = max(g[i-1], args[i-1]);
    }

    for (int i = 1; i <= n; i++) {
        res = max(res, args[i] + g[i] - f[i]);
    }
    cout << res << "\n";
    return 0;
}