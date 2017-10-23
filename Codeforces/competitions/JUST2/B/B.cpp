#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll MOD = 1e9+7;
int N;
string S;

vector<vector<bool>> isIJBeautiful(1e4+5, vector<bool>(1e4+5, false));
vector<vector<ll>> memo(1e4+5, vector<ll>(1e4+5, -1));

ll rec(int i, int j) {
  if (i > j) return 0;
  if (memo[i][j] != -1) return memo[i][j];

  ll ans = 0;
  for (int k=0;i<)
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> S;

  for (int i=0;i<N;i++) {
    for (int j=0;j<min(N-i,10);j++) {
      vector<bool> appeared(10, false);
      bool isBeautiful = true;
      for (int k=i;k<i+j;k++) {
        if (appeared[S[k]-'0']) {
          isBeautiful = false;
          break;
        }
        appeared[S[k]-'0'] = true;
      }
      if (isBeautiful) {
        isIJBeautiful[i][i+j] = true;
      } else break;
    }
  }
  ll ans = 0;



  cout << ans << endl;

  return 0;
}
