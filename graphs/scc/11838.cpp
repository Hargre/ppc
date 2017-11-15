#include <bits/stdc++.h>

#define MAX_V 2010
#define UNVISITED -1

using namespace std;

vector<int> G[MAX_V];
vector<int> scc;

int dfs_num[MAX_V];
int dfs_low[MAX_V];
bool visited[MAX_V];

int dfs_count = 0;
int scc_count = 0;
int m, n;

void tarjan_scc(int v) {
    dfs_num[v] = dfs_low[v] = dfs_count++;
    scc.push_back(v);
    visited[v] = true;

    for(auto i: G[v]) {
        if (dfs_num[i] == UNVISITED) tarjan_scc(i);
        if (visited[i])
            dfs_low[v] = min(dfs_low[v], dfs_low[i]);
    }

    if (dfs_low[v] == dfs_num[v]) {
        scc_count++;

        auto i = scc.back();
        do {
            i = scc.back();
            scc.pop_back();
            visited[i] = false;
        } while(i != v);

    }
}

int main() {
    int v, w, p;

    while (cin >> n >> m, n != 0) {
        dfs_count = 0;
        scc_count = 0;

        memset(G, 0, sizeof G);
        memset(dfs_low,  0, sizeof dfs_low);
        memset(dfs_num, UNVISITED, sizeof dfs_num);
        memset(visited, false, sizeof visited);

        for (int i = 0; i < m; i++) {
            cin >> v >> w >> p;
            G[v].push_back(w);

            if (p == 2) {
                G[w].push_back(v);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (dfs_num[i] == UNVISITED) {
                tarjan_scc(i);
            }
        }

        if (scc_count == 1) {
            cout << '1' << endl;
        } else {
            cout << '0' << endl;
        }
    }

    return 0;
}