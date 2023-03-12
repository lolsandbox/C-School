#include <bits/stdc++.h>

using namespace std;

int n, m, res = INT_MIN;
int args[105][105], f[105][105];

int check (int i, int j){
    if (i <= m && i >= 1 && j <= n && j >= 1){
        return f[i][j];
    }
    return 0;
}

int main() {

    freopen("bctest15.inp", "r", stdin);
    freopen("bctest15.out", "w", stdout);

    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> args[i][j];
            if (i == 1) {
                f[i][j] = args[i][j];
            }
        }
    }

    for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = max(max(check(i-1, j-2), check(i-2, j-1)), max(check(i-2, j+1), check(i-1, j+2))) + args[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (f[m][i] > res) {
            res = f[m][i];
        }
    }

    cout << res << endl;
    return 0;
}