#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> e;
    vector<int> o;

    cin >> n;

    for (size_t i = 0; i < n; i++) {
        int j;
        cin >> j;

        if (j % 2 == 0) {
            e.push_back(j);
        } else {
            o.push_back(j);
        }
    }

    sort(e.begin(), e.end());
    sort(o.rbegin(), o.rend());

    for (auto i : e) {
        cout << i << endl;
    }

    for (auto i : o) {
        cout << i << endl;
    }

    return 0;
}