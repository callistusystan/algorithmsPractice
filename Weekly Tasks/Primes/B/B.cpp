#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

/*
6 5 4 3 2 1
6 1 4 3 2 5
1 6 4 3 2 5
1 6 2 3 4 5
1 2 6 3 4 5
1 2 3 6 4 5
1 2 3 4 6 5
1 2 3 4 5 6
*/

vi isPrime(1e5+5);

vi fac , pr;
void fast_sieve (int n) {
  fac . assign (n + 1, 0);
  for (ll i = 2; i <= n; ++i) {
    if ( fac [i] == 0) fac [i] = i, pr. push_back (i);
    for (int p : pr) if (p > fac [i] || i * p > n) break ; else fac[i * p] = p;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  fast_sieve(1e5+5);
  sort(pr.begin(), pr.end());

  int N; cin >> N;
  vi nums(N+1), pos(N+1);
  for (int i=1;i<=N;i++) {
    cin >> nums[i];
    pos[nums[i]] = i;
  }

  vector<ii> ans;

  for (int cur=1;cur<=N;cur++) {
    // cerr << cur << endl;
    while (pos[cur] != cur) {
      // try to move as close to i
      int lo = -1, hi = (int)pr.size();

      int nBetween = pos[cur]-cur+1;
      // cerr << cur << " is at " << pos[cur] << " and is " << nBetween << " from " << cur << endl;

      while (lo != hi-1) {
        // cerr << "bs: " << lo << " " << hi << endl;
        int mid = (lo+hi)/2;
        if (pr[mid] <= nBetween) lo = mid;
        else hi = mid;
      }

      // pr[lo] <= pos[cur]-cur+1
      // swap pos[cur] with pos[pos[cur] - pr[lo] + 1]

      int swapTo;
      swapTo = pos[cur]-pr[lo]+1;
      ans.push_back({swapTo, pos[cur]});

      // we have cur, pos[cur], nAtSwapTo, swapTo
      int numberAtSwapTo;
      numberAtSwapTo = nums[swapTo];
      nums[swapTo] = cur;
      nums[pos[cur]] = numberAtSwapTo;

      int tmp = pos[numberAtSwapTo];
      pos[numberAtSwapTo] = pos[cur];
      pos[cur] = tmp;
    }
  }

  cout << ans.size() << endl;
  for (ii p : ans) {
    cout << p.first << " " << p.second<<endl;
  }

  return 0;
}
