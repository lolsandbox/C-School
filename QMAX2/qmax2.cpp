#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int n, m;
int a[MAXN];
long long tree[MAXN * 4], lazy[MAXN * 4];

void push_down(int node) {
    if (lazy[node] != 0 && left < right) {
        int t = lazy[node];
        tree[2 * node] += t;
        tree[2 * node + 1] += t;

        lazy[2 * node] += t;
        lazy[2 * node + 1] += t;

        lazy[node] = 0;
    }
}

void update(int node, int left, int right, int l, int r, int val) {
    if (left > r || right < l) return;
    if (left >= l && right <= r) {
        push_down(node);
        tree[node] += val;
        lazy[node] += val;
        return;
    }
    push_down(node);
    int mid = (left + right) / 2;
    update(node * 2, left, mid, l, r, val);
    update(node * 2 + 1, mid + 1, right, l, r, val);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

long long query(int node, int left, int right, int l, int r) {
    if (left > r || right < l) return 0;
    if (left >= l && right <= r) return tree[node];
    push_down(node);
    int mid = (left + right) / 2;
    long long getL = query(node * 2, left, mid, l, r);
    long long getR = query(node * 2 + 1, mid + 1, right, l, r);
    return max(getL, getR);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("qmax2.inp", "r", stdin);
    freopen("qmax2.out", "w", stdout);
    

    cin >> n >> m;

    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 0) {
            int t; cin >> t;
            update(1, 1, n, l, r, t);
        } else {
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}