#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int n, q;
vector<int> args;
vector<long long> st[MAXN * 4];

void buildTree(int id, int l, int r ) {
    if (l == r) {
        st[id].push_back(a[l]);
        return ;
    }
    int mid = (l + r) / 2;
    buildTree(id*2, l, mid);
    buildTree(id*2 + 1, mid + 1, r);

    merge(st[id*2].begin(), st[id*2].end(), st[id*2+1].begin(), st[id*2+1].end(), st[id].begin());
}

long long getK(int id, int l, int r, int u, int v, int k) {
    if (v < l || r < u) {
        return 0;
    }
    if (u <= l && r <= v) {
        return st[id].size() - (upper_bound(st[id].begin(), st[id].end(), k) - st[id].begin());
    }

    int mid = (l + r) / 2;
    return 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("pttk.inp", "r", stdin);
    freopen("pttk.out", "w", stdout);

    cin >> n;

    args.resize(n + 5);
    for (int i = 1; i <= n; i++) cin >> args[i];
    // buildTree(1, 1, n);

    cin >> q;
    for(int i = 1; i <= q; i++) {
        int l, r, k; cin >> l >> r >> k;
        sort(args.begin() + l, args.begin() + r + 1, );
        cout << args[k] << "\n";
        for (int t = 1; t <= n; t++) {
            cout << args[t] << " ";
        }
        cout << "\n";
        // cout << get(1, 1, n, l, r, k) << "\n";
    }
    return 0;
}