#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    double fib;

    cin >> n;

    fib = (pow(((1 + sqrt(5)) / 2), n) - pow(((1 - sqrt(5)) / 2), n)) / (sqrt(5));

    cout << fixed << setprecision(1) << fib << endl;
    return 0;
}