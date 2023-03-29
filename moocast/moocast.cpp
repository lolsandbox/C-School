#include <bits/stdc++.h>

using namespace std;

const int maxN = 250005;

struct Cows {
    int x, y, dist;
};

vector<Cows> args;
int n;
int x[maxN], y[maxN];
int parent[maxN], r[maxN];

int find(int u) {
    return parent[u] < 0 ? u : parent[u] = find(parent[u]);
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (parent[u] < parent[v]) {
        swap(u, v);
    }
    parent[u] += parent[v];
    parent[v] = u;
    return true;
}

auto cmp = [&](Cows a, Cows b) {
    return a.dist < b.dist;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("moocast.inp", "r", stdin);
    freopen("moocast.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
        r[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int dx = x[i] - x[j];
            int dy = y[i] - y[j];
            args.push_back({i, j, (dx * dx) + (dy * dy)});
        }
    }

    sort(args.begin(), args.end(), cmp);

    int last = 0;
    int c = n;
    for (int i = 0; i < n; i++) {
        auto it = args[i];
        if (join(it.x, it.y)) {
            last = it.dist;
            if (--c == 1) break;
        }
    }

    cout << last << "\n";
    return 0;
}