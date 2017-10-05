#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

vi fac , pr;
vector<ll> memo(5e6+5, -1), prefSum(5e6+5,0);

void fast_sieve (int n) {
  fac . assign (n + 1, 0);
  for (ll i = 2; i <= n; ++i) {
    if ( fac [i] == 0) fac [i] = i, pr. push_back (i);
    for (int p : pr) if (p > fac [i] || i * p > n) break ; else fac[i * p] = p;
  }
}

ll nPrimeFactors(int n) {
  if (n <= 1) return 0;
  if (memo[n] != -1) return memo[n];

  int nextNum = n/fac[n];
  memo[n] = nPrimeFactors(nextNum) + 1;
  return memo[n];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  fast_sieve(5e6+5);
  memo[0] = memo[1] = 0;
  for (int i=2;i<=5e6;i++) {
    memo[i] = memo[i/fac[i]] + 1;
    prefSum[i] = prefSum[i-1] + memo[i];
  }

  int T; cin >> T;
  int A,B;
  while (T--) {
    cin >> A >> B;
    cout << prefSum[A] - prefSum[B] << '\n';
  }

  return 0;
}
