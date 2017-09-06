#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int N, M;
vi dist(1000005, -1);

void solve() {
  cin >> N >> M;

  dist[N] = 0;
  queue<int> q; q.push(N);

  while (!q.empty()) {
    int u = q.front(); q.pop();
    if (u == M) break;
    // red
    if (2*u >= 0 && 2*u < 1000000 && dist[2*u] == -1) {
      dist[2*u] = dist[u] + 1;
      q.push(2*u);
    }
    // blue
    if (u-1 >= 0 && 2*u < 1000000 && dist[u-1] == -1) {
      dist[u-1] = dist[u] + 1;
      q.push(u-1);
    }
  }

  cout << dist[M] << endl;
}

int main() {
  solve();
  return 0;
}
