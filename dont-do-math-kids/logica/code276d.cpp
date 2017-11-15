#include <bits/stdc++.h>

using namespace std;

int main() {
    long long l, r;

    cin >> l >> r;

    if (l == r) {
        cout << '0' << endl; 
        return 0;
    }

    int p = 64 - __builtin_clzll(l ^ r);
    cout << (1LL << p) - 1 << endl;

    return 0;
}