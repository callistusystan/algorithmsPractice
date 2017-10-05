#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vector<bool> isprime;
void sieve(int n) {
  isprime.assign(n+1,1); isprime[0] = isprime[1] = 0;
  for (ll i=2;i*i<=n;i++) {
    if (isprime[i]) {
      for (ll j = i*i;j<=n;j+=i) {
        isprime[j] = 0;
      }
    }
  }
}

void naive() {
  for (int i=2;i<200;i++) {
    int N = i;
    ll ans = 1;
    for (int j=2;j*j<=N;j++) {
      ll c = 0;
      while (N%j==0) {
        c++; N/=j;
      }
      ans *= (c+1);
    }
    if (N > 1) ans *= (1+1);

    cerr << i << ": " << (ans == 3 ? "YES" : "NO") << endl;
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  sieve(1e6+5);
  int N; cin >> N;

  for (int i=0;i<N;i++) {
    ll x; cin >> x;

    bool isXTPrime = false;
    for (ll j=sqrt(x)-2;j<=sqrt(x)+2;j++) {
      if (j <= 1) continue;
      if (j*j == x && isprime[j]) {
        isXTPrime = true;
      }
    }
    if (isXTPrime) cout << "YES";
    else cout << "NO";
    cout << endl;
  }

  return 0;
}
