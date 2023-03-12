#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;

int n, k;
int args[maxN], f[maxN];

int main() {
    
    freopen("VSTEPS.inp", "r", stdin);
    freopen("VSTEPS.out", "w", stdout);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) f[i] = 1;
    for (int i = 1; i <= k; i++) {
        cin >> args[0];
        f[args[0]] = 0;
    }

    args[args[0]] = 1;
    f[1] = 1;
    f[0] = 0;

    for (int i = 2; i <= n; i++) {
        if (f[i] != 0) {
            if (f[i - 1] == 0) {
                f[i] = (f[i - 2]) % 14062008;
            } else if (f[i - 2] == 0) {
                f[i] = (f[i- 1]) % 14062008;
            } else if (f[i - 1] == 0 && f[i - 2] == 0) {
                continue;
            } else {
                f[i] = (f[i - 1] + f[i-2]) % 14062008;
            }
        }
    }

    cout << f[n];
    return 0;
}