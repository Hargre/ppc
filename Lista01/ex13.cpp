#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int num;
    string num_s;

    cin >> num;

    num_s = to_string(num);
    reverse(num_s.begin(), num_s.end());

    cout << num_s << endl;

    return 0;
}