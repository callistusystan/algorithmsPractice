#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi dfs_num;
vvi adjList;
int VISITED = 1;
int UNVISITED = 2;

bool dfs(int u, int T) {
  dfs_num[u] = VISITED;
  if (u == T) return true;
  for (int v : adjList[u]) {
    if (dfs_num[v] == UNVISITED)
      if (dfs(v, T)) return true;
  }
  return false;
}

void solve() {
  int N, T;
  cin >> N >> T;

  adjList.resize(N+5);
  dfs_num.resize(N+5);
  fill(dfs_num.begin(), dfs_num.end(), UNVISITED);
  for (int i=1;i<=N-1;i++) {
    int a_i; cin >> a_i;
    adjList[i].push_back(i+a_i);
  }

  cout << ((dfs(1,T)) ? "YES" : "NO") << endl;

}

int main() {
  solve();
  return 0;
}
