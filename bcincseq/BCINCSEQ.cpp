#include <bits/stdc++.h>

using namespace std;

int n, dem = 1, res = 1;
int args[30005], f[30005];


int main() {

    freopen("BCINCSEQ.inp", "r", stdin);
    freopen("BCINCSEQ.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> args[i];
    }

    
    args[n + 1] = args[n - 1];

    for (int i = 2; i <= n + 1; i++) {
        if (args[i] >= args[i - 1]) {
            dem++;
        } else {
            res = max(res, dem);
            dem = 1;
        }
    }

    cout << res;
    return 0;
}