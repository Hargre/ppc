#include <bits/stdc++.h>

using namespace std; 

int main() {
    int n;

    while(cin >> n) {
        int sq = n / 3;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == j) && (i == n / 2)) {
                    cout << '4';
                } else if ((i >= sq && i < (n - sq)) && (j >= sq && j < (n- sq))) {
                    cout << '1';
                } else if (i == j) {
                    cout << '2';
                } else if (j == (n - (i + 1))) {
                    cout << '3';
                } else {
                    cout << '0';
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}