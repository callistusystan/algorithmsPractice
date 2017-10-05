#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int MOD = 1e9+7;

ll gcd (ll a, ll b, ll& x, ll& y) {
  if (b == 0) { y = 0; x = (a < 0) ? -1 : 1; return (a < 0) ? -a : a; }
  else { ll g = gcd (b, a%b, y, x); y -= a/b*x; return g; }
}

// Multiplicative inverse of a mod m, for a,m coprime . Complexity : O( log (a))
ll multInv (ll a, ll m) { ll x, y; gcd (m,a,x,y); return ((y % m) + m) % m; }

void add(int &a, int b) {
  a += b;
  if (a >= MOD) a-= MOD;
}

void sub(int &a, int b) {
  a -= b;
  if (a < 0) a+= MOD;
}

void mult(int &x, int y) {
  x = ((long long)x * y)%MOD;
}

vi fac(1e5+5, 1), inv(1e5+5);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  fac[0] = fac[1] = 1;
  for (int i=2;i<1e5+5;i++) {
    fac[i] = i;
    mult(fac[i], fac[i-1]);
  }

  for (int i=0;i<1e5+5;i++) {
    inv[i] = multInv(fac[i], MOD);
  }

  int T, K; cin >> T >> K;

  vi ways(1e5+5);
  for (int i=0;i<K;i++) ways[i] = 1;
  for (int i=K;i<1e5+5;i++) {
    ways[i] = ways[i-1];
    add(ways[i], ways[i-K]);
  }

  vi prefSum(1e5+5);
  for (int i=1;i<1e5+5;i++) {
    prefSum[i] = ways[i];
    if (i == 1) continue;
    add(prefSum[i], prefSum[i-1]);
  }

  while (T--) {
    int A,B;
    cin >> A >> B;
    int ans = prefSum[B];
    sub(ans, prefSum[A-1]);
    cout << ans << '\n';
  }

  return 0;
}
