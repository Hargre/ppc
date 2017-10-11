#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    set<string> dic;

    while (cin >> s) {
        string cur = "";

        for (int i = 0; i < s.size(); i++) {
            char c = tolower(s[i]);

            if (isalpha(c)) {
                cur += c;
            } else if (cur != "") {
                dic.insert(cur);
                cur = "";
            }
        }
        if (cur != "") {
            dic.insert(cur);
        }
    }

    for (auto s : dic) {
        cout << s << endl;
    }

    return 0;
}