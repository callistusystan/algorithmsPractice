#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<double>> memo(2005,vector<double>(2005, -1));

double getLeadingPerms(int remainingA, int remainingB) {
  int usedA = N-remainingA;
  int usedB = M-remainingB;
  if ((usedA != 0 && usedB!= 0) && usedA <= usedB) {
    return 0;
  } else if (remainingA < 0 || remainingB < 0) {
    return 0;
  } else if (remainingA == 0 && remainingB == 0) {
    return 1;
  } else if (memo[remainingA][remainingB] > -0.5) {
    // cout << memo[remainingA][remainingB] << endl;
    return memo[remainingA][remainingB];
  }
  double probChooseA, probChooseB;
  probChooseA = (double)remainingA/(double)(remainingA+remainingB);
  probChooseB = (double)remainingB/(double)(remainingA+remainingB);

  double chooseA = getLeadingPerms(remainingA-1, remainingB);
  double chooseB = getLeadingPerms(remainingA, remainingB-1);

  double prob = probChooseA * chooseA;
  prob += probChooseB * chooseB;

  memo[remainingA][remainingB] = prob;

  return prob;
}

int main() {
  int T;

  cin >> T;

  for (int t=1;t<=T;t++) {
    cin >> N >> M;

    for (int i=0;i<=N;i++) {
      for (int j=0;j<=M;j++) {
        memo[i][j] = -1;
      }
    }

    double ans = getLeadingPerms(N, M);

    printf("Case #%d: %.8f\n", t, ans);
  }
  return 0;
}
