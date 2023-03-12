#include <bits/stdc++.h>

using namespace std;

int main() {
    int args[] = {88, 99, 11, 22, 22, 33, 22, 11};

    int res = 0;
    for (int i = 1; i <= 6; i++) {
        if (args[i - 1] <= args[i]) {
            res++;
        } else {
            res = 0;
        }
    }

    cout << res;
    return 0;
}