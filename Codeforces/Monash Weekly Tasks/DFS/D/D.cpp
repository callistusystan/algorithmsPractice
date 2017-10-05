#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int PARI = 1, ARYA = 2, UNVISITED = 0;

int N, M;
vi visited, pariVertices, aryaVertices;
vvi adjList;

bool isBiPartite(int s) {
  queue<int> q; q.push(s);
  vi colors(N+5, UNVISITED);
  colors[s] = PARI;
  pariVertices.push_back(s);

  while (!q.empty()) {
    int u = q.front(); q.pop();
    visited[u] = 1;
    for (int v: adjList[u]) {
      if (colors[v] == UNVISITED) {
        if (colors[u] == PARI) {
          colors[v] = ARYA;
          aryaVertices.push_back(v);
        } else {
          colors[v] = PARI;
          pariVertices.push_back(v);
        }
        q.push(v);
      } else if (colors[v] == colors[u]) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  cin >> N >> M;

  visited.resize(N+5, 0);
  adjList.resize(N+5);

  for (int i=0;i<M;i++) {
    int u,v;
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  for (int i=1;i<=N;i++) {
    if (!visited[i] && adjList[i].size() > 0)
      if (!isBiPartite(i)) {
        cout << -1 << endl;
        return;
      }
  }

  sort(pariVertices.begin(), pariVertices.end());
  sort(aryaVertices.begin(), aryaVertices.end());

  cout << pariVertices.size() << endl;
  for (int i=0;i<(int)pariVertices.size();i++) {
      if (i) cout << " ";
      cout << pariVertices[i];
  } cout << endl;
  cout << aryaVertices.size() << endl;
  for (int i=0;i<(int)aryaVertices.size();i++) {
      if (i) cout << " ";
      cout << aryaVertices[i];
  } cout << endl;
}

int main() {
  solve();
  return 0;
}
