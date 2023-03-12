#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;

struct Data {
    int a, b;
};

bool cmp(Data x, Data y) {
    return (x.b > y.b || (x.b == y.b && x.a < y.a));
}

int n, res;
int s[maxN];
Data args[maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    freopen("pbcseq.inp", "r", stdin);
    freopen("pbcseq.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> args[i].a >> args[i].b;
    }

    sort(args + 1, args + n + 1, cmp);

    res = 1;
    s[1] = args[1].a;

    for (int i = 2; i <= n; i++) {
        int j = res;
        while (j > 0 && s[j] > args[i].a) {
            j--;
        }

        if (j == res) s[++res] = INT_MAX;
        s[j + 1] = min(s[j + 1], args[i].a);
    }

    cout << res;
    return 0;
}