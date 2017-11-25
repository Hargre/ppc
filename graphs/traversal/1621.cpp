#include <bits/stdc++.h>

#define MAX_V 100000

using namespace std;

vector<int> G[MAX_V];
vector<char> aux;

int main() {
    int n, m;
    while (cin >> n >> m, n) {
        for (int i = 0; i < n * m; i++) {
            char temp;
            cin >> temp;
            aux.push_back(temp);
        }
    }


    return 0;
}