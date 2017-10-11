#include <bits/stdc++.h>

using namespace std;

vector< pair<int, int> > block;
int memo[11000];

int lis(int n) {
    int max_lis = 0;
    
        for (int i = 0; i < n; i++) {
            memo[i] = 1;
    
            for (int j = i - 1; j >= 0; j--) {
                if (block[j].second <= block[i].second) {
                    memo[i] = max(memo[i], memo[j] + 1);
                }
            }
    
            max_lis = max(max_lis, memo[i]);
        }
    
        return max_lis;
}

int main() {
    int b;
    cin >> b;
    
    while (b != 0) {
        int l, m;
        pair<int, int> bl;

        memset(memo, 0, sizeof memo);
        block.clear();

        for (int i = 0; i < b; i++) {
            cin >> l >> m;

            bl.first = l;
            bl.second = m;

            block.push_back(bl);
        }

        sort(block.begin(), block.end());

        cout << lis(b) << endl;
        cin >> b;
    }

    cout << '*' << endl;

    return 0;
}