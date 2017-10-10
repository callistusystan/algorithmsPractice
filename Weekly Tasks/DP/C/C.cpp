#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int NORMAL = 0, REVERSED = 1;

int N;
vi cost(1e5+5);
vector<vector<string>> strings(1e5+5, vector<string>(2));
vector<vector<ll>> memo(1e5+5, vector<ll>(2, -2));

ll rec(int cur, int prev) {
  if (cur == N) return 0;
  if (memo[cur][prev] != -2) return memo[cur][prev];
  memo[cur][prev] = -1;

  if (strings[cur][NORMAL] >= strings[cur-1][prev]) {
    if (rec(cur+1, NORMAL) != -1) {
      if (memo[cur][prev] == -1) {
        memo[cur][prev] = rec(cur+1, NORMAL);
      }
      memo[cur][prev] = min(memo[cur][prev], rec(cur+1, NORMAL));
    }
  }
  if (strings[cur][REVERSED] >= strings[cur-1][prev]) {
    if (rec(cur+1, REVERSED) != -1) {
      if (memo[cur][prev] == -1) {
        memo[cur][prev] = (ll)cost[cur] + rec(cur+1, REVERSED);
      }
      memo[cur][prev] = min(memo[cur][prev], (ll)cost[cur] + rec(cur+1, REVERSED));
    }
  }

  return memo[cur][prev];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N;
  for (int i=0;i<N;i++) {
    cin >> cost[i];
  }
  for (int i=0;i<N;i++) {
    cin >> strings[i][0];

    strings[i][1] = strings[i][0];
    reverse(strings[i][1].begin(), strings[i][1].end());
  }

  if (rec(1,NORMAL) != -1 && rec(1,REVERSED) != -1)
    cout << min(rec(1,NORMAL), (ll)cost[0]+rec(1,REVERSED)) << endl;
  else if (rec(1, NORMAL) == -1 && rec(1,REVERSED) == -1)
    cout << -1 << endl;
  else if (rec(1, NORMAL) == -1)
    cout << (ll)cost[0]+rec(1, REVERSED) << endl;
  else if (rec(1,REVERSED) == -1)
    cout << rec(1,NORMAL) << endl;

  return 0;
}
