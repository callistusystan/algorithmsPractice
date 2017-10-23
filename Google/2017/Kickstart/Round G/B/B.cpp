#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int N;
vi R(10), B(10);

ll rec(int used, vector<ll> &memo) {
  if (__builtin_popcount(used) == N-1) return 0;
  if (memo[used] != -1) return memo[used];

  ll ans = 1e15;
  for (int i=0;i<N;i++) {
    if ((used>>i) & 1) continue;
    for (int j=0;j<N;j++) {
      if ( i == j || ((used>>j) & 1) ) continue;

      ans = min(ans, (R[i]^B[j]) + rec(used | (1<<i), memo));
      ans = min(ans, (R[i]^B[j]) + rec(used | (1<<j), memo));
    }
  }

  return memo[used] = ans;
}

void solve() {
  cin >> N;
  for (int i=0;i<N;i++) cin >> R[i];
  for (int i=0;i<N;i++) cin >> B[i];
  vector<ll> memo((1<<10), -1);

  cout << rec(0, memo) << endl;
}

int main() {
  int T; cin >> T;
  for (int t=1;t<=T;t++) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
