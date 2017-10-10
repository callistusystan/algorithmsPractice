#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

int UNVISITED = -1, BLACK = 0, WHITE = 1;

vi dfs_num(1e5+5, UNVISITED);
vvi adjList(1e5+5);

void dfs(int u, int color) {
  dfs_num[u] = color;

  for (int v : adjList[u]) {
    if (dfs_num[v] == UNVISITED) {
      dfs(v, 1-color);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N; cin >> N;
  set<pair<int, int>> edges;
  for (int i=0;i<N-1;i++) {
    int u,v; cin >> u >> v;
    u--; v--;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
    edges.insert({u,v});
    edges.insert({v,u});
  }
  dfs(0, BLACK);
  vi left,right;

  for (int i=0;i<N;i++) {
    if (dfs_num[i] == BLACK) left.push_back(i);
    else right.push_back(i);
  }

  ll a = left.size(), b = right.size();

  cout << a*b-(N-1) << endl;
  return 0;
}
