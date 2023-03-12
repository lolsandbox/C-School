#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e4 + 5;

int n, args[maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("daylom.inp", "r", stdin);
    freopen("daylom.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> args[i];
    }

    vector<int> f(n, 1), g(n, 1);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= i + 1; j--) {
            if (args[j] > args[i]) {
                g[i] = max(g[i], g[j] + 1);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (args[i] < args[j]) {
                f[i] = max(f[i], f[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        ans = max(ans, f[i] + g[i] - 1);
    }

    cout << ans << endl;
    return 0;
}
