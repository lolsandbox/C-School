#include <bits/stdc++.h>

using namespace std;

int n, res = INT_MIN;;
vector<int> args(30005);


int main() {

    freopen("lis.inp", "r", stdin);
    freopen("lis.out", "w", stdout);

    cin >> n;

    args.resize(n);
    for (int i = 1; i <= n; i++) {
        cin >> args[i];
    }

    // f[1] = 1;
    // int res = 1;

    // for (int i = 2; i <= n; i++) {
    //     int l = 1, r = res, j = 0;
    //     while (l <= r) {
    //         int m = (l + r) / 2;
    //         if (args[i] > args[f[m]]) {
    //             j = m;
    //             l = m + 1;
    //         } else {
    //             r = m - 1;
    //         }
    //         if (j == res) f[++res] = i;
    //         if (args[i] < args[f[j + 1]]) f[j + 1] = i;
    //     }
    // }

    vector<int> f(n + 5), b(n + 5, INT_MAX);
    b[0] = INT_MIN;

    for (int i = 1; i <= n; i++) {
        int k = lower_bound(b.begin(), b.end(), args[i]) - b.begin();
        b[k] = args[i];
        res = max(res, k);
    }

    cout << res;
    return 0;
}