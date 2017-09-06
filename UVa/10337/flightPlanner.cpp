#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<ll> vll;
typedef vector<vll> vvll;

ll INF = LLONG_MAX/2;

int X;
vvi world(10, vi(1000));

ll dp(int miles, int alt, vvll &memo) {
  if (alt < 0 || alt > 9) return INF;
  if (miles == X) {
    if (alt == 0) return 0;
    else return INF;
  }
  if (memo[miles][alt] != -1) return memo[miles][alt];

  // climb
  ll climb = 60 - world[alt][miles] + dp(miles+1, alt+1, memo);
  ll stay = 30 - world[alt][miles] + dp(miles+1, alt, memo);
  ll sink = 20 - world[alt][miles] + dp(miles+1, alt-1, memo);

  vll a = {climb, stay, sink};

  memo[miles][alt] = *min_element(a.begin(), a.end());
  return memo[miles][alt];
}

void solve() {
  cin >> X; X/=100;
  for (int i=9;i>=0;i--) {
    for (int j=0;j<X;j++) {
      cin >> world[i][j];
    }
  }

  vvll memo(X+5, vll(10, -1));

  cout << dp(0, 0, memo) << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
    cout << endl;
  }
  return 0;
}
