// #include<bits/stdc++.h>

// using namespace std;

// int n, k, s[1000005], pos[1000005], x;

// void qs(int l, int r) {
//     if (l >= r) return;

//     int i = l, j = r, p = s[(l+r)/2];
//     while (i < j) {
//         while (s[i] < p) ++i;
//         while (s[j] > p) --j;

//         if (i > j) break;

//         swap(s[i], s[j]);
//         swap(pos[i], pos[j]);

//         ++i; --j;
//     }

//     qs(l, j); qs(i, r);
// }

// int main() {
//     freopen("seq9.inp", "r", stdin);
//     freopen("seq9.out", "w", stdout);

//     cin >> n >> k;
//     s[0] = 0;
//     for (int i = 1; i <= n; ++i) {
//         cin >> x;
//         s[i] = s[i-1] + x;
//         pos[i] = i;
//         s[i] = s[i] % k;
//     }

//     qs(1, n);

// //    for (int i = 1; i <= n; ++i) cout << s[i] << " ";
// //    cout << "\n";
// //    for (int i = 1; i <= n; ++i) cout << pos[i] << " ";

//     int l = 1;
//     int kq = 0;
//     for (int r = 1; r <= n; ++r) {
//         if (s[l] != s[r]) l = r;
//         kq =  max(kq, pos[r]-pos[l]);
//         if (s[r] == 0) kq = max(kq, pos[r]);
//     }

//     cout << kq << "\n";

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int find_longest_subarray_divisible_by_k(vector<int> a, int n, int k) {
    vector<int> count_mod(k);
    int sum = 0, longest_len = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        sum %= k;
        if (sum == 0) {
            longest_len = i+1;
        } else if (count_mod[sum] > 0) {
            longest_len = max(longest_len, i-count_mod[sum]+1);
        } else {
            count_mod[sum] = i+1;
        }
    }
    return longest_len;
}

int main() {
    int n, k;

    freopen("seq9.inp", "r", stdin);
    freopen("seq9.out", "w", stdout);

    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int longest_len = find_longest_subarray_divisible_by_k(a, n, k);
    cout << longest_len << endl;
    
    return 0;
}
