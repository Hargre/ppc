#include <bits/stdc++.h>

using namespace std;

int main() {
    int a = 0;
    int b = 0;

    for (int i = 0; i < 5; i++) {
        int temp; 
        cin >> temp;
        a |= temp << i;
    }

    for (int i = 0; i < 5; i++) {
        int temp; 
        cin >> temp;
        b |= temp << i;
    }

    a ^= b;

    if ((a & 0x1f) == 0x1f) {
        cout << 'Y' << endl;
    } else {
        cout << 'N' << endl;
    }


    return 0;
}