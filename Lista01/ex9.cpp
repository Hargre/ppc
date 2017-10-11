#include <bits/stdc++.h>

using namespace std;

int main() {
    string line;
    
    while (getline(cin, line)) {
        bool upper = true;

        for (size_t i = 0; i < line.length(); i++) {
            if (line.at(i) != ' ') {
                if (upper) {
                    putchar(toupper(line.at(i)));
                } else {
                    putchar(tolower(line.at(i)));
                }
                upper = !upper;
            } else {
                cout << ' ';
            }
        }

        cout << endl;
    }
    return 0;
}