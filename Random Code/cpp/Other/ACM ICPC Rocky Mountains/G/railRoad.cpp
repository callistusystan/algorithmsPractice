#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int N1, N2;
vi train1(1005), train2(1005), pat(2005);
vvi memo(1005, vi(1005,-1)); // 0 false, 1 true, -1 not computed

bool f(int p1, int p2) {
  int i = p1 + p2;
  if (i == N1+N2) return true;
  else if (memo[p1][p2] != -1) return memo[p1][p2];

  // do stuff
  if (p1 < N1 && p2 < N2 && pat[i] == train1[p1] && pat[i] ==train2[p2]) {
    // try both
    if (f(p1+1,p2) || f(p1, p2+1))
      return memo[p1][p2] = true;
  } else if (p1 < N1 && pat[i] == train1[p1]) {
    if (f(p1+1, p2)) return memo[p1][p2] = true;
  } else if (p2 < N2 && pat[i] == train2[p2]) {
    if (f(p1, p2+1)) return memo[p1][p2] = true;
  }

  return memo[p1][p2] = false;
}

void solve() {
  for (int i=0;i<N1;i++) cin >> train1[i];
  for (int i=0;i<N2;i++) cin >> train2[i];
  for (int i=0;i<N1+N2;i++) cin >> pat[i];

  for (int i=0;i<1005;i++)
    for (int j=0;j<1005;j++) memo[i][j] = -1;

  if (f(0,0)) cout << "possible";
  else cout << "not possible";
  cout << endl;
}

int main() {
  while (cin >> N1 >> N2, N1 || N2) {
    solve();
  }
  return 0;
}
