#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    unsigned int x, y, result;

    while (cin >> x >> y) {
        result = x ^ y;
        cout << result << endl;
    }

    return 0;
}