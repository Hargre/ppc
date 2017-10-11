#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;

    cin >> t;

    while (t--) {
        deque<pair<int, int>> d;
        int n, m;

        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pair<int, int> p(x, i);

            d.push_back(p);
        }

        auto i = d.at(m);
        int num = 0;

        while (!d.empty()) {
            auto f = d.front();
            bool hl = false;

            for (auto a : d) {
                if (a.first > f.first) {
                    d.pop_front();
                    d.push_back(f);
                    hl = true;
                    break;
                }
            }
            if (!hl) {
                if (d.front() == i) {
                    num++;
                    break;
                }
                d.pop_front();
                num++;
            }
        } 

        cout << num << endl;
    }

    return 0;  
}