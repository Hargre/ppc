#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
int N, M;
int max_d;
ii max_p;
char maze[505][505];
int dist[505][505];

bool is_valid(ii p) {
    return !(p.first < 0 || 
        p.second < 0 || 
        p.first >= N || 
        p.second >= M || 
        maze[p.first][p.second] == '#' || 
        dist[p.first][p.second] != -1);
}

void bfs(ii point) {
    memset(dist, -1, sizeof dist);
    max_d = 0;
    max_p = ii(-1, -1);


    auto init_v = point;

    queue<ii> to_visit;
    to_visit.push(init_v);
    dist[point.first][point.second] = 0;

    while (!to_visit.empty()) {
        auto v = to_visit.front();
        to_visit.pop();

        for (int i = 0; i < 4; i++) {
            auto p_to_v = ii(v.first + dx[i], v.second + dy[i]);
            if (is_valid(p_to_v)) {
                dist[p_to_v.first][p_to_v.second] = dist[v.first][v.second] + 1;
                if (dist[p_to_v.first][p_to_v.second] > max_d) {
                    max_d = dist[p_to_v.first][p_to_v.second];
                    max_p = p_to_v;
                }
                to_visit.push(ii(p_to_v));
            }
        }
    }
}

int main() {
    char aux;
    ii start_point;
    while (cin >> N >> M, N + M) {
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < M; k++) {
                cin >> aux;
                maze[i][k] = aux;
                if (aux == '.') start_point = ii(i, k);
            }
        }
        bfs(start_point);
        bfs(max_p);
        cout << max_d << endl;
    }

    return 0;
}