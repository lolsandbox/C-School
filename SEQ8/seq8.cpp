#include <bits/stdc++.h>
using namespace std;

int find_longest_monotonic_subsequence(vector<int> a, int n) {
    vector<int> f(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                f[i] = max(f[i], f[j]+1);
            }
        }
    }
    int longest_len = 0;
    for (int i = 0; i < n; i++) {
        longest_len = max(longest_len, f[i]);
    }
    return longest_len;
}

int main() {
    int n;

    freopen("seq8.inp", "r", stdin);
    freopen("seq8.out", "w", stdout);

    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int longest_len = find_longest_monotonic_subsequence(a, n);
    cout << n - longest_len << endl;
    
    return 0;
}
