#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int caso = 1;

    while (cin >> n) {
        int i_num = 1;

        for (int i = 0; i <= n; i++) {
            i_num += i;
        }

        cout << "Caso " << caso << ": " << i_num << ((i_num == 1) ? " numero" : " numeros") << endl;

        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                cout << "0";
            } else {
                for (int j = 0; j < i; j++) {
                    cout << ' ' << i;
                }
            }
        }
        cout << endl << endl;
        caso++;
    }

    return 0;
}