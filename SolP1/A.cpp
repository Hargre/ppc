#include <bits/stdc++.h>

using namespace std;

class Building {
    string type;
    char busy;
    int munition;
    int gold;

    Building() {}
};

bool operator < (Building a, Building b) {
    if (a.type != b.type) {
        return a.type > b.type;
    } 
    if (a.busy != b.busy) {
        return a.busy < b.busy;
    }
    if (a.busy == 'A') {
        return a.munition < b.munition;
    }
    return a.gold > b.gold;
}

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int C;
        cin >> C;
        vector<Building> bs;

        for (int i = 0; i < C; i++) {
            Building b;
            char type[20];
            scanf("%s %c %d %d", type, &b.busy, &b.munition, &b.gold);
            b.type = string(type);
            bs.push_back(b);
        }
        sort(bs.begin(), bs.end());

        printf("Caso %d:\n", tc);
        for (auto b : bs) {
            printf("%s %c %d %d \n", b.type.c_str(), b.busy, b.munition, b.gold);
        }
        if (tc < T) {
            printf("\n");
        }
    }

    return 0;
}