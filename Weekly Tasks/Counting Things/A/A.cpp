#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vector<vector<ll>> C(1000, vector<ll>(1000));

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  for (int i=0;i<1000;i++) {
    C[i][0] = C[i][i] = 1;
    if (i == 0) continue;
    for (int j=1;j<i;j++) {
      C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }

  int N; cin >> N;
  cout << C[N][5] + C[N][6] + C[N][7] << endl;



  return 0;
}
