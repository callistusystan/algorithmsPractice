#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int N, M;
vvi adjList1(500), adjList2(500);

int bfs(vvi &adjList) {
  vi dist(500, -1);
  queue<int> q;

  dist[1] = 0; q.push(1);
  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (u == N) break;
    for (int v : adjList[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return dist[N];
}

void solve() {
  cin >> N >> M;

  vvi hasRailway(500, vi(500, 0));

  for (int i=0;i<M;i++) {
    int u,v; cin >> u >> v;
    adjList1[u].push_back(v);
    adjList1[v].push_back(u);
    hasRailway[u][v] = 1;
    hasRailway[v][u] = 1;
  }

  for (int i=1;i<=N;i++) {
    for (int j=1;j<=N;j++) {
      if (!hasRailway[i][j]) {
        adjList2[i].push_back(j);
        adjList2[j].push_back(i);
      }
    }
  }

  int ans1 = bfs(adjList1), ans2 = bfs(adjList2);
  if (ans1 == -1 || ans2 == -1) {
    cout << -1 << endl;
    return;
  } else {
    cout << max(ans1, ans2) << endl;
  }
}

int main() {
  solve();
  return 0;
}
