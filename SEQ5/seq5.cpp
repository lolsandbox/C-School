#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 5;

int n, k;
int args[maxN], f[maxN];

int main() {

    freopen("seq5.inp", "r", stdin);
    freopen("seq5.out", "w", stdout);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> args[i];
    }

    int l = 1, r = 1, sum = 0;
    int res = 0;
    while (r < n) {
        sum += args[r];
        while (sum > k) {
            sum -= args[l];
            l++;
        }

        if (sum == k) {
            res = max(res, r - l + 1);
        }

        r++;
    }

    cout << res;
    return 0;
}