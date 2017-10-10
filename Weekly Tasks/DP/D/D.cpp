#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int N,M,K;
vi colors(105);
vector<vi> P(105, vi(105, -1));
ll memo[105][105][105];

ll rec(int cur, int color, int remainK) {
  if (remainK < 0) return -1;
  if (cur == N && remainK == 0) return 0;
  else if (cur == N && remainK != 0) return -1;
  else if (memo[cur][color][remainK] != -2) return memo[cur][color][remainK];

  ll res = -1;

  if (colors[cur] == 0) {
    for (int i=1;i<=M;i++) {
      int nextK;
      if (i == color) nextK = remainK;
      else nextK = remainK-1;

      if (rec(cur+1, i, nextK) != -1) {
        if (res == -1) res = rec(cur+1, i, nextK) + P[cur][i];
        res = min(res, rec(cur+1, i, nextK) + P[cur][i]);
      }
    }
  } else if (colors[cur] == color) {
    res = rec(cur+1, colors[cur], remainK);
  } else {
    res = rec(cur+1, colors[cur], remainK-1);
  }

  memo[cur][color][remainK] = res;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  for (int i=0;i<105;i++) {
    for (int j=0;j<105;j++) {
      for (int k=0;k<105;k++) {
        memo[i][j][k] = -2;
      }
    }
  }

  cin >> N >> M >> K;
  for (int i=0;i<N;i++) cin >> colors[i];

  for (int i=0;i<N;i++) {
    for (int j=1;j<=M;j++) {
      cin >> P[i][j];
    }
  }

  if (colors[0] == 0) {
    ll val = -1;
    for (int i=1;i<=M;i++) {
      if (rec(1,i,K-1) != -1) {
        if (val == -1) val = rec(1,i,K-1) + P[0][i];
        val = min(val, rec(1,i,K-1)+P[0][i]);
      }
    }
    cout << val << endl;
  } else {
    cout << rec(1,colors[0],K-1) << endl;
  }

  return 0;
}
