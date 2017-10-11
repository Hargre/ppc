#include <bits/stdc++.h>

#define MAX 1000010

using namespace std;

int coins[MAX];
int memo[MAX];

int coin_change(int V, int N) {
    if (V == 0) {
        return 0;
    }

    if (V < 0) {
        return 500000;
    }

    if (memo[V] != -1) {
        return memo[V];
    }

    int n_coins = 500000;

    for (int i = 0; i < N; i++) {
        n_coins = min(n_coins, coin_change(V - coins[i], N));
    }

    return memo[V] = n_coins + 1;
}

int main() {
    memset(memo, -1, sizeof memo);   

    coins[0] = 2;
    coins[1] = 3;

    cout << coin_change(6, 2) << endl; 
    return 0;
}
