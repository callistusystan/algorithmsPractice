#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int N, K;
vi coins(505);
// vector<vector<vi>> memo(505, vector<vi>(505, vi(505,-1)));
int memo[2][505][505];

// bool rec(int cur, int remain1, int remain2) {
//   if (remain1 < 0 || remain2 < 0) return 0;
//   else if (cur == N && remain1 == 0 && remain2 == 0) return 1;
//   else if (cur == N) return 0;
//   else if (memo[cur][remain1][remain2] != -1) return memo[cur][remain1][remain2];
//
//   memo[cur][remain1][remain2] = 0;
//
//   bool res1,res2,res3;
//   res1 = rec(cur+1, remain1, remain2);
//   res2 = rec(cur+1, remain1-coins[cur], remain2);
//   res3 = rec(cur+1, remain1-coins[cur], remain2-coins[cur]);
//
//   if (res1 || res2 || res3)
//     memo[cur][remain1][remain2] = 1;
//
//   return memo[cur][remain1][remain2];
// }

int main() {
  cin >> N >> K;

  for (int i=1;i<=N;i++)
    cin >> coins[i];

  sort(coins.begin()+1, coins.begin()+1+N);

  memo[0][0][0] = 1;
  for (int i=1;i<=N;i++) {
    for (int j=0;j<=K;j++) {
      for (int k=0;k<=K;k++) {
        memo[i%2][j][k] = memo[(i+1)%2][j][k];
        if (j >= coins[i]) {
          memo[i%2][j][k] |= memo[(i+1)%2][j-coins[i]][k];
          if (k >= coins[i]) {
            memo[i%2][j][k] |= memo[(i+1)%2][j-coins[i]][k-coins[i]];
          }
        }
      }
    }
  }

  vi canMake;
  for (int i=0;i<=K;i++) {
    if (memo[N%2][K][i]) canMake.push_back(i);
  }

  N = canMake.size();
  cout << N << endl;
  for (int i=0;i<N;i++) {
    cout << canMake[i] << " \n"[i==N-1];
  }

  return 0;
}
