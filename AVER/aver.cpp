// #include <bits/stdc++.h>

// using namespace std;

// const int maxN = 1e6 + 5;

// int n;
// float k;
// vector<int> args(maxN);

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     freopen("aver.inp", "r", stdin);
//     freopen("aver.out", "w", stdout);

//     cin >> n >> k;
    
//     args.resize(n);

//     for (int i = 0; i < n; i++) {
//         cin >> args[i];
//     }

//     int ans = 0;

//     for (int i = 0; i < n; i++) {
//         float sum = 0;
//         for (int j = i; j < n; j++) {
//             sum += args[j];
//             float avg = sum / (j - i + 1);
//             // cout << avg << endl;
//             if (avg >= k) {
//                 ans = max(ans, j - i + 1);
//             }
//         }
//     }

//     cout << ans << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int n, k;
pair <long long, int> f[1000007];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("AVER.inp", "r", stdin);
    freopen("AVER.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        f[i].first = f[i - 1].first + (a - k);
        f[i].second = i;
    }

    sort(f + 1, f + n + 1);

    int vtmn = INT_MAX, ans = 0;

    for (int i = 1; i <= n; ++i) {
        vtmn = min(vtmn, f[i].second);
        if (f[i].second > vtmn) {
            ans = max(ans, f[i].second - (vtmn + 1) + 1);
        }
        if (f[i].first >= 0) {
            ans = max(ans, f[i].second);
        }
    }
    cout << ans << "\n";

    return 0;
}
