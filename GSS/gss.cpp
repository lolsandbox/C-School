#include <bits/stdc++.h>

using namespace std;

const int maxN = 5e4 + 5;

struct Nodes {
    int sum, prefix, suffix, best;
} nodes[maxN];

Nodes combine(Nodes l, Nodes r) {
    Nodes res;
    res.sum = l.sum + r.sum;
    res.prefix = max(l.prefix, l.sum + r.prefix);
    res.suffix = max(r.suffix, r.sum + l.suffix);
    res.best = max(max(l.best, r.best), l.suffix + r.prefix);
    return res;
}

int n, m;
int args[maxN];

void buildTree(int id, int l, int r) {
    if (l == r) {
        nodes[id].sum = nodes[id].prefix = nodes[id].suffix = nodes[id].best = args[l];
        return;
    }

    int mid = (l + r) / 2;
    buildTree(2 * id, l, mid);
    buildTree(2 * id + 1, mid + 1, r);

    nodes[id] = combine(nodes[2 * id], nodes[2 * id + 1]);
}

Nodes get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) return {-INT_MIN, -INT_MIN, 0, -INT_MIN};
    if (l >= u && r <= v) return nodes[id];

    int mid = (l + r) / 2;
    Nodes lt = get(2 * id, l, mid, u, v);
    Nodes rt = get(2 * id + 1, mid + 1, r, u, v);
    return combine(lt, rt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("gss.inp", "r", stdin);
    freopen("gss.out", "w", stdout);
    
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> args[i];
    buildTree(1, 1, n);

    cin >> m;
    while (m--) {
        int l, r; cin >> l >> r;
        cout << get(1, 1, n, l, r).best << "\n";
    }
    return 0;
}