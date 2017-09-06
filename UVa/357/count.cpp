#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<ll> vll;
typedef vector<vll> vvll;


vvll memo(5, vll(30005, -1));
int coins[] = {1,5,10,25,50};

ll rec(int id, int remainVal, vvll &memo) {
  if (remainVal < 0) return 0;
  if (remainVal == 0) return 1;
  if (id == 5) return 0;
  if (memo[id][remainVal] != -1) return memo[id][remainVal];

  // try this coin
  ll tryCoin = rec(id, remainVal - coins[id], memo);
  // dont try this coin
  ll dontTryCoin = rec(id+1, remainVal, memo);

  memo[id][remainVal] = tryCoin + dontTryCoin;
  return memo[id][remainVal];
}

void solve(int val) {
  ll ans = rec(0, val, memo);

  if (ans == 1)
    printf("There is only 1 way to produce %d cents change.\n", val);
  else
    printf("There are %lld ways to produce %d cents change.\n", ans, val);
}

int main() {
  int val;
  while (cin >> val)
    solve(val);
  return 0;
}
