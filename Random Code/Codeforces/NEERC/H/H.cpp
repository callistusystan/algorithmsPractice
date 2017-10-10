#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N; cin >> N;

  vector<ll> nums(N+5);
  for (int i=0;i<N;i++) cin >> nums[i];

  vector<ll> prefixSum(N+5), suffixSum(N+5);
  vi prefixLast(N+5), suffixLast(N+5);

  ll sum, last;
  sum = last = 0;
  for (int i=0;i<N;i++) {
    ll cur = max(last+1, nums[i]);
    sum += cur - nums[i];
    prefixSum[i] = sum;
    last = cur;
    prefixLast[i] = last;
  }

  sum = last = 0;
  for (int i=N-1;i>=0;i--) {
    ll cur = max(last+1, nums[i]);
    sum += cur - nums[i];
    suffixSum[i] = sum;
    last = cur;
    suffixLast[i] = last;
  }

  ll ans = LLONG_MAX;
  for (int i=0;i<N;i++) {
    ll cur1 = prefixSum[i] + suffixSum[i];
    cur1 -= prefixLast[i] - nums[i];
    cur1 -= suffixLast[i] - nums[i];
    cur1 += max(prefixLast[i], suffixLast[i]) - nums[i];
    ll cur2 = prefixSum[i] + suffixSum[i];
    cur2 -= prefixLast[i] - nums[i];
    cur2 -= suffixLast[i] - nums[i];
    cur2 += max(prefixLast[i], suffixLast[i]) - nums[i];
    cerr << cur1 << " " << cur2 << endl;
    ans = min(ans, cur1);
  }

  cout << ans << endl;

  return 0;
}
