#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        vector<int> v;
        vector<int> vOrd;
        for (int j = 0; j < c; j++) {
            int a;
            
            cin >> a;
            v.push_back(a);
        }

        vOrd = v;
        sort(v.rbegin(), v.rend());

        int num = 0;
        for (int j = 0; j < c; j++) {
            if (v[j] == vOrd[j]) {
                num++;
            }
        }
        cout << num << endl;
    }

    return 0;
}