#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi nums(1e3+5);
vector<vi> memo(1e3+5, vi(1e3+5,-1));

int N;

int rec(int i, int j, vector<vi> &memo) {
  if (i > j) return 0;
  if (memo[i][j] != -1) return memo[i][j];

  int id = ((N - (j-i+1)) % 2 == 0 ? 0 : 1);

  // try front
  int tryFront = (id == 0 ? nums[i] : -nums[i]) + rec(i+1,j, memo);
  // try back
  int tryBack = (id == 0 ? nums[j] : -nums[j]) + rec(i,j-1, memo);

  if (id == 0) {
    memo[i][j] = max(tryFront, tryBack);
  } else {
    memo[i][j] = min(tryFront, tryBack);
  }
  return memo[i][j];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T; cin >> T;
  while (T--) {
    cin >> N;
    for (int i=0;i<N;i++) cin >> nums[i];
    for (int j=0;j<N;j++) {
      for (int k=0;k<N;k++) {
        memo[j][k] = -1;
      }
    }
    cout << rec(0,N-1,memo) << endl;
  }
  return 0;
}
