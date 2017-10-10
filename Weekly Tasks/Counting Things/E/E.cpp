#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int MOD = 1e8;

int N1,N2,K1,K2;
vector<vector<vi>> memo(105, vector<vi>(105,vi(2,-1)));

void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int rec(int N1, int N2, int cur) {
  if (N1 < 0 || N2 < 0) return 0;
  if (N1 == 0 && N2 == 0) return 1;
  else if (memo[N1][N2][cur] != -1) return memo[N1][N2][cur];

  int ans = 0;
  for (int i=1;i<=(cur == 0? K1 : K2);i++) {
    if (cur == 0)
      add(ans, rec(N1-i, N2, 1-cur));
    else
      add(ans, rec(N1, N2-i, 1-cur));
  }
  memo[N1][N2][cur] = ans;
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  cin >> N1 >> N2 >> K1 >> K2;

  int ans = 0;
  for (int i=1;i<=K1;i++) {
    add(ans, rec(N1-i, N2, 1));
  }
  for (int i=1;i<=K2;i++) {
    add(ans, rec(N1, N2-i, 0));
  }

  cout << ans << endl;

  return 0;
}
