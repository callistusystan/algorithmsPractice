#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;

int R,S,P;
vector<vector<vector<vd>>> memo(105, vector<vector<vd>>(105, vector<vd>(105, vd(3,-1))));
vector<vi> C(305, vi(305));

void add(vd &a, vd b) {
  a[0] += b[0];
  a[1] += b[1];
  a[2] += b[2];
}

void multScalar(vd &a, double b) {
  a[0] *= b;
  a[1] *= b;
  a[2] *= b;
}

vd rec(int R, int S, int P) {
  // cannot have negatives
  if (R < 0 || S < 0 || P < 0) return {0,0,0};

  if (R && !S && !P) return {1,0,0};
  else if (!R && S && !P) return {0,1,0};
  else if (!R && !S && P) return {0,0,1};
  else if (memo[R][S][P][0] != -1) return memo[R][S][P];

  int denom = R*S + P*R + S*P;

  memo[R][S][P] = {0,0,0};
  // R kill S
  if (R && S) {
    vd res = rec(R, S-1, P);
    multScalar(res, (double)(R*S)/denom);
    add(memo[R][S][P], res);
  }

  // P kill R
  if (P && R) {
    vd res = rec(R-1, S, P);
    multScalar(res, (double)(P*R)/denom);
    add(memo[R][S][P], res);
  }

  // S kill P
  if (S && P) {
    vd res = rec(R, S, P-1);
    multScalar(res, (double)(S*P)/denom);
    add(memo[R][S][P], res);
  }

  return memo[R][S][P];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  for (int i=0;i<305;i++) {
    C[i][0] = C[i][i] = 1;
    if (i == 0) continue;
    for (int j=1;j<i;j++) {
      C[i][j] = C[i-1][j-1] + C[i-1][j];
    }
  }

  cin >> R >> S >> P;

  vd ans = rec(R,S,P);
  cout << fixed << setprecision(10) << ans[0] << " " << ans[1] << " " << ans[2] << endl;

  return 0;
}
