#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    string a, b;

    cin >> n;

    while (n--) {   
        cin >> a >> b;

        size_t i = 0;
        size_t j = 0;

        while (i < a.length() && j < b.length()) {
            cout << a.at(i);
            cout << b.at(j);
            
            i++;
            j++;
        }

        while (i < a.length()) {
            cout << a.at(i);
            i++;
        }

        while (j < b.length()) {
            cout << b.at(j);
            j++;
        }
        
        cout << endl;
    }

    return 0;
}