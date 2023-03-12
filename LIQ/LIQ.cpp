#include <bits/stdc++.h>

using namespace std;

const long long maxN = 1e5 + 5;

long long n, args[maxN], f[maxN], res = INT_MIN;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("liq.inp", "r", stdin);
    freopen("liq.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> args[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j >= 1; j--) {
            if (args[i] > args[j]) {
                f[i] = max(f[i], f[j]);
            }
        }
        f[i] += 1;
        res = max(res, f[i]);
    }

    cout << res;
    return 0;
}