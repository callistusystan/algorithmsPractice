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

int rec(int f, int k) {
  if (f < 0 || k < 0) return 0;
  if (f == B || f >= N) return rec(f-1, k);
  if (k == 0) {
    int ans = rec(f-1,k);
    add(ans, 1);
    return ans;
  }
  // cerr << f << " " << k << endl;
  // cerr << " check if computed" << endl;
  if (memo[f][k] != -1) return memo[f][k];

  // cerr << " init" << endl;
  memo[f][k] = 0;

  int d = abs(B-f)-1;
  // cerr << " computing" << endl;
  if (d > 0) {
    memo[f][k] = rec(min(f+d, N-1),k-1);
    sub(memo[f][k], rec(f,k-1));
    add(memo[f][k], rec(f-1,k-1));
    sub(memo[f][k], rec(f-d-1,k-1));
    // cerr << " done" << endl;
  }

  add(memo[f][k], rec(f-1,k));

  // cerr << " returning" << endl;
  return memo[f][k];
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  cin >> N >> A >> B >> K;
  A--; B--;
  int ans = rec(A,K);
  sub(ans, rec(A-1,K));
  cout << ans << endl;

  return 0;
}
