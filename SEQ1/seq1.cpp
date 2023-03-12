#include <bits/stdc++.h>

using namespace std;

const long long maxN = 1e6 + 5;

long long n, args[maxN], f[maxN], res = INT_MIN, m = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("seq1.inp", "r", stdin);
    freopen("seq1.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> args[i];
        f[i] = min(f[i], args[i]);
    }

    args[0] = INT_MAX;
    for (int i = 1; i <= n; i++) {
        m = min(m, args[i]);
        // cout << m << "\n";
        res = max(res, args[i] - m);
    }

    cout << res << "\n";
    return 0;
}