#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll N, K;
ll MOD = 1e9+7;
vector<ll> fac(1e3+5);

ll gcd (ll a, ll b, ll& x, ll& y) {
  if (b == 0) { y = 0; x = (a < 0) ? -1 : 1; return (a < 0) ? -a : a; }
  else { ll g = gcd (b, a%b, y, x); y -= a/b*x; return g; }
}

// Multiplicative inverse of a mod m, for a,m coprime . Complexity : O( log (a))
ll inv (ll a, ll m) {
  ll x, y; gcd (m,a,x,y); return ((y % m) + m) % m;
}

void solve() {
  cin >> N >> K;

  if (N < K) {
    cout << 0 << endl;
    return;
  }

  ll top, btm;
  // fac(N)/fac(N-k)
  top = fac[N];
  btm = fac[N-K];

  cout << (top*inv(btm, MOD))%MOD << endl;
}

int main() {
  fac[0] = fac[1] = 1;
  for (int i=2;i<1e3+5;i++)
    fac[i] = (fac[i-1]*(ll)i)%MOD;

  int T; cin >> T;
  while (T--) solve();

  return 0;
}
