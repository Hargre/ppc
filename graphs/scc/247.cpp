#include <bits/stdc++.h>

#define UNVISITED -1
#define MAX_V 25

using namespace std;

unordered_map<string, vector<string>> G;

unordered_map<string, int> dfs_num;
unordered_map<string, int> dfs_low;
unordered_map<string, bool> visited;

vector<string> scc;

int dfs_count = 0;
int scc_count = 0;

void tarjan_scc(string v) {
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

            cout << i << " ";
        } while(i != v);

        printf("\n");
    }
}


int main() {

    int n, m;
    string caller;
    string called;

    while (cin >> n >> m, n) {
        dfs_count = scc_count = 0;
        G.clear();
        dfs_num.clear();
        dfs_low.clear();
        visited.clear();

        for (int i = 0; i < m; i++) {
            cin >> caller >> called;
            G[caller].push_back(called);
        }

        for (auto i : G) {
            if (dfs_num.find(i.first) == dfs_num.end()) {
                tarjan_scc(i.first);
            }
        }
    }

    return 0;
}