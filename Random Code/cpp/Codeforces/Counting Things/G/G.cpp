#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int MOD = 1e9+7, N;
string S;
vector<vi> memo(105, vi(2605,-1));

void add(int &a, int b) {
  a += b;
  if (a >= MOD) a-=MOD;
}

void sub(int &a, int b) {
  a -= b;
  if (a < 0) a+=MOD;
}

int rec(int id, int sum) {
  if (id == 0 && sum != 0) return 0;
  if (id == 0 && sum == 0) return 1;
  if (memo[id][sum] != -1) return memo[id][sum];

  int ans = 0;
  for (int i=1;i<=26;i++) {
    if (sum-i >= 0)
      add(ans, rec(id-1, sum - i));
  }

  memo[id][sum] = ans;
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int T; cin >> T;
  while (T--) {
    cin >> S;
    N = S.size();

    int sum = 0;
    for (int c: S) {
      sum += c- 'a' + 1;
    }
    int ans = rec(N, sum);
    sub(ans, 1);
    cout << ans << '\n';
  }

  return 0;
}
