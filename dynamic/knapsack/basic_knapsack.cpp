#include <bits/stdc++.h>

#define MAX_ITEMS 1000
#define MAX_V 1000
#define MAX_W 1000

using namespace std;

int W[MAX_ITEMS];
int V[MAX_ITEMS];

int memo[MAX_W][MAX_V];

int knapsack(int i, int w) {
    // No items or full bag
    if (i < 0 || w <= 0) {
        return 0;
    }

    // Value already in matrix
    if (memo[i][w] != -1) {
        return memo[i][w];
    }

    // Current item weight greater than bag's capacity. Move to previous item
    if (W[i] > w) {
        return memo[i][w] = knapsack(i - 1, w);
    }

    // Choose between not taking or taking the item
    return memo[i][w] = max(knapsack(i - 1, w),
                            knapsack(i - 1, w - W[i]) + V[i]);
}

int main() {
    memset(memo, -1, sizeof memo);

    W[0] = 26;
    V[0] = 64;

    W[1] = 22;
    V[1] = 85;

    W[2] = 4;
    V[2] = 52;

    W[3] = 18;
    V[3] = 99;

    W[4] = 13;
    V[4] = 39;

    W[5] = 9;
    V[5] = 54;


    cout << knapsack(6, 89) << endl;

    return 0;
}