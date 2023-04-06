#include <bits/stdc++.h>

using namespace std;

const int maxN = 5e5 + 5;
struct Nodes {
    int sum;
    int maxSum;
    int maxLeft;
    int maxRight;
} st[4 * maxN];

int n, m;
int args[maxN];

void build(int id, int l, int r) {
    if (l == r) {
        st[id] = {args[l], args[l], args[l], args[l]};
        return;
    }

    int mid = (l + r) / 2;
    build(2 * id, l, mid);
    build(2 * id + 1, mid + 1, r);

    int sum = st[2 * id].sum + st[2 * id + 1].sum;
    int maxSum = max(max(st[2 * id].maxSum, st[2 * id + 1].maxSum), st[2 * id].maxRight + st[2 * id + 1].maxLeft);
    int maxLeft = max(st[2 * id].maxLeft, st[2 * id].sum + st[2 * id + 1].maxLeft);
    int maxRight = max(st[2 * id + 1].maxRight, st[2 * id + 1].sum + st[2 * id].maxRight);

    st[id] = {sum, maxSum, maxLeft, maxRight};
}

Nodes get(int id, int l, int r, int u, int v) {
    if (l > v || r < u) {
        return {0, -1000000000, -1000000000, -1000000000};
    }

    if (l >= u && r <= v) {
        return st[id];
    }

    int mid = (l + r) / 2;
    Nodes t1 = get(2 * id, l, mid, u, v);
    Nodes t2 = get(2 * id + 1, mid + 1, r, u, v);

    int sum = t1.sum + t2.sum;
    int maxSum = max(max(t1.maxSum, t2.maxSum), t1.maxRight + t2.maxLeft);
    int maxLeft = max(t1.maxLeft, t1.sum + t2.maxLeft);
    int maxRight = max(t2.maxRight, t1.maxRight + t2.sum);

    Nodes t = {sum, maxSum, maxLeft, maxRight};
    return t;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("gss.inp", "r", stdin);
    freopen("gss.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> args[i];
    }
    build(1, 1, n);

    for (int i = 1; i <= n * 4; i++) {
        cout << st[i].sum << " " << st[i].maxSum << " " << st[i].maxLeft << " " << st[i].maxRight << "\n";
    }
    cout << "\n";
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        Nodes ans = get(1, 1, n, l, r);
        cout << ans.sum << " " <<  ans.maxSum << " " << ans.maxLeft << " " << ans.maxRight << "\n";
    }
    return 0;
}