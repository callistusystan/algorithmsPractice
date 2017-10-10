#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int MOD = 1e9+7;
int N,A,B,K;
vector<vi> memo(5050, vi(5050,-1));

void add(int &a, int b) {
  a += b;
  if (a >= MOD) a-=MOD;
}

void sub(int &a, int b) {
  a -= b;
  if (a < 0) a+=MOD;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> A >> B >> K;
  A--; B--;

  for (int i=0;i<N;i++) {
    memo[0][i] = 1;
  }
  memo[0][B] = 0;

  for (int i=0;i<=K;i++) {
    if (i > 0) {
      for (int j=0;j<N;j++) {
        memo[i][j] = 0;
        int d = abs(B-j)-1;
        if (d > 0) {
          int l,r;
          l = max(0, j-d);
          r = min(N-1, j+d);
          add(memo[i][j], memo[i-1][r]);
          sub(memo[i][j], memo[i-1][j]);
          if (j > 0)
            add(memo[i][j], memo[i-1][j-1]);
          if (l > 0)
            sub(memo[i][j], memo[i-1][l-1]);
        }
      }
    }

    for (int j=1;j<N;j++) {
      add(memo[i][j], memo[i][j-1]);
    }
  }

  int ans = memo[K][A];
  if (A > 0)
    sub(ans, memo[K][A-1]);

  cout << ans << endl;

  return 0;
}
