#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> sentences;
    string line;
    size_t max = 0;

    while (getline(cin, line)) {
        sentences.push_back(line);
        if (line.length() > max) {
            max = line.length();
        }
    }

    for (size_t i = 0; i < max; i++) {
        for (int j = sentences.size() - 1; j >= 0; j--) {
            if (sentences[j].length() > i) {
                if (sentences[j][i] == '\0' || sentences[j][i] == '\n') {
                    cout << ' ';
                } else {
                    cout << sentences[j][i];
                }
            } else {
                cout << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}