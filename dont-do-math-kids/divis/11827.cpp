#include <bits/stdc++.h>

using namespace std;

long long seq[110];

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        string line;
        getline(cin, line);
        while (getline(cin, line)) {
            memset(seq, 0, sizeof seq);
            int i = 0;
            istringstream iss(line);
            while (iss >> seq[i++]);
            long long result = 0;
            for (int j = 0; j < i - 1; j++) {
                for (int k = j + 1; k < i - 1; k++) {
                    result = max(result, gcd(seq[j], seq[k]));
                }
            }
            cout << result << endl;
        }
    }

    return 0;
}