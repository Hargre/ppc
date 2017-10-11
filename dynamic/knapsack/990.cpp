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