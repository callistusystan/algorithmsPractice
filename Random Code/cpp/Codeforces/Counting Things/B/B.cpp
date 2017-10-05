#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vector<vector<ll>> C(105, vector<ll>(105));

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int i=0;i<105;i++) {
    C[i][0] = C[i][i] = 1;
    if (i == 0) continue;
    for (int j=1;j<i;j++) {
      C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }

  ll N; cin >> N;

  ll ans = C[N][5] * N * (N-1) * (N-2) * (N-3) * (N-4);

  cout << ans << endl;


  return 0;
}
