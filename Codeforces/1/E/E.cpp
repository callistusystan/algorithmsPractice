#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

map<string, int> userId;

int N;
vvi adjList;

int bfs(int s) {
  queue<int> q; q.push(s);
  vi dist(N+5, -1); dist[s] = 0;

  int maxD = 0;
  while (!q.empty()) {
    int u = q.front(); q.pop();
    maxD = max(maxD, dist[u]);
    for (int v: adjList[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u]+1;
        q.push(v);
      }
    }
  }
  return maxD;
}

string toUpperString(string s) {
  string ans;
  for (char c : s) {
    ans += toupper(c);
  }
  return ans;
}

void solve() {
  cin >> N;
  adjList.resize(N+5);

  int ID = 0;

  for (int i=0;i<N;i++) {
    string u, v;
    cin >> v >> u >> u;
    u = toUpperString(u);
    v = toUpperString(v);
    if (!userId.count(u))
      userId[u] = ID++;
    if (!userId.count(v))
      userId[v] = ID++;
    int UID, VID;
    UID = userId[u]; VID = userId[v];
    adjList[UID].push_back(VID);
  }

  cout << bfs(0) + 1 << endl;
}

int main() {
  solve();
  return 0;
}
