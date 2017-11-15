#include <bits/stdc++.h>

#define MAX_V 1010

using namespace std;

map<string, vector<string>> G;

vector<string> scc;

pair<int, string> dfs_num[MAX_V];
pair<int, string> dfs_low[MAX_V];
bool visited[MAX_V];

int dfs_count = 0;
int scc_count = 0;

void tarjan_scc(int v, string s) {
    dfs_num[v] = dfs_low[v] = dfs_count++;
    scc.push_back(s);
    visited[v] = true;

    for(auto i: G[s]) {
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
    ios_base::sync_with_stdio(false);

    int p, t;
    string name;
    string sname;

    while (cin >> p >> t, p != 0) {

        for (int i = 0; i < p; i++) {
            getline(cin, name);
            G[name] = vector<string>();
        }

        for (int i = 0; i < t; i++) {
            getline(cin, name);
            getline(cin, sname);

            G[name].push_back(sname);
        }
    }
    
    return 0;
}