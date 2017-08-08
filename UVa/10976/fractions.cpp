#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(int K) {
  // 1/k = 1/x + 1/y
  // x >= y
  // 1 sol is x = y = 2k
  // 1/k = 1/2k + 1/2k

  // since other sol will need to have x > y
  // thus, y <= 2k

  // however, y cannot be k
  // because no value of x can make 1/k = 1/x + 1/k

  // thus compute x using y in [k+1,k]
  // x can be obtained by
  // 1/x = 1/k - 1/y
  // 1/x = (y-k)/ky
  // x = ky/(y-k)
  // note that for x to be integer, (y-k) must divide ky

  vector<pair<int,int>> sols;

  for (int y=K+1;y<=2*K;y++) {
    if ((K*y)%(y-K) == 0) {
      int x = (K*y)/(y-K);
      sols.push_back(make_pair(x,y));
    }
  }

  cout << sols.size() << endl;

  for (pair<int, int> sol : sols) {
    cout << "1/" << K << " = 1/"  << sol.first << " + 1/" << sol.second << endl;
  }

}

int main() {
  int K;
  while (cin >> K) {
    solve(K);
  }
  return 0;
}
