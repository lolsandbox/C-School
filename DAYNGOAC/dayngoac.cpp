#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;

int n, m, l, r;
string s;

bool Validate(string s, int l, int r) {
    stack<int> st;
    for (int i = l; i <= r; i++) {
        if (s[i] == '(') {
            st.push(s[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("dayngoac.inp", "r", stdin);
    freopen("dayngoac.out", "w", stdout);

    cin >> n >> m >> s;

    while (m--) {
        cin >> l >> r;
        cout << Validate(s, l, r) << "\n";
    }
    
    return 0;
}