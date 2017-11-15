#include <bits/stdc++.h>

#define MAX_V 110
#define INF_NUM 100000000

using namespace std;
using ii = pair<int, int>;

vector<ii> G[MAX_V];
int distances[MAX_V];

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
    int n, e, t, m;
    int a, b, time;
    int result;

    cin >> tc;

    while (tc--) {
        result = 0;
        memset(G, 0, sizeof G);
        memset(distances, 0, sizeof distances);

        cin >> n;
        cin >> e;
        cin >> t;
        cin >> m;

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> time;
            G[a].push_back(ii(b, time));
        }

        for (int i = 1; i <= n; i++) {
            if (dijkstra(i, e, n) <= t) {
                result++;
            }
        }

        cout << result << endl;

        if (tc) {
            cout << endl;
        }
    }

    return 0;
}