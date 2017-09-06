#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<ll> vll;
typedef vector<vll> vvll;

vvll memo(105, vll(105, -1));
ll MOD_VALUE = 1e6;

ll rec(int N, int K) {
  if (K == 1) return 1;
  if (memo[N][K] != -1) return memo[N][K];

  ll nWays = 0;
  for (int i=0;i<=N;i++) {
    nWays += rec(N-i, K-1);
    nWays %= MOD_VALUE;
  }
  memo[N][K] = nWays;
  return nWays;
}

void solve(int N, int K) {
  cout << rec(N, K) << endl;
}

int main() {
  int N, K;
  while (cin >> N >> K, N || K)
    solve(N, K);
  return 0;
}
