#include <bits/stdc++.h>

using namespace std;

const int maxN = 105;

struct Points {
    int x, y;
} args[maxN];

int n;

int Dis(Points a, Points b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("chungcu.inp", "r", stdin);
    freopen("chungcu.out", "w", stdout);

    cin >> n;

    // if (n <= 1) {
    //     cout << 1 << " " << setprecision(3) << fixed << 0.000;
    //     return 0;
    // }

    for (int i = 1; i <= n; i++) {
        cin >> args[i].x >> args[i].y;
    }

    int pos = 0;
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int distance = 0;
        for (int j = 1; j <= n; j++) {
            distance += abs(args[i].y - args[j].y);
        }
        if (ans > distance) {
            ans = distance;
        }
    }

    cout << ans << "\n";
    return 0;
}