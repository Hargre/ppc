#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
        
    long long a, l;
    int i = 1;

    while (cin >> a >> l, a != -1) {
        int n = 1;
        cout << "Case " << i << ": A = " << a << ", limit = " << l << ", number of terms = ";

        while (a != 1) {
            if (a > l) {
                n--;
                break;
            } else if (a % 2 == 0) {
                a /= 2;
            } else {
                a = a * 3 + 1;
            }
            n++;
        }
        i++;
        cout << n << endl;
    }

    return 0;
}