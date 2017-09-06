#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<ll> vll;
typedef vector<vll> vvll;

struct Coin {
  int c;
  int i;
};

ll INF = LLONG_MAX/2;

ll dp(int id, int c, int i, int target, vector<Coin> &coins, vector<vector<vll>> &memo) {
  if (c*c + i*i == target) return 0;
  else if (c*c + i*i > target) return INF;
  if (id == (int)coins.size()) return INF;
  if (memo[id][c][i] != -1) return memo[id][c][i];

  ll tryCoin = 1 + dp(id, c+coins[id].c, i+coins[id].i, target, coins, memo);
  ll dontTryCoin = dp(id+1, c, i, target, coins, memo);

  memo[id][c][i] = min(tryCoin, dontTryCoin);
  return memo[id][c][i];
}

void solve() {
  int M, S; cin >> M >> S;
  vector<Coin> coins(M);
  for (int i=0;i<M;i++) {
    cin >> coins[i].c >> coins[i].i;
  }

  vector<vector<vll>> memo(M+5, vector<vll>(S+5, vll(S+5, -1)));

  ll ans = dp(0, 0, 0, S*S, coins, memo);
  if (ans == INF) cout << "not possible" << endl;
  else cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
