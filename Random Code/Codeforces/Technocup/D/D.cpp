#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

vector<vi> adjList(7);

int bfs(int N) {
  queue<ii> q;
  vi dist(1e4+5, -1);
  q.push({0,1});
  dist[0] = 0;

  while (!q.empty()) {
    ii cur = q.front(); q.pop();
    int s,f;
    s = cur.first;
    f = cur.second;
    if (s == N) return dist[s];

    for (int nextF: adjList[f]) {
      if (s+nextF <= N && dist[s+nextF] == -1) {
        dist[s+nextF] = dist[s] +1;
        q.push({s+nextF, nextF});
      }
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  adjList[1] = {2,3,4,5};
  adjList[2] = {1,3,4,6};
  adjList[3] = {1,2,5,6};
  adjList[4] = {1,2,5,6};
  adjList[5] = {1,3,4,6};
  adjList[6] = {2,3,4,5};

  int T; cin >> T;
  while (T--) {
    int N; cin >> N;

    cout << bfs(N) << endl;
  }
  return 0;
}
