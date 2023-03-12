#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e4 + 5;

int n, m, x, price, res = INT_MIN;
int p[maxN];

int main() {

    freopen("AUCTION.inp", "r", stdin);
    freopen("AUCTION.out", "w", stdout);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> p[i];
    }
    
    for (int i = 1; i <= m; i++) {
        int sum = 0;
        for (int j = 1; j <= m; j++) {
            if (p[j] >= p[i]) sum += p[i];
        }
        sum = min(sum, n * p[i]);
        if (sum > res) {
            res = sum;
            price = p[i];
        }
        if (sum == res) price = min(price, p[i]);
    }

    cout << price << " " << res;
    return 0;
}