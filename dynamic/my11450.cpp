/*
 * Wedding Shop - DP não clássica
 */

#include <bits/stdc++.h>

using namespace std;

int memo[200][200];
vector<int> items[20];
int M, C;

int dp(int i, int money) {
    if (money < 0) {
        return numeric_limits<int>::lowest();
    }

    if (memo[i][money] != -1) {
        return memo[i][money];
    }

    if (i == C) {
        return M - money;
    }

    int max_cost = numeric_limits<int>::lowest();

    for (auto item : items[i]) {
        max_cost = max(max_cost, dp(i + 1, money - item));
    }

    return memo[i][money] = max_cost;
}

int main() {
    int tc;

    cin >> tc;

    while (tc--) {
        memset(memo, -1, sizeof(memo));
        int k, p;

        cin >> M >> C;
        for (int i = 0; i < C; i++) {
            cin >> k;
            items[i].clear();

            for (int j = 0; j < k; j++) {
                cin >> p;
                items[i].push_back(p);
            }
        }

        int cost = dp(0, M);

        if (cost > 0) {
            cout << cost << endl;
        } else {
            cout << "no solution" << endl;
        }
    }

    return 0;
}