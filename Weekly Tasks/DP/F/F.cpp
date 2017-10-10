#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N;
vi colors(505);
vector<vi> memo(505, vi(505, -1));

int rec(int i, int j) {
  if (i > j) return 0;
  if (i == j) return 1;
  if (memo[i][j] != -1) return memo[i][j];

  int ans = j-i+1;

  for (int k=i+1;k<=j;k++) {
    if (colors[i] == colors[k]) {
      ans = min(ans, ((k == i+1) ? 1 : 0) + rec(i+1,k-1) + rec(k+1,j));
    }
  }

  // try i+1..j
  ans = min(ans, 1 + rec(i+1,j));
  // try i..j-1
  ans = min(ans, 1 + rec(i,j-1));

  // cerr << i << " " << j << " has val " << ans << endl;

  return memo[i][j] = ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N;
  for (int i=0;i<N;i++) cin >> colors[i];

  cout << rec(0, N-1) << endl;

  return 0;
}
