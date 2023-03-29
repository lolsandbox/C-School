#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 7;

int n, q;
int args[maxN];
long long st[maxN * 4];

void buildTree(int id, int l, int r) {
    if (l == r) {
        st[id] = args[l];
        return;
    }

    int mid = (l + r) / 2;
    buildTree(2 * id, l, mid);
    buildTree(2 * id + 1, mid + 1, r);

    st[id] = min(st[2 * id], st[2 * id + 1]);
}

void update(int id, int l, int r, int i, int v) {
    if (l > i || r < i) return;
    if (l == r) {
        st[id] = v;
        return;
    }

    int mid = (l + r) / 2;
    update(2 * id, l, mid, i, v);
    update(2 * id + 1, mid + 1, r, i, v);

    st[id] = min(st[2 * id], st[2 * id + 1]);
}

long long get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return INT_MAX;

    if (l >= u && r <= v) {
        return st[id];
    }

    int mid = (l + r) / 2;
    long long get1 = get(2 * id, l, mid, u, v);
    long long get2 = get(2 * id + 1, mid + 1, r, u, v);

    return min(get1, get2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("st0.inp", "r", stdin);
    freopen("st0.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> args[i];
    }

    buildTree(1, 1, n);

    cin >> q;

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 0) {
            update(1, 1, n, l, r);
        } else {
            cout << get(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}