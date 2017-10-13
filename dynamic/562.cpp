/*
 * Dividing coins - Knapsack, weight = value
 */ 

#include <bits/stdc++.h>

using namespace std;

int peso[105];
int valor[105];

int memo[15000][15000];

int c = 0;

int nepseq(int item, int weight) {
    c++;
    if (item < 0 || weight <= 0) {
        return 0;
    }

    if (memo[item][weight] != -1) {
        return memo[item][weight];
    }

    if (peso[item] > weight) {
        return memo[item][weight] = nepseq(item - 1, weight);
    }

    return memo[item][weight] = max(nepseq(item - 1, weight),
                                    nepseq(item - 1, weight - peso[item]) + valor[item]);
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        memset(memo, -1, sizeof memo);
        memset(peso, 0, sizeof peso);
        memset(valor, 0, sizeof valor);
        int m;
        int sum = 0;
        int v;
        cin >> m;

        for (int i = 0; i < m; i++) {
            int temp;
            cin >> temp;
            peso[i] = temp;
            valor[i] = temp;
            sum += temp;
            cout << "sum: " << sum << endl; 
        }

        v = nepseq(m, sum / 2);
        cout << "count: " << c << endl;
        cout << "maior: " << v << endl;
        cout << sum - 2 * v << endl;
    }

    return 0;
}