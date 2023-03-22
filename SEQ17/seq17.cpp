#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 5;

int n, q;
int a[MAXN];
long long tree[MAXN * 4], lazy[MAXN * 4];

void build(int node, int left, int right) {
    if (left == right) {
        lazy[node] = 0;
        tree[node] = a[left];
        return;
    }
    lazy[node] = 0;
    int mid = (left + right) / 2;
    build(node * 2, left, mid);
    build(node * 2 + 1, mid + 1, right);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void push_down(int node, int left, int right) {
    if (lazy[node] != 0 && left < right) {
        int mid = (left + right) / 2;
        tree[node * 2] += lazy[node] * (mid - left + 1);
        tree[node * 2 + 1] += lazy[node] * (right - mid);
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
        lazy[node] = 0;
    }
}

void update(int node, int left, int right, int l, int r, int val) {
    if (left > r || right < l) return;
    if (left >= l && right <= r) {
        push_down(node, left, right);
        tree[node] += (right - left + 1) * val;
        lazy[node] += val;
        return;
    }
    push_down(node, left, right);
    int mid = (left + right) / 2;
    update(node * 2, left, mid, l, r, val);
    update(node * 2 + 1, mid + 1, right, l, r, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long query(int node, int left, int right, int l, int r) {
    if (left > r || right < l) return 0;
    if (left >= l && right <= r) return tree[node];
    push_down(node, left, right);
    int mid = (left + right) / 2;
    long long sum_left = query(node * 2, left, mid, l, r);
    long long sum_right = query(node * 2 + 1, mid + 1, right, l, r);
    return sum_left + sum_right;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("seq17.inp", "r", stdin);
    freopen("seq17.out", "w", stdout);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 0) {
            int t;
            cin >> t;
            update(1, 1, n, l, r, t);
        } else {
            cout << query(1, 1, n, l, r) << '\n';
        }
    }

    return 0;
}
