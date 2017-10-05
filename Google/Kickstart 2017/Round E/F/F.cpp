#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int INF = 1e9+5;

int N, M, T;
vvii adjList(5005);
vvll memo(5005, vll(5005, -1));
vvii child(5005, vii(5005));

ll rec(int u, int remainingNodes, vvll &memo) {
  if (remainingNodes < 1) return INF;
  if (u == N) {
    // check if we reached here using N nodes
    if (remainingNodes == 1) return 0;
    else return INF;
  }
  if (memo[u][remainingNodes] != -1) return memo[u][remainingNodes];

  // compute
  memo[u][remainingNodes] = INF;
  for (ii next : adjList[u]) {
    int v = next.first, w = next.second;
    ll t = rec(v, remainingNodes-1, memo);
    if (t+w <= T) {
      if (t+w < memo[u][remainingNodes]) {
        memo[u][remainingNodes] = t+w;
        child[u][remainingNodes] = ii(v, remainingNodes-1);
      }
    }
  }
  return memo[u][remainingNodes];
}

int main() {
  cin >> N >> M >> T;
  for (int i=0;i<M;i++) {
    int u,v,w; cin >> u >> v >> w;
    adjList[u].push_back(ii(v, w));
  }

  int ans;
  for (ans=N;ans>=2;ans--) {
    if (rec(1,ans, memo) <= T) break;
  }

  cout << ans << endl;

  ii cur = {1, ans};
  while (cur.second != 1) {
    cout << cur.first << " ";
    cur = child[cur.first][cur.second];
  }
  cout << N << endl;

  return 0;
}
