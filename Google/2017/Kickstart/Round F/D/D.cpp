#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int N;

/*
50 = 49 + 1
49 = 49
48 = 16 + 16 + 16

5 = 4 + 1
4 = 4
3 = 1 + 1 + 1
2 = 1 + 1
1 = 1
*/


int rec(int remain, vi &memo) {
  if (remain < 0) return 1e5;
  if (remain == 0) return 0;
  if (remain == 1) return 1;
  if (memo[remain] != -1) return memo[remain];
  memo[remain] = remain;
  for (int i=1;i*i<=remain;i++) {
    memo[remain] = min(memo[remain], 1 + rec(remain-i*i, memo));
  }
  return memo[remain];
}

void solve() {
  cin >> N;
  vi memo(1e4+5,-1);
  cout << rec(N,memo) << endl;
}

int main() {
  int T; cin >> T;
  for (int t=1;t<=T;t++) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
