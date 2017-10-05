#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int N, M;
vector<vll> a(25005, vll(30)), b(25005, vll(30));
vector<vector<pair<ll,ll>>> memo(25005, vector<pair<ll,ll>>(30,{-1,-1}));

pair<ll, ll> rec(int i, int j) {
  if (i == N) return {0,0};
  if (memo[i][j].first != -1) return memo[i][j];

  // try j-1, j, j+1
  auto res = rec(i+1,j);
  res.first += a[i][j];
  memo[i][j] = res;

  if (j-1 >= 0) {
    auto res = rec(i,j-1);
    res.second += b[i][j-1];
    memo[i][j] = min(memo[i][j], res);
  }

  if (j+1 < M) {
    auto res = rec(i,j+1);
    res.second += b[i][j];
    memo[i][j] = min(memo[i][j], res);
  }

  return memo[i][j];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T; cin >> T;
  while (T--) {
    cin >> N >> M;

    for (int i=0;i<N;i++)
      for (int j=0;j<M;j++) cin >> a[i][j];

    for (int i=0;i<N;i++)
      for (int j=0;j<M-1;j++) cin >> b[i][j];

    for (int i=0;i<N;i++) {
      for (int j=0;j<M;j++) {
        memo[i][j] = {-1,-1};
      }
    }

    pair<ll, ll> ans = rec(0,0);
    cout << ans.first << " " << ans.second << endl;
  }
  return 0;
}
