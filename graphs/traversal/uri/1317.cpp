/*
 * URI 1317
 * I hate spam, but some people love it - I hate graphs, and I guess everyone else does too.
 * Use BFS, count amount of neighbors for each visited node, use this amount to calculate
 * the spam result for each person.
 */ 

#include <bits/stdc++.h>

#define MAX_P 20
#define MAX_SP 100

using namespace std;

vector<int> graph[MAX_P];
string spam[MAX_SP][3];
int spammer[MAX_SP];
pair<int, int> thr[MAX_SP];
string people[MAX_P];
bool visited[MAX_P];
string results[MAX_P][MAX_SP];

void bfs(int s, int c) {
    memset(visited, 0, sizeof visited);

    int initial_vertice = s;

    queue<int> to_visit;
    to_visit.push(initial_vertice);
    visited[initial_vertice] = true;

    while (!to_visit.empty()) {
        auto v = to_visit.front();
        to_visit.pop();

        for (auto i : graph[v]) {
            if (!visited[i]) {
                visited[i] = true;
                to_visit.push(i);
            }
        }

        int list_s = graph[v].size();
        if (list_s < thr[c].first) {
            results[v][c] = spam[c][0];
        } else if (list_s >= thr[c].first && list_s < thr[c].second) {
            results[v][c] = spam[c][1];
        } else {
            results[v][c] = spam[c][2];
        }
    }
}

int main() {
    int n;
    
    while (cin >> n, n != 0) {
        for (int i = 1; i <= n; i++) {
            graph[i].clear();
            int p;
            while (cin >> p, p != 0) {
                graph[i].push_back(p);
            }
        }

        int sp, t1, t2;
        int c = 0;
        string a1, a2, a3;
        while (cin >> sp , sp != 0) {
            cin >> t1 >> t2 >> a1 >> a2 >> a3;
            pair<int, int> t (t1, t2);
            spammer[c] = sp;
            thr[c] = t;
            spam[c][0] = a1;
            spam[c][1] = a2;
            spam[c][2] = a3;
            c++;
        }
        
        for (int i = 1; i <= n; i++) {
            string per;
            cin >> per;
            people[i] = per;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < c; j++) {
                results[i][j] = spam[j][0];
            }
        }

        for (int i = 0; i < c; i++) {
            bfs(spammer[i], i);
        }

        for (int i = 1; i <= n; i++) {
            cout << people[i] << ": ";
            for (int j = 0; j < c; j++) {
                cout << results[i][j] << ' ';
            }
            cout << endl;
        }
    }
}