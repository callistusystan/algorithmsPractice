#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

double memo[2005][2005];
int N, P, T;

double rec(int cur, int remainT) {
  if (remainT == 0) return cur;
  if (cur == N) return N;
  if (memo[cur][remainT] != -1) return memo[cur][remainT];

  double ans = 0;
  // goes in
  ans += rec(cur+1, remainT-1);
  // doesnt go in
  ans += rec(cur, remainT-1);

  return memo[cur][remainT] = ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  char c;
  cin >> N >> c >> c >> P >> T;

  for (int i=0;i<2005;i++) for(int j=0;j<2005;j++) memo[i][j] = -1;

  cout << rec(0, T) << endl;

  return 0;
}
