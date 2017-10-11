#include <bits/stdc++.h>

#define MAX 33000

using namespace std;

// Sequencia original
int sequence[MAX];

// Registra a LIS (que sempre está ordenada)
int lis_seq[MAX];

int lis(int n) {
    int max_lis = 0;

    for (int i = 0; i < n; i++) {
        lis_seq[i] = 1;

        for (int j = i - 1; j >= 0; j--) {
            if (sequence[j] >= sequence[i]) {
                lis_seq[i] = max(lis_seq[i], lis_seq[j] + 1);
            }
        }

        max_lis = max(max_lis, lis_seq[i]);
    }

    return max_lis;
}

int main() {
    int i;
    int tc = 1;
    int counter = 0;

    while (1) {
        cin >> i;

        if (i == -1) {
            cout << "Test #" << tc << ":" << endl;
            cout << "  maximum possible interceptions: " << lis(counter) << endl;
            memset(sequence, 0, sizeof sequence);
            memset(lis_seq, 0, sizeof lis_seq);
            counter = 0;
            tc++;

            cin >> i;
            if (i == -1) {
                return 0;
            }
            cout << endl;
        }
        sequence[counter] = i;
        counter++;
    }

    return 0;
}