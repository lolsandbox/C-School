#include <bits/stdc++.h>

using namespace std;

const int maxN = 3e5 + 5;

int n;
int args[maxN], h[maxN];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> args[i] >> h[i];
    }

    // sort(args, args + n, cmp), sort(h, h + n, cmp);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt = 0;
        for (int j = i + 1; j < n; j++) {
            if (args[i] >= args[j] || h[i] >= h[j]) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}