#include <bits/stdc++.h>

#define MAX_V 1000
#define INF_NUM 100000000

using namespace std;
using ii = pair<int, int>;

int mat[MAX_V][MAX_V];

vector<ii> G[MAX_V * MAX_V];
int distances[MAX_V * MAX_V];

int dijkstra(int source, int destiny, int N) {
    fill(distances, distances + N + 1, INF_NUM);

    priority_queue<ii, vector<ii>, greater<ii>> to_visit;

    distances[source] = 0;
    to_visit.push(ii(distances[source], source));

    while (!to_visit.empty()) {
        auto d = to_visit.top().first;
        auto v = to_visit.top().second;
        to_visit.pop();

        if (d > distances[v]) continue;

        for (auto i : G[v]) {
            auto i_v = i.first;
            auto i_d = i.second;

            if (distances[v] + i_d < distances[i_v]) {
                distances[i_v] = distances[v] + i_d;
                to_visit.push(ii(distances[i_v], i_v));
            }
        }
    }

    return distances[destiny];
}

int main() {
    int tc;
    int n, m;
    cin >> tc;

    while (tc--) {
        memset(G, 0, sizeof G);

        cin >> n;
        cin >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }

        int v = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i != 0 && i != n - 1 && j != 0 && j != m - 1) {
                    G[v].push_back(ii(v + 1, mat[i][j]));
                    G[v].push_back(ii(v - 1, mat[i][j]));
                    G[v].push_back(ii(v + m, mat[i][j]));
                    G[v].push_back(ii(v - m, mat[i][j]));
                } else if (i == 0 && j == 0) {
                    G[v].push_back(ii(v + 1, mat[i][j]));
                    G[v].push_back(ii(v + m, mat[i][j]));
                } else if (i == 0 && j == m - 1) {
                    G[v].push_back(ii(v - 1, mat[i][j]));
                    G[v].push_back(ii(v + m, mat[i][j]));
                } else if (i == n - 1 && j == 0) {
                    G[v].push_back(ii(v + 1, mat[i][j]));
                    G[v].push_back(ii(v - m, mat[i][j]));
                } else if (i == n - 1 && j == m - 1) {
                    G[v].push_back(ii(v - 1, mat[i][j]));
                    G[v].push_back(ii(v - m, mat[i][j]));
                } else if (i == 0) {
                    G[v].push_back(ii(v + 1, mat[i][j]));
                    G[v].push_back(ii(v - 1, mat[i][j]));
                    G[v].push_back(ii(v + m, mat[i][j]));
                } else if (i == n - 1) {
                    G[v].push_back(ii(v + 1, mat[i][j]));
                    G[v].push_back(ii(v - 1, mat[i][j]));
                    G[v].push_back(ii(v - m, mat[i][j]));
                } else if (j == 0) {
                    G[v].push_back(ii(v + 1, mat[i][j]));
                    G[v].push_back(ii(v + m, mat[i][j]));
                    G[v].push_back(ii(v - m, mat[i][j]));
                } else if (j == m - 1) {
                    G[v].push_back(ii(v - 1, mat[i][j]));
                    G[v].push_back(ii(v + m, mat[i][j]));
                    G[v].push_back(ii(v - m, mat[i][j]));
                }
                v++;
            }
        }

        cout << dijkstra(m - 1, v - m, v) << endl;
    }

    return 0;
}