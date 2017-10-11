#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    int ncase = 1;

    while (cin >> n >> q, n != 0) {
        cout << "CASE# " << ncase << ":" << endl;
        ncase++;

        vector<int> m;

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;

            m.push_back(num);
        }

        sort(m.begin(), m.end());

        for (int i = 0; i < q; i++) {
            int s;
            cin >> s;

            auto iter = find(m.begin(), m.end(), s);

            if (iter != m.end()) {
                auto pos = distance(m.begin(), iter);
                cout << s << " found at " << pos + 1 << endl;
            } else {
                cout << s << " not found" << endl;
            }
        }

    }

    return 0;
}