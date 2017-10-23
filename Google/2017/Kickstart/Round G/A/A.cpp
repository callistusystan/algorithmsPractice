#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef __int128 big;

int N;

ll expmod(big a, big b, big m) {
  big res = 1%m;
  a%= m;
  for (;b;b/=2) {
    if (b&1) res = (res*a)%m;
    a= (a*a)%m;
  }

  return res;
}

void solve() {
  ll A,N,P; cin >> A>> N >> P;

  ll ans = A%P;

  while (N > 1) {
    ans = expmod(ans, N, P);
    N--;
  }

  cout << ans << endl;
}

int main() {
  int T; cin >> T;
  for (int t=1;t<=T;t++) {
    cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
