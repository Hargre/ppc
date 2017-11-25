#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    set<char> sc;

    cin >> s;
    sc = set<char>(begin(s), end(s));

    if (!((int)sc.size() % 2)) cout << "CHAT WITH HER!" << endl;
    else cout << "IGNORE HIM!" << endl;

    return 0;
}