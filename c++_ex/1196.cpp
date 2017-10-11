#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    map <char, char> q;

    q['1'] = '`';
    q['2'] = '1';
    q['3'] = '2';
    q['4'] = '3';
    q['5'] = '4';
    q['6'] = '5';
    q['7'] = '6';
    q['8'] = '7';
    q['9'] = '8';
    q['0'] = '9';
    q['-'] = '0';
    q['='] = '-';

    q['W'] = 'Q';
    q['E'] = 'W';
    q['R'] = 'E';
    q['T'] = 'R';
    q['Y'] = 'T';
    q['U'] = 'Y';
    q['I'] = 'U';
    q['O'] = 'I';
    q['P'] = 'O';
    q['['] = 'P';
    q[']'] = '[';
    q['\\'] = ']';

    q['S'] = 'A';
    q['D'] = 'S';
    q['F'] = 'D';
    q['G'] = 'F';
    q['H'] = 'G';
    q['J'] = 'H';
    q['K'] = 'J';
    q['L'] = 'K';
    q[';'] = 'L';
    q['\''] = ';';

    q['X'] = 'Z';
    q['C'] = 'X';
    q['V'] = 'C';
    q['B'] = 'V';
    q['N'] = 'B';
    q['M'] = 'N';
    q[','] = 'M';
    q['.'] = ',';
    q['/'] = '.';
    
    while (getline(cin, s)) {
        for (auto i : s) {
            if (q.count(i)) {
                cout << q[i];
            } else {
                cout << i;
            }
        }
        cout << endl;
    }

    return 0;
}