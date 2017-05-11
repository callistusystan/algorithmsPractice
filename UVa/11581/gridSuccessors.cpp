#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi hor = {1,0,-1,0}, ver = {0,1,0,-1};
vvi g(3, vi(3));

bool isValid(int i, int j) {
  return (i>=0 && i<3 && j>=0 && j<3);
}

bool isAllZeroes(vvi &g) {
  for (int i=0;i<3;i++)
    for (int j=0;j<3;j++)
      if (g[i][j] != 0) return false;
  return true;
}

vvi f(vvi &g) {
  vvi tmp = g;

  for (int i=0;i<3;i++)
    for (int j=0;j<3;j++) {
      int sum = 0;
      for (int k=0;k<4;k++) {
        if (isValid(i+ver[k], j+hor[k])) {
          sum += g[i+ver[k]][j+hor[k]];
          tmp[i][j] = sum%2;
        }
      }
    }
  return tmp;
}

void solve() {
  for (int i=0;i<3;i++) {
    for (int j=0;j<3;j++) {
      char c;
      cin >> c;
      g[i][j] = c - '0';
    }
  }

  int ans = -1;
  while (!isAllZeroes(g)) {
    g = f(g);
    ans++;
  }

  cout << ans << endl;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
