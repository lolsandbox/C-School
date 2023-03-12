#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e6 + 5;

int n;
float k;
vector<int> args(maxN);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("aver.inp", "r", stdin);
    freopen("aver.out", "w", stdout);

    cin >> n >> k;
    
    args.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> args[i];
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = i; j < n; j++) {
            sum += args[j];
            float avg = sum / (j - i + 1);
            // cout << avg << endl;
            if (avg >= k) {
                ans = max(ans, j - i + 1);
            }
        }
    }

    cout << ans << endl;
    return 0;
}