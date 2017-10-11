#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;

    while (cin >> a >> b, a != 0) {
        set<int> as;
        set<int> bs;

        for (int i = 0; i < a; i++) {
            int n;
            cin >> n;

            as.insert(n);
        }

        for (int i = 0; i < b; i++) {
            int n;
            cin >> n;

            bs.insert(n);
        }

        set<int> da;
        set<int> db;

        set_difference(as.begin(), as.end(), bs.begin(), bs.end(), inserter(da, da.begin()));
        set_difference(bs.begin(), bs.end(), as.begin(), as.end(), inserter(db, db.begin()));

        cout << min(da.size(), db.size()) << endl;
    }

    return 0;
}