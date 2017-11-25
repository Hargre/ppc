#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int a, b, c, d;
    set<int> si;
    
    cin >> a >> b >> c >> d;
    si.insert(a);
    si.insert(b);
    si.insert(c);
    si.insert(d);

    cout << 4 - (int)si.size() << endl;

    return 0;
}