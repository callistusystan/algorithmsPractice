#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve() {
  int N; cin >> N;
  vvi M(N, vi(N));
  for (int i=0;i<N;i++) for (int j=0;j<N;j++) cin >> M[i][j];

  vi bobMoves(N);
  for (int i=0;i<N;i++) bobMoves[i] = i;

  bool first = true;
  int ans;
  do {
    int curAns = 0;
    for (int i=0;i<N;i++) {
      curAns += M[i][bobMoves[i]];
    }
    if (first) {
      ans = curAns;
      first = false;
    }
    else ans = min(ans, curAns);
  } while (next_permutation(bobMoves.begin(), bobMoves.end()));

  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
