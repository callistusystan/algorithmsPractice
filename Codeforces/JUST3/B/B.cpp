#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T; cin >> T;
  while(T--) {
    int N; cin >> N;

    map<ll, ll> a, b;
    for (int i=0;i<N;i++) {
      ll ai,bi; cin >> ai >> bi;
      a[ai]++;
      b[bi]++;
    }
    ll ans = 0;
    for (auto it=b.begin();it!=b.end();it++) {
      pair<ll, ll> p = *it;
      ans += p.second * a[p.first];
    }
    cout << ans << endl;
  }

  return 0;
}
