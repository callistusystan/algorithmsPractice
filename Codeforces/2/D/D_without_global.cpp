#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef long long ll;
typedef vector<ll> vll;

typedef pair<int, int> ii;
typedef vector<ii> vii;

typedef pair<ll, int> lli;
typedef vector<lli> vlli;

int N, M, L, S, T;
vvi adjList(1005);
vector<vll> adjMatrix(1005, vll(1005,-1));
vii edges;

struct Result {
  vll dist;
  vi parent;
  Result(vll &aDist, vi &aParent) {
    dist = aDist;
    parent = aParent;
  }
};

Result dijkstra(int S, int T, bool useZero) {
  vll dist(N+5, -1);
  vi parent(N+5, -1);
  priority_queue<lli, vlli, greater<lli>> pq;

  dist[S] = 0;
  pq.push(lli(0, S));

  while (!pq.empty()) {
    lli front = pq.top(); pq.pop();
    ll d = front.first; int u = front.second;
    if (d > dist[u]) continue;
    for (int v : adjList[u]) {
      ll w;
      // see if it is zero
      if (adjMatrix[u][v] == 0) {
        if (!useZero) continue;
        w = 1; // its min value
      } else {
        w = adjMatrix[u][v];
      }
      if (dist[v] == -1 || dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        parent[v] = u;
        pq.push(lli(dist[v], v));
      }
    }
  }

  return Result(dist, parent);
}

void solve() {
  cin >> N >> M >> L >> S >> T;
  for (int i=0;i<M;i++) {
    int u,v,w; cin >> u >> v >> w;
    adjList[u].push_back(v);
    adjList[v].push_back(u);

    adjMatrix[u][v] = w;
    adjMatrix[v][u] = w;
    edges.push_back({u, v});
  }

  // dijkstra without using zero edges
  Result res1 = dijkstra(S, T, false);
  vll dist; vi parent;
  dist = res1.dist; parent = res1.parent;

  // if shortest dist to T is < L, fail
  // if shortest dist to T is == L, pass
  // if shortest dist to T is > L, test dijkstra using zero edges <= L
  if (dist[T] < L && dist[T] != -1) {
    cout << "NO" << endl;
    return;
  } else if (dist[T] == L) {
    cout << "YES" << endl;
    for (ii edge: edges) {
      int u,v; u = edge.first; v = edge.second;
      if (adjMatrix[u][v] == 0) {
        adjMatrix[u][v] = 1;
      }
      cout << u << " " << v << " " << adjMatrix[u][v] << endl;
    }
    return;
  }

  // dijkstra with using zero edges
  Result res2 = dijkstra(S, T, true);
  dist = res2.dist; parent = res2.parent;
  // if dist[T] > L, fail
  // if dist[T] <= L, pass

  if (dist[T] == -1 || dist[T] > L) {
    cout << "NO" << endl;
    return;
  }


  while (dist[T] < L) {
    // find first zero edge in cur shortest path
    ll remaining = L - dist[T];
    int cur = T;
    while (cur != S) {
      int u,v;
      v = cur; u = parent[cur];
      if (adjMatrix[u][v] == 0) {
        adjMatrix[u][v] = remaining+1;
        adjMatrix[v][u] = remaining+1;
        break;
      }
      cur = parent[cur];
    }
    Result res = dijkstra(S, T, true);
    dist = res.dist; parent = res.parent;
  }

  if (dist[T] != L) {
    cout << "NO" << endl;
    return;
  }

  // set all zero edges on shortest path to 1
  int cur = T;
  while (cur != S) {
    int u,v;
    v = cur; u = parent[cur];
    if (adjMatrix[u][v] == 0) {
      adjMatrix[u][v] = 1;
      adjMatrix[v][u] = 1;
    }
    cur = parent[cur];
  }

  cout << "YES" << endl;
  for (ii edge: edges) {
    int u,v; u = edge.first; v = edge.second;
    // all other zero edges can be 1 since they wont result in a shorter path
    // than what we found
    if (adjMatrix[u][v] == 0) {
      adjMatrix[u][v] = 1;
    }
    cout << u << " " << v << " " << adjMatrix[u][v] << endl;
  }
}

int main() {
  solve();
  return 0;
}
