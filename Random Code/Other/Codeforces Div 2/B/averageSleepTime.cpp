#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

void solve() {
  int N, K; cin >> N >> K;

  vector<ll> nums(N);
  for (int i=0;i<N;i++) {
    cin >> nums[i];
    if (i) nums[i] += nums[i-1];
  }

  double weeks = N-K+1;

  double ans = 0;
  for (int i=K-1;i<N;i++) {
    double unwanted = 0;
    if (i-K>=0) unwanted = nums[i-K];
    ans += (nums[i]-unwanted);
  }
  ans/= weeks;

  printf("%.6lf\n", ans);

}

int main() {
  solve();
  return 0;
}
