/*
 * UVa 990 Diving for Gold - Knapsack, 3*w constraint, reconstruct solution
 */

#include <bits/stdc++.h>

using namespace std;

int t, w;

int depth[300];
int value[100];

int memo[2000][2000];
int taken[2000][2000];

int dp(int i, int time) {
    if (i < 0 || time <= 0) {
        return 0;
    }

    if (memo[i][time] != -1) {
        return memo[i][time];
    }

    if ((3 * w * depth[i]) > time) {
        return memo[i][time] = dp(i - 1, time);
    }

    auto take = dp(i - 1, time - (3 * w * depth[i])) + value[i];
    auto not_take = dp(i - 1, time);

    if (take > not_take) {
        taken[i][time] = true;
        return memo[i][time] = take;
    }
    return memo[i][time] = not_take; 
}

void reconstruct(int nt, int time) {
    stack<int> items;

    do {
        if (taken[nt][time]) {
            time = time - (3 * w * depth[nt]);
            items.push(nt);
        }
    } while (nt--);

    cout << items.size() << endl;
    while (!items.empty()) {
        cout << depth[items.top()] << ' ' << value[items.top()] << endl;
        items.pop();
    }
}

int main() {
    int f = 0;
    while (cin >> t >> w) {
        memset(memo, -1, sizeof memo);
        memset(depth, 0, sizeof depth);
        memset(value, 0, sizeof value);
        memset(taken, false, sizeof taken);        

        int nt;
        cin >> nt;

        int d, v;
        for (int i = 0; i < nt; i++) {
            cin >> d >> v;
            depth[i] = d;
            value[i] = v;
        }

        if (f) {
            cout << endl;
        }
        f++;

        cout << dp(nt, t) << endl;
        reconstruct(nt, t);
    }

    return 0;
}

/*
 * UVa 10130 Supersale - Knapsack, calculate for each member in family
 */ 

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

/*
 * UVa 10819 13 Dots - Knapsack, built with i = 0 and w = 0, taking in account
 * weird weight modifications
 */

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
