#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int N, M; char c;
    cin >> N >> c >> c >> M;
    int pass = (N*M+99)/100;
    int s = 0;
    for (int i=0;i<(int)N;i++) {
      int g; cin >> g;
      if (g >=50) s++;
    }
    if (s >= pass) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
