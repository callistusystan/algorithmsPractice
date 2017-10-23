#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int U = 0, V = 1, W = 2;

int N, M;
vector<vi> edges;
vi memo(3e5+5), prevWeight(3e5+5, 1e9+5);

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> M;
  for (int i=0;i<M;i++) {
    int u,v,w;
    cin >> u >> v >> w;
    edges.push_back({w,u,v});
  }

  sort(edges.begin(), edges.end());

  int i = 0;
  queue<vi> q;
  while (i < M) {
    vi e = edges[i];
    int u,v,w;
    u = e[1]; v = e[2]; w = e[0];

    if (!q.empty()) {
      if (w != q.front()[0]) {
        while (!q.empty()) {
          vi p = q.front(); q.pop();
          int newVal = p[1], node = p[2];
          memo[node] = max(memo[node],newVal);
        }
      }
    }
    q.push({w, memo[u]+1, v});
    i++;
  }

  while (!q.empty()) {
    vi p = q.front(); q.pop();
    int newVal = p[1], node = p[2];
    memo[node] = max(memo[node],newVal);
  }

  int ans = 1;
  for (int i=0;i<=N;i++) {
    ans = max(ans, memo[i]);
  }

  cout << ans << endl;

  return 0;
}
