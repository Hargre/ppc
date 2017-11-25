#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    set<int> a;
    set<int> b;
    vector<int> c;

    while (cin >> n >> m, n) {
        a.clear();
        b.clear();
        c.clear();

        int x;
        while (n--) {
            cin >> x;
            a.insert(x);
        }

        while (m--) {
            cin >> x;
            b.insert(x);
        }

        set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));

        cout << c.size() << endl;
    }

    return 0;
}