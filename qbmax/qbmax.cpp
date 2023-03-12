#include <bits/stdc++.h>

using namespace std;

int n, m, res = INT_MIN;
int args[105][105], f[105][105];

int main() {

    freopen("qbmax.inp", "r", stdin);
    freopen("qbmax.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        f[0][i] = -INT_MIN;
        f[n + 1][i] = -INT_MIN;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> args[i][j];
        }
    }

    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            f[i][j] = args[i][j] + max(f[i - 1][j - 1], max(f[i + 1][j - 1], f[i][j - 1]));
        }
    }

    for (int i = 1; i <= n; i++) res = max(res, f[i][m]);

    cout << res;
    return 0;
}