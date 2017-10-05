#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD = 1e9+7;

ll gcd (ll a, ll b, ll& x, ll& y) {
  if (b == 0) { y = 0; x = (a < 0) ? -1 : 1; return (a < 0) ? -a : a; }
else { ll g = gcd (b, a%b, y, x); y -= a/b*x; return g; }
}
// Multiplicative inverse of a mod m, for a,m coprime . Complexity : O( log (a))
ll inv (ll a, ll m) { ll x, y; gcd (m,a,x,y); return ((y % m) + m) % m; }

vector<ll> memo(1e5+5,-1);

ll fac(ll N) {
	if (N <= 1) return 1;
	if (memo[N] != -1) return memo[N];
	memo[N] = (N * fac(N-1))%MOD;
	return memo[N];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int T; cin >> T;
	while (T--) {
		ll A,B; cin >> A >> B;

		ll num, den1, den2, den;
		num = fac(A-1);
		den1 = fac(A-1-B);
		den2 = fac(B);
		den = (den1*den2)%MOD;
		ll ans = (2*num*inv(den, MOD))%MOD;

		cout << ans << endl;

	}
	return 0;
}
