#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

int N;
vi nums(105), primes, fact(60);
vector<vi> memo(100, vi(1<<16,-1)), B(100, vi(1<<16));

int rec(int cur, int b) {
  if (cur == N) return 0;
  else if (memo[cur][b] != -1) return memo[cur][b];

  memo[cur][b] = 1e9;
  for (int i=1;i<59;i++) {
    if (!(fact[i] & b)) {
      int newB = (b | fact[i]);
      int val = abs(i-nums[cur]) + rec(cur+1, newB);
      if (val < memo[cur][b]) {
        memo[cur][b] = val;
        B[cur][b] = i;
      }
    }
  }

  return memo[cur][b];
}

int main() {
  vi isPrime(59, 1);
  for (int i=2;i<59;i++) {
    if (isPrime[i]) {
      primes.push_back(i);
      for (int j=i+i;j<59;j+=i) {
        isPrime[j] = 0;
      }
    }
  }

  int nPrimes = primes.size();
  for (int i=2;i<59;i++) {
    for (int j=0;j<nPrimes;j++) {
      if (i%primes[j] == 0) fact[i] |= (1<<j);
    }
  }

  cin >> N;
  for (int i=0;i<N;i++) {
    cin >> nums[i];
  }

  rec(0,0);

  int b = 0;
  for (int i=0;i<N;i++) {
    if (i) cout << " ";
    cout << B[i][b];
    b |= fact[B[i][b]];
  }
  cout << endl;

  return 0;
}
