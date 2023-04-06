#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;

int n, q;
int args[maxN];
long long tree[maxN * 4];

void buildTree(int id, int l, int r) {
    if (l == r) {
        tree[id] = args[l];
        return;
    }

    int mid = (l + r) / 2;
    buildTree(2 * id, l, mid);
    buildTree(2 * id + 1, mid + 1, r);

    tree[id] = tree[2 * id] + tree[2 * id + 1];
}

void update(int id, int l, int r, int i, int v) {
    if (l > i || r < i) return;
    if (l == r) {
        tree[id] = v;
        return;
    }

    int mid = (l + r) / 2;
    update(2 * id, l, mid, i, v);
    update(2 * id + 1, mid + 1, r, i, v);

    tree[id] = tree[2 * id] + tree[2 * id + 1];
}

long long get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) {
        return tree[id];
    }

    int mid = (l + r) / 2;
    return get(2 * id, l, mid, u, v) + get(2 * id + 1, mid + 1, r, u, v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("st2.inp", "r", stdin);
    freopen("st2.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> args[i];
    }

    buildTree(1, 1, n);

    cin >> q;
    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            update(1, 1, n, l, r);
        } else {
            cout << get(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}