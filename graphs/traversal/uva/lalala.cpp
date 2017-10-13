#include <bits/stdc++.h>
#define MAX_V 50050
#define next iuahdfuioahds

using namespace std;

bool visited[MAX_V], useless[MAX_V];
int next[MAX_V], can_reach[MAX_V];
int counterr = 0;

int dfs(int v) {
    counterr++;
    if(can_reach[v]) return can_reach[v];
    return can_reach[v] = dfs(next[v]) + 1;
}

int main(){
  int n, ng, ini_v, las_v, counter=1;
  scanf("%d", &n);
  while(n--){
    scanf("%d", &ng);
    for(int i=1; i<=ng; i++){
      scanf("%d %d", &ini_v, &las_v);
      next[ini_v] = las_v;
    }
    for(int i=1; i<=ng; i++){
      if(!visited[i]){
        int node = i;
        while(!visited[i]){
          visited[node] = true;
          node = next[node];
        }
        if(!useless[node]){
          int cycle_start = node;
          int cycle_size = 0;
          do{
            cycle_size++;
            node = next[node];
          }while(node != cycle_start);

          cycle_start = node;
          while(node != cycle_start){
            can_reach[node] = cycle_size;
            node = next[node];
          }
        }
        node = i;
        while(!useless[node]){
          useless[node] = true;
          node = next[node];
        }
      }
    }

    int popular_node = -1, max_reach = 0;
    for(int i=1; i<=ng; i++){
      printf("%d ", can_reach[i]);
    }
    printf("\n");
    for(int i=1; i<=ng; i++){
      max_reach = max(dfs(i), max_reach);
      if(max_reach == can_reach[i]) popular_node = i;
    }
    memset(can_reach, 0, sizeof can_reach);
    memset(visited, false, sizeof visited);
    memset(useless, false, sizeof useless);
    printf("Case %d: %d\n", counter, popular_node);
  }
  return 0;
}