#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;

int n, q;
int parent[maxN];

int find(int u) {
    return parent[u] < 0 ? u : parent[u] = find(parent[u]);
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (parent[u] > parent[v]) {
        swap(u, v);
    }
    parent[
}

int main() {

    return 0;
}