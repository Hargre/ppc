#include <bits/stdc++.h>

#define MAX 50005
#define next iahusd

using namespace std;

int next[MAX];
int can_reach[MAX];
bool useless[MAX];
bool visited[MAX];
int n;

int dfs(int v) {
    if (can_reach[v])  {
        return can_reach[v];
    }

    return can_reach[v] = dfs(next[v]) + 1;
}

int main() {
    int t, u, v;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        memset(next, 0, sizeof next);
        scanf("%d", &n);

        for (int j = 0; j < n; j++) {
            scanf("%d %d", &u, &v);

            next[u] = v;
        }

        memset(can_reach, 0, sizeof can_reach);
        memset(visited, false, sizeof visited);
        memset(useless, false, sizeof useless);

        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                int node = j;

                while (!visited[node]) {
                    visited[node] = true;
                    node = next[node];
                }

                if (!useless[node]) {
                    int cycle_st = node;
                    int cycle_sz = 0;

                    do {
                        node = next[node];
                        cycle_sz++;
                    } while (node != cycle_st);

                    cycle_st = node;
                    do {
                        can_reach[node] = cycle_sz;
                        node = next[node];
                    } while (node != cycle_st);
                }

                node = j;
                while (!useless[node]) {
                    useless[node] = true;
                    node = next[node];
                }
            }
        }

        int max_value = 0;
        int result = 0;

        for (int j = 1; j <= n; j++) {
            dfs(j);
            if (can_reach[j] > max_value) {
                max_value = can_reach[j];
                result = j;
            }
        }
        printf("Case %d: %d\n", i + 1, result);
        
    }

    return 0;
}