#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int n, q;
int args[MAXN];
vector<long long> tree[MAXN];

void buildTree(int id, int l, int r) {
    if (l == r) {
        tree[id].push_back(args[l]);
        return;
    }

    int mid = (l + r) / 2;
    buildTree(2 * id, l, mid);
    buildTree(2 * id + 1, mid + 1, r);

    merge(tree[id*2].begin(), tree[id*2].end(), tree[id*2+1].begin(), tree[id*2+1].end(), tree[id].begin());
}

int get(int id, int l, int r, int u, int v, int k) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) {
        return tree[id].size() - (upper_bound(tree[id].begin(), tree[id].end(), k) - tree[id].begin());
    }
    int mid = (l + r) / 2;
    return get(2 * id, l, mid, u, v, k) + get(2 * id + 1, mid + 1, r, u, v, k);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("pttk.inp", "r", stdin);
    freopen("pttk.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> args[i];
    buildTree(1, 1, n);

    cin >> q;
    for(int i = 1; i <= q; i++) {
        int l, r, k; cin >> l >> r >> k;
        cout << get(1, 1, n, l, r, k) << "\n";
    }
    return 0;
}