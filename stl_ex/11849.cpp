#include <bits/stdc++.h>

using namespace std;

int main() {
    int jack, jill;

    while (cin >> jack >> jill, jack != 0) {
        set<int> ca;
        set<int> cb;
        set<int> in;

        for (int i = 0; i < jack; i++) {
            int num;
            cin >> num;

            ca.insert(num);
        }

        for (int i = 0; i < jill; i++) {
            int num;
            cin >> num;

            cb.insert(num);
        }

        set_intersection(ca.begin(), ca.end(), cb.begin(), cb.end(), inserter(in, in.begin()));

        cout << in.size() << endl;
    }

    return 0;
}