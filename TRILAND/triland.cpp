#include <bits/stdc++.h>

using namespace std;

const long long maxN = 3e3 + 5;

set<pair<int, int>> points;
int n;

double distance(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

double heron(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    double a = distance(p1, p2);
    double b = distance(p2, p3);
    double c = distance(p3, p1);
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("triland.inp", "r", stdin);
    freopen("triland.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.insert(make_pair(x, y));
    }

    double maxArea = 0.0;
    for (auto it1 = points.begin(); it1 != prev(points.end(), 2); it1++) {
        for (auto it2 = next(it1); it2 != prev(points.end()); it2++) {
            for (auto it3 = next(it2); it3 != points.end(); it3++) {
                double area = heron(*it1, *it2, *it3);
                maxArea = max(maxArea, area);
            }
        }
    }

    cout << fixed << setprecision(1) << maxArea << endl;

    return 0;
}

