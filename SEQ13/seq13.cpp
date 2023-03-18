#include <bits/stdc++.h>

using namespace std;

const int maxN = 10000007;

int n, t;
int args[maxN], st[maxN];

void buildTree(int id, int l, int r) {
    if (l == r) {
        st[id] = args[l];
        return;
    }

    int mid = (l + r) / 2;
    buildTree(id * 2, l, mid);
    buildTree(id * 2 + 1, mid + 1, r);

    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) {
        return INT_MIN;
    }

    if (l >= u && r <= v) {
        return st[id];
    }

    int mid = (l + r) / 2;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    freopen("seq13.inp", "r", stdin);
    freopen("seq13.out", "w", stdout);

    cin >> n >> t;

    for (int i = 1; i <= n; i++) {
        cin >> args[i];
    }

    buildTree(1, 1, n);

    int l, r;
    for (int i = 1; i <= t; i++) {
        cin >> l >> r;
        cout << get(1, 1, n, l, r) << endl;
    }
    return 0;
}