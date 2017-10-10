#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

vi fac , pr;
void fast_sieve (int n) {
  fac . assign (n + 1, 0);
  for (ll i = 2; i <= n; ++i) {
    if ( fac [i] == 0) fac [i] = i, pr. push_back (i);
    for (int p : pr) if (p > fac [i] || i * p > n) break ; else fac[i * p] = p;
  }
}

void solve() {
  int A,B; cin >> A >> B;
  cout << fac[A] << " " << fac[B] << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  fast_sieve(5e6+5);

  int T; cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
