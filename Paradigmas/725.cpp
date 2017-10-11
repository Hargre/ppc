#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    int c = 0;
    while (cin >> n, n !=0) {
        if (c) {
            cout << endl;
        }
        bool sol = false;
        for (int a = 1234; a <= 98765; a++) {
            int b = a * n;
            int bits = 0;
            int tmp = a;

            if (b > 98765) {
                continue;
            }
        
            for (int i = 0; i < 5; i++) {
                bits |= (1 << (tmp % 10));
                tmp /= 10;
            }
            
            tmp = b;
        
            for (int i = 0; i < 5; i++) {
                bits |= (1 << (tmp % 10));
                tmp /= 10;
            }
        
            if (bits == (1 << 10) - 1) {
                sol = true;
                cout << b << " / " << setfill('0') << setw(5) << a << " = " << n << endl;
            } 
        } 
        if (!sol) {
            cout << "There are no solutions for " << n << "." << endl;
        }
        c++;
    }
    
    return 0;
}