#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> ii;
typedef vector<ii> vii;

typedef pair<ll, int> lli;
typedef vector<lli> vlli;

int N, M;

void dijkstra(int s, vector<vii> &adjList) {
  vector<ll> dist(N+5, -1);
  vi parent(N+5, -1);
  priority_queue<lli, vlli, greater<lli>> pq;

  dist[s] = 0;
  pq.push(lli(0, s));

  while (!pq.empty()) {
    lli front = pq.top(); pq.pop();
    ll d = front.first; int u = front.second;
    if (d > dist[u]) continue;
    for (ii next : adjList[u]) {
      int v = next.first; ll w = next.second;
      if (dist[v] == -1 || dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        parent[v] = u;
        pq.push(lli(dist[v], v));
      }
    }
  }

  if (dist[N] == -1) {
    cout << -1 << endl;
    return;
  }
  int cur = N;
  stack<int> ans;
  while (cur != -1) {
    ans.push(cur);
    cur = parent[cur];
  }

  while (!ans.empty()) {
    cout << ans.top() << " ";
    ans.pop();
  }
  cout << endl;
}

void solve() {
  cin >> N >> M;

  vector<vii> adjList(N+5);
  for (int i=0;i<M;i++) {
    int u,v,w; cin >> u >> v >> w;
    if (u == v) continue;
    adjList[u].push_back(ii(v, w));
    adjList[v].push_back(ii(u, w));
  }

  dijkstra(1, adjList);
}

int main() {
  solve();
  return 0;
}
