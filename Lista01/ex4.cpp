#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;

    getline(cin, str);

    if (str.length() <= 80) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}