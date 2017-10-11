#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    while (cin >> n, n !=0) {
        bitset<32> o(n);
        bitset<32> a;
        bitset<32> b; 

        bool ia = true;

        for (int i = 0; i < 32; i++) {
            if (o[i]) {
                if (ia) {
                    a.set(i);
                } else {
                    b.set(i);
                }
                ia = !ia;
            }
        }

        unsigned long int ua = a.to_ulong();
        unsigned long int ub = b.to_ulong();

        cout << ua << ' ' << ub << endl;
    }

    return 0;  
}