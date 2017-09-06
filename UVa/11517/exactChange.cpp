#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<ll> vll;
typedef vector<vll> vvll;

typedef pair<ll, ll> pll;

ll INF = 1e9;

pll dp(int id, int remainP, vi &bills, vector<vector<pll>> &memo) {
  if (remainP <= 0) return pll(0, 0);
  if (id == (int)bills.size()) return pll(INF, INF);
  if (memo[id][remainP] != pll(-1,-1)) return memo[id][remainP];

  pll tryThis = dp(id+1, remainP-bills[id], bills, memo);
  tryThis.first += bills[id];
  tryThis.second += 1;
  pll dontTryThis = dp(id+1, remainP, bills, memo);

  memo[id][remainP] = min(tryThis, dontTryThis);
  return memo[id][remainP];
}

void solve() {
  int P, N; cin >> P >> N;
  vi bills(N);
  for (int i=0;i<N;i++) {
    cin >> bills[i];
  }

  vector<vector<pll>> memo(N+5, vector<pll>(P+5, pll(-1,-1)));

  pll ans = dp(0, P, bills, memo);
  cout << ans.first << " " << ans.second << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
