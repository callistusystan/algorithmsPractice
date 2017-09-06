#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int VISITED = 1;
int UNVISITED = 0;

int N;
vi p;
vvi adjList;

int bfs(int s) {
  queue<int> q;
  vi dist(N+5,-1);
  dist[s] = 0;

  q.push(s);
  int maxD = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    maxD = max(maxD, dist[u]);
    for (int v: adjList[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
  return maxD;
}

void solve() {
  cin >> N;

  adjList.resize(N+5);
  p.resize(N+5);

  for (int i=1;i<=N;i++) {
    cin >> p[i];
    if (p[i] != -1)
      adjList[p[i]].push_back(i);
  }

  int maxDistance = -1;
  for (int i=1;i<=N;i++) {
    if (p[i] == -1) {
      maxDistance = max(maxDistance, bfs(i));
    }
  }

  cout << maxDistance + 1 << endl;
}

int main() {
  solve();
  return 0;
}
