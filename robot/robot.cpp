#include <bits/stdc++.h>

using namespace std;

int n, m, res = INT_MIN;
int args[105][105], f[105][105];

int main() {

    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);

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

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = args[i][j] + max(f[i][j - 1], f[i - 1][j]);
        }
    }

    for (int i = 1; i <= n; i++) res = max(res, f[i][m]);

    cout << res;
    return 0;
}