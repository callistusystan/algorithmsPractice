#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll INF = 1e9+5;
int N, M, T;
vvii adjList(5005);
vector<vector<ll>> memo(5005, vector<ll>(5005,-1));
vvi parent(5005, vi(5005,-1));

ll rec(int cur, int remainNodes, vector<vector<ll>> &memo) {
  if (remainNodes < 1) return INF;
  if (memo[cur][remainNodes] != -1) return memo[cur][remainNodes];
  if (cur == N) {
    if (remainNodes == 1) {
      return 0;
    }
    else
      return INF;
  }

  memo[cur][remainNodes] = INF;

  for (ii next : adjList[cur]) {
    int v = next.first, w = next.second;
    // get time taken from going to this node
    ll t = rec(v, remainNodes-1, memo);
    if (t + w <= T && t+w < memo[cur][remainNodes]) {
      memo[cur][remainNodes] = t+w;
      parent[v][remainNodes-1] = cur;
    }
  }
  return memo[cur][remainNodes];
}

void solve() {
  cin >> N >> M >> T;

  for (int i=0;i<N;i++) {
    int u,v,t_i; cin >> u >> v >> t_i;
    adjList[u].push_back(ii(v, t_i));
  }

  // see if we can start from 1 and reach N
  // using another i-1 nodes (total of i nodes)
  int maxCities;
  for (maxCities=N;maxCities>=1;maxCities--) {
    if (rec(1,maxCities,memo) <= T) {
      break;
    }
  }
  cout << maxCities << endl;

  int cur = N, i = 1;
  vi s;
  while (cur != 1) {
    s.push_back(cur);
    cur = parent[cur][i++];
  }
  s.push_back(1);

  for (int i=(int)s.size()-1;i>=0;i--) {
    cout << s[i];
    if (i) cout << " ";
  }
  cout << endl;

}

int main() {
  solve();
  return 0;
}
