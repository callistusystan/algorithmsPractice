#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> ii;
typedef vector<ii> vii;

typedef tuple<ll, int, int> llii;
typedef vector<llii> vllii;

int N, M, L, S, T;
vector<vii> adjList(1005);
vector<vi> edgesMatrix(1005, vi(1005, -1)), edges;

void dijkstra(int s, int t, vector<vii> &adjList, vector<vi> &edges) {
  vector<ll> dist(N+5, -1);
  vi parent(N+5, -1);
  priority_queue<llii, vllii, greater<llii>> pq;

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

  ll remaining = L - dist[t];

  if (dist[t] == -1 || remaining < 0) {
    cout << "NO" << endl;
    return;
  }
  int count = 0;
  int cur = t;
  while (cur != s) {
    int u,v;
    v = cur; u = parent[cur];
    if (edgesMatrix[u][v] == 0 || edgesMatrix[v][u] == 0) {
      count++;
    }
    cur = parent[cur];
  }
  if (remaining < count) {
    cout << "NO" << endl;
    return;
  }

  cur = t;
  while (cur != s) {
    int u,v;
    v = cur; u = parent[cur];
    if (edgesMatrix[u][v] == 0 || edgesMatrix[v][u] == 0) {
      if (count == 1) {
        edgesMatrix[u][v] = remaining;
        edgesMatrix[v][u] = remaining;
        remaining = 0;
      } else {
        edgesMatrix[u][v] = 1;
        edgesMatrix[v][u] = 1;
        remaining--;
      }
      count--;
    }
    cur = parent[cur];
  }

  cout << "YES" << endl;
  for (vi edge: edges) {
    int u,v; u = edge[0]; v = edge[1];
    if (edgesMatrix[u][v] == 0) {
      edgesMatrix[u][v] = 1;
    }
    cout << u << " " << v << " " << edgesMatrix[u][v] << endl;
  }
}

void solve() {
  cin >> N >> M >> L >> S >> T;
  for (int i=0;i<M;i++) {
    int u,v,w; cin >> u >> v >> w;
    edgesMatrix[u][v] = w;
    edgesMatrix[v][u] = w;
    edges.push_back({u, v});
    if (w == 0) w = 1;
    adjList[u].push_back(ii(v,w));
    adjList[v].push_back(ii(u,w));
  }

  dijkstra(S, T, adjList, edges);
}

int main() {
  solve();
  return 0;
}
