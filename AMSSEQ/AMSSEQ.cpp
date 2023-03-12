#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("AMSSEQ.inp", "r", stdin);
    freopen("AMSSEQ.out", "w", stdout);

    cin >> n >> k;

    int args[n + 5], f[n + 5];
    int res = INT_MIN;

    args[0] = 0, f[0] = 0;
    memset(args, 0, sizeof(args));
    memset(f, 0, sizeof(f));

    for (int i = 1; i <= n; i++) {
        cin >> args[i];
        f[i] = -INT_MIN;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                f[i] = max(f[i], f[i - j] + args[i]);
            }
        }
        res = max(res, f[i]);
    }

    cout << res;
    return 0;
}
