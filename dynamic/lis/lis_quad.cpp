#include <bits/stdc++.h>

using namespace std;

int sequence[10];
int memo[10];

int lis(int n) {
    int max_lis = 0;

    for (int i = 0; i < n; i++) {
        memo[i] = 1;

        for (int j = i - 1; j >= 0; j--) {
            if (sequence[j] < sequence[i]) {
                memo[i] = max(memo[i], memo[j] + 1);
            }
        }

        max_lis = max(max_lis, memo[i]);
    }

    return max_lis;
}

int main() {
    sequence[0] = -7;
    sequence[1] = 10;
    sequence[2] = 9;
    sequence[3] = 2;
    sequence[4] = 3;
    sequence[5] = 8;
    sequence[6] = 8;
    sequence[7] = 1;

    cout << lis(8) << endl;

    return 0;
}