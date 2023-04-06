#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;
int n, q, cnt, found, res;
int L, R, k;
int args[maxN];
vector<long long> st[4 * maxN];

void buildTree(int id, int l, int r) {
    if (l == r) {
        st[id].push_back(args[l]);
        return;
    }

    int mid = (l + r) / 2;
    buildTree(2 * id, l, mid);
    buildTree(2 * id + 1, mid + 1, r);

    merge(st[2 * id].begin(), st[2 * id].end(), st[2 * id + 1].begin(), st[2 * id + 1].end(), back_inserter(st[id]));
}

void get(int id, int l, int r) {
    if (l > R || r < L) return;
    if (l >= L && r <= R) {
        int i = 0;
        int j = (int)st[id].size() - 1;
        int pos = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (st[id][mid] <= res) {
                pos = mid;
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
        if (pos == -1) return;
        cnt += pos + 1;
        if (st[id][pos] == res) found = true, cnt--;
        return;
    }
    int mid = (l + r) / 2;
    get(2 * id, l, mid);
    get(2 * id + 1, mid + 1, r);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("pttk.inp", "r", stdin);
    freopen("pttk.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> args[i];
    }

    buildTree(1, 1, n);

    cin >> q;
    while (q--) {
        cin >> L >> R >> k;
        int l = 0, r = (int)st[1].size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            cnt = 0;
            found = false;
            res = st[1][mid];
            get(1, 1, n);
            if (cnt == k - 1 && found == true) {
                cout << res << "\n";
                break;
            }
            if (cnt < k) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
    }

    return 0;
}