#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int SIZE = 1000;

vector<vector<ll>> C(SIZE, vector<ll>(SIZE));

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  for (int i=0;i<SIZE;i++) {
    C[i][0] = C[i][i] = 1;
    if (i == 0) continue;
    for (int j=1;j<i;j++) {
      C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }

  ll N; cin >> N;

  ll ans = C[5+N-1][N-1] * C[3+N-1][N-1];

  cout << ans << endl;

  return 0;
}
