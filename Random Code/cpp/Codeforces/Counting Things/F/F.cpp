#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi fac(1e6+5,1), inv(1e6+5);
int A,B,N, MOD = 1e9+7;

void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

void mult(int &a, int b) {
  a = ((ll)a * b)%MOD;
}

bool goodNumber(int num) {
  while (num > 0) {
    int d = num%10;
    if (!(d == A || d == B)) return false;
    num /= 10;
  }
  return true;
}

ll gcd (ll a, ll b, ll& x, ll& y) {
  if (b == 0) { y = 0; x = (a < 0) ? -1 : 1; return (a < 0) ? -a : a; }
  else { ll g = gcd (b, a%b, y, x); y -= a/b*x; return g; }
}

// Multiplicative inverse of a mod m, for a,m coprime . Complexity : O( log (a))
ll multInv (ll a, ll m) { ll x, y; gcd (m,a,x,y); return ((y % m) + m) % m; }

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  for (int i=2;i<1e6+5;i++) {
    fac[i] = i;
    mult(fac[i], fac[i-1]);
  }

  for (int i=0;i<1e6+5;i++) {
    inv[i] = multInv(fac[i], MOD);
  }


  cin >> A >> B >> N;

  int ans = 0;
  for (int i=0;i<=N;i++) {
    int sumDigits = i*A + (N-i)*B;
    if (goodNumber(sumDigits)) {
      int val = fac[N];
      mult(val, inv[N-i]);
      mult(val, inv[i]);
      add(ans, val);
    }
  }

  cout << ans << '\n';

  return 0;
}
