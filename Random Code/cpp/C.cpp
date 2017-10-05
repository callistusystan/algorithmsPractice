#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int UNVISITED = 0, VISITED = 1;

vi boss(2005,-1), visited(2005, UNVISITED);
vvi adjList(2005);

int dfs(int u) {
  visited[u] = VISITED;
  int d = 0;
  for (int v : adjList[u]) {
    if (visited[v] == UNVISITED) {
      d = max(d, dfs(v));
    }
  }
  return d + 1;
}

int main() {
  int N; cin >> N;
  for (int i=1;i<=N;i++) {
    cin >> boss[i];
    if (boss[i] != -1) adjList[boss[i]].push_back(i);
  }

  int ans = 1;
  for (int i=1;i<=N;i++) {
    if (boss[i] == -1 && visited[i] == UNVISITED) {
      ans = max(ans,dfs(i));
    }
  }

  cout << ans << endl;
  return 0;
}
