#include <bits/stdc++.h>

using namespace std;

const int maxN = 5 * 1e5 + 5;

int n;
int args[maxN], dp[maxN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("seq7.inp", "r", stdin);
    freopen("seq7.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> args[i];
    }

    // subtask: 5 * 10^5 -> O(log n) -> 9d
    vector<int> tail;
    tail.push_back(args[0]);

    for (int i = 1; i < n; i++) {
        if (args[i] > tail.back()) {
            tail.push_back(args[i]);
        } else {
            auto it = lower_bound(tail.begin(), tail.end(), args[i]);
            *it = args[i];
        }
    }

    cout << tail.size() << endl;

    // subtask: 5 * 10^5 -> O(n) -> 9d
    // dp[0] = args[0];

    // int res = 0;
    // for (int i = 1; i <= n - 1; i++) {
    //     int j = lower_bound(dp + 1, dp + res + 1, args[i]) - dp;
    //     dp[j] = args[i];
    //     res = max(res, j);
    // }

    // cout << res << endl;

    // O(n ^ 2) -> 6d
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < i; j++) {
    //         if (i > j && args[i] > args[j]) {
    //             dp[i] = max(dp[i], dp[j] + 1);
    //         }
    //     }
    // }

    // cout << *max_element(dp.begin(), dp.end()) << endl;
    return 0;
}
