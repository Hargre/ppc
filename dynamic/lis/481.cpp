/*
 * What goes up - Only one that works with nlogn solution somehow. 
 * Uses reconstruction.
 */

#include <bits/stdc++.h>

#define MAX 1000000

using namespace std;

int sequence[MAX];
int lis_seq[MAX];

int lis_seq_i[MAX];
int lis_parents[MAX];
int lis_max_i = -1;

int lis(int n) {
    // Tamanho do lis_seq, inicialmente está vazio
    int lis_size = 0;
    
    for (int i = 0; i < n; ++i) {

        // Encontra a menor posição que é possível inserir o i-ésimo termo na LIS
        int p = lower_bound(lis_seq, lis_seq + lis_size, sequence[i]) - lis_seq; 

        lis_seq[p] = sequence[i];
        lis_seq_i[p] = i;

        lis_parents[i] = (p ? lis_seq_i[p - 1] : -1);

        if (p + 1 > lis_size) {
            lis_size = p + 1;
            lis_max_i = i;
        }
    }

    return lis_size;
}

void reconstruct() {
    stack<int> s;
    for (int i = lis_max_i; i != -1; i = lis_parents[i]) {
        s.push(sequence[i]);
    }

    cout << s.top() << endl;
    while (s.pop(), !s.empty()) {
        cout << s.top() << endl;
    }
}

int main() {
    int v;
    int i = 0;

    while (cin >> v) {
        sequence[i] = v;
        i++;
    }

    cout << lis(i) << endl;
    cout << '-' << endl;
    reconstruct();
}