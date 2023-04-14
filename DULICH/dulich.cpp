#include <bits/stdc++.h>

using namespace std;

const int maxN = 105;

struct Points {
    double x, y;
} args[maxN];

int n;

double Dis(Points a, Points b) {
    return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("dulich.inp", "r", stdin);
    freopen("dulich.out", "w", stdout);

    cin >> n;

    // if (n <= 1) {
    //     cout << 1 << " " << setprecision(3) << fixed << 0.000;
    //     return 0;
    // }

    for (int i = 1; i <= n; i++) {
        cin >> args[i].x >> args[i].y;
    }

    int pos = 0;
    double ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        double distance = 0;
        for (int j = 1; j <= n; j++) {
            distance += Dis(args[i], args[j]);
        }
        if (distance < ans) {
            ans = distance;
            pos = i;
        }
    }

    cout << pos << " " << setprecision(3) << fixed << ans << "\n";
    return 0;
}