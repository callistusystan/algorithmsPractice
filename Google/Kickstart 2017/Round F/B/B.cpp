#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int E, N;

void solve() {
  cin >> E >> N;
  vi S(N);
  for (int i=0;i<N;i++) cin >> S[i];
  sort(S.begin(), S.begin()+N);

  int ans, honor; ans = honor = 0;
  int l,r; l = 0; r = N-1;
  while (l <= r) {
    if (E - S[l] > 0) {
      E -= S[l];
      honor++;
      l++;
    } else if (honor > 0) {
      E += S[r];
      honor--;
      r--;
    } else break;
    ans = max(ans, honor);
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
