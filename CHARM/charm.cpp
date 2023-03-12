#include <bits/stdc++.h>

using namespace std;
const int N = 3405;

int n, m, f[N][13005];
struct data
{
    int w, d;
}

a[N];
bool cmp(const data &x, const data &y)
{
    return x.w < y.w;
}
int main()
{
    freopen("CHARM.inp", "r", stdin);
    freopen("CHARM.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].w >> a[i].d;
    }
    sort(a + 1, a + n + 1, cmp);

    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= a[i].w; j--)
        {
            f[i][j] = max(f[i][j], f[i - 1][j - a[i].w] + a[i].d);
        }
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = max(f[i][j], f[i - 1][j]);
        }
    }
    cout << f[n][m];
    return 0;
}