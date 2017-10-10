#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int REST = 0, CONTEST = 1, GYM = 2, BOTH = 3, N;
vi states(105);
vector<vi> memo(105, vi(3, -1));

int rec(int cur, int prev) {
  if (cur == N) return 0;
  if (memo[cur][prev] != -1) return memo[cur][prev];

  memo[cur][prev] = 105;
  memo[cur][prev] = min(memo[cur][prev], 1 + rec(cur+1,REST));
  if (prev != CONTEST && (states[cur] == CONTEST || states[cur] == BOTH)) {
    memo[cur][prev] = min(memo[cur][prev], rec(cur+1, CONTEST));
  }
  if (prev != GYM && (states[cur] == GYM || states[cur] == BOTH)) {
    memo[cur][prev] = min(memo[cur][prev], rec(cur+1,GYM));
  }

  return memo[cur][prev];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;

  for (int i=0;i<N;i++) {
    cin >> states[i];
  }

  cout << rec(0, 0) << endl;

  return 0;
}
