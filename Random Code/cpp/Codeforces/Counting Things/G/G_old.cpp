#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int MOD = 1e9+7, N;
string S;
vector<vi> memo(105, vi(55));

void add(int &a, int b) {
  a += b;
  if (a >= MOD) a-=MOD;
}

void sub(int &a, int b) {
  a -= b;
  if (a < 0) a+=MOD;
}

void mult(int &a, int b) {
  a = ((ll)a*b)%MOD;
}

int rec(int id, int prevOp) {
  if (S[id] - prevOp < 'a' || S[id] - prevOp > 'z') return 0;
  cout << id << " " << prevOp << '\n';
  if (id == N-1) return 1;
  if (memo[id][prevOp+25] != -1) return memo[id][prevOp+25];

  int ans = 0;
  for (int i=-25;i<=25;i++) {
    if ('a' <= S[id]-prevOp+i && S[id]-prevOp+i <= 'z')
      add(ans, rec(id+1, i));
  }

  memo[id][prevOp+25] = ans;
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;
  while (T--) {
    cin >> S;
    N = S.size();
    for (int i=0;i<105;i++)
      for (int j=0;j<55;j++)
        memo[i][j] = -1;
    int ans = rec(0,0);
    sub(ans, 1);
    cout << ans << '\n';
  }

  return 0;
}
