#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        for (int i = 0; i < n; i = i + 2) {
            int num_s = (n - (i + 1)) / 2;
            cout << string(num_s, ' ') << string(i + 1, '*') << endl;
        }
        cout << string(((n - 1) / 2), ' ') << "*" << endl;
        cout << string(((n - 3) / 2), ' ') << "***" << endl;
        cout << endl;
    }

    return 0;
}