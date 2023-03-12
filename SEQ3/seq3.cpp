#include <bits/stdc++.h>

using namespace std;

const long long maxN = 1e6 + 5;
int n, args[maxN];

int main() {
    freopen("seq3.inp", "r", stdin);
    freopen("seq3.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> args[i];
    }

    int m1 = args[1], m2 = args[1];
    for (int i = 2; i <= n; i++) {
        m1 = max(args[i], m1 + args[i]);
        m2 = max(m2, m1);
    }

    cout << m2 << "\n";
    return 0;
}