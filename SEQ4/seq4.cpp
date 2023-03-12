#include <bits/stdc++.h>

using namespace std;

const long long maxN = 1e6 + 5;

int n;

pair<int, int> args[maxN];

int main() {
    freopen("seq4.inp", "r", stdin);
    freopen("seq4.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        args[i].first = args[i-1].first + x;
        args[i].second = i;
    }
    sort(args + 1, args + n + 1);

    int res = INT_MIN, flag = INT_MAX;
    for (int i = 1; i <= n; i++) {
        flag = min(flag, args[i].second);
        res = max(res, args[i].second - flag);
        if (args[i].first >= 0) {
            res = max(res, args[i].second);
        }
    }

    cout << res;
    
    return 0;
}