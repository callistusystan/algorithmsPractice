#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int N, M;
vector<string> stations(1e4+5);
vector<vector<pii>> adjList(1e4+5);

vi dist(1e4+5, -1);

void dijkstra(int S) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  dist[S] = 0;
  pq.push({0,S});

  while (!pq.empty()) {
    pii cur = pq.top(); pq.pop();
    int d = cur.first, u = cur.second;
    // cerr << "AT " << u << ", " << stations[u] << endl;
    if (d > dist[u]) continue;
    for (pii p : adjList[u]) {
      int v,w; v = p.first; w = p.second;
      if (dist[v] == -1 || d+w < dist[v]) {
        dist[v] = d + w;
        pq.push({d+w,v});
      }
    }
  }
}

int getDistance(int i, int j) {
  vi freq1(26,0), freq2(26,0);
  for (char c : stations[i]) {
    freq1[tolower(c)-'a']++;
  }
  for (char c : stations[j]) {
    freq2[tolower(c)-'a']++;
  }
  int ans = 0;
  for (int i=0;i<26;i++) {
    if (freq1[i] && freq2[i]) ans++;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> N >> M;
  for (int i=0;i<N;i++) {
    cin >> stations[i];
  }

  for (int i=0;i<M;i++) {
    int u,v; cin >> u >> v;
    u--;v--;
    int d = getDistance(u,v);
    adjList[u].push_back({v,d});
    adjList[v].push_back({u,d});
  }

  int S,E; cin >> S >> E;
  S--; E--;
  dijkstra(S);
  cout << dist[E] << endl;

  return 0;
}
