#include <bits/stdc++.h>

using namespace std;

#define MAX 100

// Sequencia original
int sequence[MAX];

// Registra a LIS (que sempre está ordenada)
int lis_seq[MAX];

int lis(int N) {

    // Tamanho do lis_seq, inicialmente está vazio
    int lis_size = 0;

    for (int i = 0; i < N; ++i) {

        // Encontra a menor posição que é possível inserir o i-ésimo termo na LIS
        int p = lower_bound(lis_seq, lis_seq + lis_size, sequence[i]) - lis_seq; 
        cout << "P at iteration " << i << " : " << p << endl;

        lis_seq[p] = sequence[i];
        lis_size = max(lis_size, p + 1);

        cout << "Lis_seq at iteration " << i << endl;
        for (int j = 0; j < lis_size; j++) {
            cout << lis_seq[j] << endl;
        }
    }

    return lis_size;
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
