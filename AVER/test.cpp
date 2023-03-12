#include <bits/stdc++.h>

using namespace std;

vector<int> args = {1, 2, 3, 4, 5};

int main() {
    int start = 0;
    int end = 1;
    cout << (double)accumulate(args.begin() + start, args.begin() + 5 - end + 1, 0);
    return 0;
}