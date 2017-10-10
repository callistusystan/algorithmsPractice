#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

vector<vi> freqs(300,vi(10,0));
int common(int i, int j) {
  int s = 0;
  for (int k=0;k<10;k++) {
    s += min(freqs[i][k], freqs[j][k]);
  }
  return s;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int T; cin >> T;
  while (T--) {
    int N, S, E; cin >> N >> S >> E;
    S--; E--;
    for (int i=0;i<N;i++)
      for (int j=0;j<10;j++)
        freqs[i][j] = 0;

    for (int i=0;i<N;i++) {
      string s; cin >> s;
      for (char c : s) {
        freqs[i][c-'0']++;
      }
    }

    vector<vi> adjList(N);

    for (int i=0;i<N-1;i++) {
      for (int j=i+1;j<N;j++) {
        if (common(i,j) == 17) {
          adjList[i].push_back(j);
          adjList[j].push_back(i);
        }
      }
    }

    queue<int> q;
    vi dist(N,-1);

    q.push(S);
    dist[S] = 0;
    while (!q.empty()) {
      int cur = q.front(); q.pop();
      if (cur == E) break;
      for (int next : adjList[cur]) {
        if (dist[next] == -1) {
          dist[next] = dist[cur] + 1;
          q.push(next);
        }
      }
    }
    cout << dist[E] << endl;
  }
  return 0;
}
