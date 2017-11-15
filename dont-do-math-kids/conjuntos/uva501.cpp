#include <bits/stdc++.h>

using namespace std;

int nums[30030];

int main() {
    ios::sync_with_stdio(false);

    int k;
    int m, n;

    cin >> k;

    while (k--) {
        memset(nums, 0, sizeof nums);
        cin >> m >> n;
        for (int i = 0; i < m; i++) {
            cin >> nums[i];
        }

        int count = 0;
        int cur = 0;
        vector<int> b;

        while (n--) {
            unsigned int y;
            cin >> y;

            while (b.size() < y) {
                auto it = lower_bound(b.begin(), b.end(), nums[cur]);
                b.insert(it, nums[cur++]);
            }

            cout << b[count++] << endl;
        }
        if (k) {
            cout << endl;
        }
    }

    return 0;
}