#include <bits/stdc++.h>

#define MAX 200

using namespace std;

char graph[MAX][MAX];
bool visited[MAX][MAX];
int N;

int di[] = {-1, -1, 0, 0, 1, 1};
int dj[] = {-1, 0, -1, 1, 0, 1};

bool flood_fill(int x, int y, char color) {
    if (x == N - 1 && graph[x][y] == color) {
        return true;
    }

    if (x < 0 || y < 0 || x >= N || y >= N || visited[x][y])  {
        return false;
    }

    if (graph[x][y] != color) {
        return false;
    }

    visited[x][y] = true;

    for (int i = 0; i < 6; i++) {
        if (flood_fill(x + di[i], y + dj[i], color)) {
            return true;
        }
    }

    return false;
}

int main() {
    char c;
    bool flag = false;
    int tc = 1;

    while (cin >> N, N != 0) {
        memset(visited, 0, sizeof visited);
        memset(graph, 0, sizeof graph);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> c;
                graph[i][j] = c;
            }
        }


        cout << tc;

        for (int i = 0; i < N; i++) {
            if (flood_fill(0, i, 'b')) {
                cout << " B" << endl;
                flag = true;
                break;
            }
        }
        
        if (!flag) {
            cout << " W" << endl;
        }
        flag = false;
        tc++;
    }

    return 0;
}