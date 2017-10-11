#include <bits/stdc++.h>

#define MAX_PRICE 10000
#define MAX_FAVOUR 500
#define MAX_ITEMS 100

using namespace std;

int price[MAX_ITEMS];
int favour[MAX_ITEMS];

int memo[MAX_PRICE][MAX_PRICE];
int m;
int n;

int knapsack(int i, int budget) {
    
    if (budget > m && m <= 1800) {
        return -1000;
    }

    if (budget > m + 200) {
        return -1000;
    }

    if (i == n) {
        if (budget <= 2000 && budget > m) {
            return -1000;
        }
        return 0;
    }

    if (memo[i][budget] != -1) {
        return memo[i][budget];
    }

    return memo[i][budget] = max(knapsack(i + 1, budget),
                                 knapsack(i + 1, budget + price[i]) + favour[i]);
}

int main() {
    while (cin >> m >> n) {
        memset(memo, -1, sizeof memo);

        int p, f;
        for (int i = 0; i < n; i++) {
            cin >> p >> f;
            price[i] = p;
            favour[i] = f;
        }
        cout << knapsack(0, 0) << endl;
    }

    return 0;
}