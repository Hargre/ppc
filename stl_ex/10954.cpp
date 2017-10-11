#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;

    while (cin >> n, n != 0) {
        priority_queue<int, vector<int>, greater<int>> q;

        while (n--) {
            int a;
            cin >> a;

            q.push(a);
        }

        int total = 0;
        int cost = 0;

        while (q.size() > 1) {
            total = q.top();
            q.pop();
            total += q.top();
            q.pop();
            cost += total;
            q.push(total);
        }

        cout << cost << endl;
    }

    return 0;
}