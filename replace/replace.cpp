#include <bits/stdc++.h>

using namespace std;

const int maxN = 255;

int n;
string s, t;
int parent[maxN], r[maxN];

int find(int u) {
    return u == parent[u] ? u : parent[u] = find(parent[u]);
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (r[u] == r[v]) r[u]++;
    if (r[u] < r[v]) {
        parent[u] = v;
    } else {
        parent[v] = u;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("replace.inp", "r", stdin);
    freopen("replace.out", "w", stdout);

    cin >> n >> s >> t;

    for (int i = 0; i < maxN; i++) {
        parent[i] = i;
        r[i] = 0;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (join(s[i], t[i])) {
            ans++;
        }
    }

    cout << ans << "\n";
    for (int i = 0; i < maxN; i++) {
        if (parent[i] != i) {
            cout << (char)i << " " << (char)parent[i] << "\n";
        }
    }
    return 0;
}
