#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int U = 0, V = 1, W = 2;

int N, M;
vector<vector<ii>> adjList(3e5+5);
vector<vi> edges;
vi memo(3e5+5,-1);

int rec(int prevEdge) {
  if (memo[prevEdge] != -1) return memo[prevEdge];
  int u,w;
  u = edges[prevEdge][V];
  w = edges[prevEdge][W];
  // cerr << "prevEdge was " << prevEdge << endl;
  // see if theres an edge i can go from u
  int ans = 0;
  auto it = lower_bound(adjList[u].begin(), adjList[u].end(), make_pair(w+1,-1));
  if (it != adjList[u].end()) {
    int i = it - adjList[u].begin();
    // cerr << "there are " << ((int)adjList[u].size()-i) << " candidate next edges starting at "<< i << endl;
    for (int j=i;j<(int)adjList[u].size();j++) {
      ans = max(ans, 1+rec(adjList[u][j].second));
    }
  }

  // cerr << prevEdge << " is " << ans << endl;
  return memo[prevEdge] = ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> M;
  for (int i=0;i<M;i++) {
    int u,v,w;
    cin >> u >> v >> w;
    edges.push_back({u,v,w});
    adjList[u].push_back({w,i});
  }

  for (int i=0;i<N;i++) {
    sort(adjList[i].begin(), adjList[i].end());
  }

  int ans = 1;

  for (int i=0;i<M;i++) {
    ans = max(ans, 1 + rec(i));
  }

  cout << ans << endl;

  return 0;
}
