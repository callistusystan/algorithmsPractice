#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;

int N, M; ll T;
vector<vector<ii>> adjList(5005);
vector<vi> memo(5005, vi(5005,-1));

int rec(int cur, int remain) {
  if (remain < 0) return -1;
  if (cur == N && remain == 0) return 0;
  if (cur == N && remain != 0) return -1;
  if (memo[cur][remain] != -1) return memo[cur][remain];

  int ans = -1;
  for (ii e : adjList[cur]) {
    int v,w; v = e.first; w = e.second;
    int res = rec(v, remain-1);
    if (res != -1) {
      ll totalT = (ll)w + res;
      if (totalT <= T) {
        if (ans == -1) ans = w + res;
        ans = min(ans, w + res);
      }
    }
  }

  return memo[cur][remain] = ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> M >> T;

  for (int i=0;i<M;i++) {
    int u,v,t; cin >> u >> v >> t;
    adjList[u].push_back({v,t});
  }

  int i;
  for (i=N;i>=2;i--) {
    if (rec(1,i-1) != -1 && rec(1,i-1) <= T) {
      break;
    }
  }

  cout << i << endl;

  return 0;
}
