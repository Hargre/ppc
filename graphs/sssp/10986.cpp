#include <bits/stdc++.h>

#define MAX_V 20020
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
    int n, m, s, t;
    int s1, s2, w;
    cin >> tc;

    for (int i = 0; i < tc; i++) {
        memset(G, 0, sizeof G);
        memset(distances, 0, sizeof distances);

        cin >> n >> m >> s >> t;
        while (m--) {
            cin >> s1 >> s2 >> w;
            G[s1].push_back(ii(s2, w));
            G[s2].push_back(ii(s1, w));
        }
        
        int result = dijkstra(s, t, n);

        cout << "Case #" << i + 1 << ": ";

        if (result != INF_NUM) {
            cout << result << endl;
        } else {
            cout << "unreachable" << endl;
        }
    }

    return 0;
}