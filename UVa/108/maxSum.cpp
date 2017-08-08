#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(int N) {
  vvi cS(N, vi(N));
  for (int i=0;i<N;i++) {
    for (int j=0;j<N;j++) {
      cin >> cS[i][j];
      if (i)
        cS[i][j] += cS[i-1][j];
      if (j)
        cS[i][j] += cS[i][j-1];
      if (i && j)
        cS[i][j] -= cS[i-1][j-1];
    }
  }

/*
  0 1 2 3
0
1     *
2
3       *
*/

  int ans = cS[0][0];
  for (int i=0;i<N;i++) for (int j=0;j<N;j++)
    for (int k=i;k<N;k++) for (int l=j;l<N;l++) {
      int sumOfRange = cS[k][l];
      if (i)
        sumOfRange -= cS[i-1][l];
      if (j)
        sumOfRange -= cS[k][j-1];
      if (i && j)
        sumOfRange += cS[i-1][j-1];
      ans = max(ans, sumOfRange);
    }

  cout << ans << endl;
}

int main() {
  int N;
  while (cin >> N) {
    solve(N);
  }
  return 0;
}
