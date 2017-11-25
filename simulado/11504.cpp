#include <bits/stdc++.h>

#define UNVISITED -1
#define MAX_V 100100

using namespace std;

vector<int> G[MAX_V];

int dfs_num[MAX_V];
int dfs_low[MAX_V];
bool visited[MAX_V];

vector<int> scc;

int dfs_count = 0;
int scc_count = 0;

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
        printf("SCC %d:", ++scc_count);

        auto i = scc.back();
        do {
            i = scc.back();
            scc.pop_back();
            visited[i] = false;

            printf(" %d", i);
        } while(i != v);

        printf("\n");
    }
}

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        memset(dfs_low,  0, sizeof dfs_low);
        memset(dfs_num, UNVISITED, sizeof dfs_num);
        memset(visited, false, sizeof visited);

        dfs_count = scc_count = 0;

        int n, m;
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
        }

        for(int i = 1; i <= n; i++)
        if(dfs_num[i] == UNVISITED)
            tarjan_scc(i);
    }

    return 0;
}