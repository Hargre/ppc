#include <bits/stdc++.h>

using namespace std;

string convert(map<int, string> roman, int n) {
    auto iter = roman.upper_bound(n);
    iter--;

    int b = iter->first;

    if (n == b) {
        return roman[n];
    } 
    return roman[b] + convert(roman, n - b);
}

int main() {
    int n;
    map<int, string> roman;

    roman[1] = "I";
    roman[4] = "IV";
    roman[5] = "V";
    roman[9] = "IX";
    roman[10] = "X";
    roman[40] = "XL";
    roman[50] = "L";
    roman[90] = "XC";
    roman[100] = "C";
    roman[400] = "CD";
    roman[500] = "D";
    roman[900] = "CM";
    roman[1000] = "M";

    cin >> n;

    cout << convert(roman, n) << endl;
}