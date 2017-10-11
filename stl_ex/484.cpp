#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<pair<int, int>> p;

    while (cin >> n) {
        bool iv = false;

        for (auto &i : p) {
            if (i.first == n) {
                i.second = i.second + 1;
                iv = true;
                break;
            }
        }
        
        if (!iv) {
            pair<int, int> x(n, 1);
            p.push_back(x);
        }
    }

    for (auto i : p) {
        cout << i.first << ' ' << i.second << endl;
    }

    return 0;  
}