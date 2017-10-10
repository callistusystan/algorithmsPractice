#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi fac, pr;
void fast_sieve(int n) {
  fac.assign(n+1, 0);
  for (ll i=2;i<=n;++i) {
    if (fac[i] == 0) fac[i] = i, pr.push_back(i);
    for (int p : pr) if (p > fac[i] || i*p > n) break;
    else fac[i*p] = p;
  }
}

ll fast_factors(ll n, ll e) {
  ll ans = 0;

  for (int p : pr) {
    if (n == 1) return ans;

    ll c = 0;
    while (n%p == 0) {
      n /= p;
      c++;
    }
    ans += p*c*e;
  }
  if (n > 1) ans += n*e;

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  fast_sieve(32000);

  int T; cin >> T;
  while (T--) {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;

    ll LHS = fast_factors(a,b);
    ll RHS = fast_factors(c,d);
    if (LHS < RHS) cout << "<";
    else cout << ">";
    cout << endl;
  }
  return 0;
}
