#include <bits/stdc++.h>

using namespace std;

map<char, vector<char>> G;
map<char, int> dfs_num;
map<char, int> dfs_low;
map<char, bool> visited;

vector<char> scc;

int dfs_count = 0;
int scc_count = 0;

void tarjan_scc(int v) {
    dfs_num[v] = dfs_low[v] = dfs_count++;
    scc.push_back(v);
    visited[v] = true;

    for(auto i: G[v]) {
        if (dfs_num.find(i) == dfs_num.end()) tarjan_scc(i);
        if (visited[i])
            dfs_low[v] = min(dfs_low[v], dfs_low[i]);
    }

    if (dfs_low[v] == dfs_num[v]) {
        printf("SCC %d:", ++scc_count);

        auto i = scc.back();
        do {
            i = scc.back();
            scc.pop_back();
            visited[i] = false;

            cout << " " << i;
        } while(i != v);

        printf("\n");
    }
}

int main() {
    int n;
    char v;

    while (cin >> n, n) {
        G.clear();
        dfs_num.clear();
        dfs_low.clear();
        visited.clear();

        char aux[5];

        for (int i = 0; i < 5; i++) {
            cin >> aux[i];
        }

        cin >> v;

        for (int i = 0; i < 5; i++) {
            if (v != aux[i]) G[v].push_back(aux[i]);
        }

        for (auto i : G) {
            if (dfs_num.find(i.first) == dfs_num.end()) tarjan_scc(i.first);
        }
    }

    return 0;
}