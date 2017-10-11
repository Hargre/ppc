#include <bits/stdc++.h>

using namespace std;

int main() {
    int s, t, f;
    int ans;

    cin >> s >> t >> f;

    if (s > 0) {
        ans = s + t + f;
    } else {
        ans = 24 + t + f;
    }

    if (ans >= 24) {
        ans -= 24;
    }
    
    cout << ans << endl;
    
    return 0;
}