#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int N;

void solve() {
  cin >> N;
  vi R(N), B(N);
  for (int i=0;i<N;i++) cin >> R[i];
  for (int i=0;i<N;i++) cin >> B[i];

  priority_queue<pair<int, pii>, vector<pair<int, pii>, greater<pair<int, pii>>> pq;

  ll ans = 0;
  vi inGame(N, 1);
  vector<vi> points(N, vi(N));

  for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++) {
      if (i == j) continue;

      pq.push({B[i]^R[j], {i, j}});
      points[i][j] = B[i]^R[j];
    }
  }

  for (int k=0;k<N-1;k++) {
    int i,j;
    do {
      pair<int, pii> cur = pq.top(); pq.pop();
      i = cur.second.first;
      j = cur.second.second;

    } while(!(inGame[i] && inGame[j]));
    ans += cur.first;

    // choose one to remove
    for ()

  }

  cout << ans << endl;
}

int main() {
  int T; cin >> T;
  for (int t=1;t<=T;t++) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
