#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 5;

int n;
double k;
int args[maxN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("aver.inp", "r", stdin);
    // freopen("aver.out", "w", stdout);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> args[i];
    }
    int ans = 0;
    double sum = 0;
    int left = 0, right = 0;
    while(right < n) {
        sum += args[right];
        while(sum / (right - left + 1) >= k) {
            ans = max(ans, right - left + 1);
            sum -= args[left];
            left++;
        }
        right++;
    }
    cout << ans << endl;
    return 0;
}
