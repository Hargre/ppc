#include <bits/stdc++.h>

using namespace std;

int main() {
    int k; 
    int count = 0;

    while (cin >> k, k != 0) {
        
        vector<int> v;
        int n;

        for (int i = 0; i < k; i++) {
            cin >> n;
            v.push_back(n);
        }

        if (count) {
            cout << endl;
        }
        count++;

        for (int a = 0; a < k - 5; a++) 
        for (int b = a + 1; b < k - 4; b++)
        for (int c = b + 1; c < k - 3; c++)
        for (int d = c + 1; d < k - 2; d++)
        for (int e = d + 1; e < k - 1; e++)
        for (int f = e + 1; f < k; f++)
            cout << v[a] << ' ' << v[b] << ' ' << v[c] << ' ' << v[d] << ' ' << v[e] << ' ' << v[f] << endl;
    }

    return 0;
}