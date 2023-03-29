#include <bits/stdc++.h>


using namespace std;

int n, q;
vector<int> args;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("xephang.inp", "r", stdin);
    freopen("xephang.out", "w", stdout);

    cin >> n >> q;

    args.resize(n + 5);
    for (int i = 1; i <= n; i++) cin >> args[i];

    while (q--) {
        int l, r; cin >> l >> r;
        cout << *max_element(args.begin() + l, args.begin() + r + 1) - *min_element(args.begin() + l, args.begin() + r + 1) << "\n";
    }
    return 0;
}