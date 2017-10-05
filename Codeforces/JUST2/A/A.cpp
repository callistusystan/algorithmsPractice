#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll MOD = 1e9+7;

// ax + by = gcd (a,b). Returns gcd (a,b). Compexity : O( log ( min (a,b)))
ll gcd (ll a, ll b, ll& x, ll& y) {
  if (b == 0) { y = 0; x = (a < 0) ? -1 : 1; return (a < 0) ? -a : a; }
  else { ll g = gcd (b, a%b, y, x); y -= a/b*x; return g; }
}
ll inv (ll a, ll m) { ll x, y; gcd (m,a,x,y); return ((y % m) + m) % m; }

int main() {
  ll M,N,K,D1,D2; char c;
  cin >> M >> N >>K >> D1 >> c >> D2;
  ll D = D1*1000+D2;

  ll num,denom;
  num = 1;
  for (int i=0;i<(K-1);i++) {
    num *= D;
    num %= MOD;
    denom *= 1000;
    denom %= MOD;
  }
  for (int i=0;i<(N-(K-1));i++) {
    num *= 1000-D;
    num %= MOD;
    denom *= 1000;
    denom %= MOD;
  }

  cout << num/__gcd(num,denom) << endl;
  cout << denom/__gcd(num,denom) << endl;



  return 0;
}
