#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N; cin >> N;
  vi nums(N);
  for (int i=0;i<N;i++) cin >> nums[i];
  vvi ans(N+5); int reps = 1;
  ans[0].push_back(nums[0]);

  for (int i=1;i<N;i++) {
    int lo = -1, hi = reps;
    while (lo != hi-1) {
      int mid = (lo+hi)/2;
      if (ans[mid].back() > nums[i]) lo = mid;
      else hi = mid;
    }
    if (hi == reps) {
      ans[reps++].push_back(nums[i]);
    }
    else ans[hi].push_back(nums[i]);
  }

  for (vi a : ans) {
    for (int i=0;i<(int)a.size();i++) cout << a[i] << " \n"[i==(int)a.size()-1];
  }

  return 0;
}
