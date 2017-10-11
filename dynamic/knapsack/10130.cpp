#include <bits/stdc++.h>

using namespace std;

int N;
int price[1100];
int weight[1100];
int family[110];
int memo[1100][40];

int dp(int i, int w) {
    // No items or full bag
    if (i < 0 || w <= 0) {
        return 0;
    }

    // Value already in matrix
    if (memo[i][w] != -1) {
        return memo[i][w];
    }

    // Current item weight greater than bag's capacity. Move to previous item
    if (weight[i] > w) {
        return memo[i][w] = dp(i - 1, w);
    }

    // Choose between not taking or taking the item
    return memo[i][w] = max(dp(i - 1, w),
                            dp(i - 1, w - weight[i]) + price[i]);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        memset(price, 0, sizeof price);
        memset(weight, 0, sizeof weight);
        memset(family, 0, sizeof family);

        int r = 0;
        cin >> N;
        int p, w, g;

        for (int i = 0; i < N; i++) {
            cin >> p >> w;
            price[i] = p;
            weight[i] = w;
        }

        cin >> g;

        for (int i = 0; i < g; i++) {
            int mw;
            cin >> mw;
            family[i] = mw;
        }

        for (int i = 0; i < g; i++) {
            memset(memo, -1, sizeof memo);
            r += dp(N, family[i]);
        }

        cout << r << endl;
    }

    return 0;
}