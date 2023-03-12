// #include <bits/stdc++.h>

// using namespace std;

// bool is_fibonacci(vector<int>& v) {
//     int n = v.size();
//     if (n < 3) {
//         return false;
//     }
//     for (int i = 2; i < n; i++) {
//         if (v[i-2] + v[i-1] != v[i]) {
//             return false;
//         }
//     }
//     return true;
// }

// int main() {
//     int n;

//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     freopen("seq6.inp", "r", stdin);
//     freopen("seq6.out", "w", stdout);

//     cin >> n;
//     vector<int> a(n);
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     int ans = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = i+2; j <= n; j++) {
//             vector<int> sub(a.begin() + i, a.begin() + j);
//             if (is_fibonacci(sub)) {
//                 ans = max(ans, j-i);
//             }
//         }
//     }
//     cout << ans << endl;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("SEQ6.inp", "r", stdin);
    freopen("SEQ6.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int prev = a[i], curr = a[i+1], len = 2;
        for (int j = i + 2; j < n; j++) {
            int next = prev + curr;
            if (a[j] == next) {
                prev = curr;
                curr = next;
                len++;
            }
            else {
                break;
            }
        }
        ans = max(ans, len);
    }

    cout << ans << endl;
    return 0;
}
