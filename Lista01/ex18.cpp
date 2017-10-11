#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> currency = {1, 5, 10, 25, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    map<int, int> result;
    double n;
    int n_cent;
    
    for (auto i : currency) {
        result.emplace(i, 0);
    }
    cin >> n;
    n_cent = n * 100;

    size_t i = currency.size() - 1;
    while (n_cent > 0) {
        if ((n_cent - currency[i]) >= 0) {
            n_cent = n_cent - currency[i];
            result[currency[i]] += 1;
        } else {
            i--;
        }
    }
    
    auto aux = result.rbegin();
    
    cout << "NOTAS:" << endl;
    for (auto value = result.rbegin(); value->first != 100; value++) {
        double num = value->first / 100.0;
        cout << setprecision(2) << fixed;
        cout << value->second << " nota(s) de R$ "  << num << endl;
        aux++;
    }

    cout << "MOEDAS:" << endl;
    while (aux != result.rend()) {
        double num = aux->first / 100.0;
        cout << setprecision(2) << fixed;
        cout << aux->second << " moeda(s) de R$ " << num << endl;
        aux++;
    } 

    return 0;
}