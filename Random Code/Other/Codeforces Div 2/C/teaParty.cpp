#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

void solve() {
  int N, W; cin >> N >> W;
  vector<pii> nums(N);
  int sum = 0, myMin = 0;
  for (int i=0;i<N;i++){
    int w;
    cin >> w;
    nums[i] = make_pair(w, i);
    sum += w;
    myMin += (w+1)/2;
  }

  if (W < myMin || W > sum) {
    cout << -1 << endl;
    return;
  }

  sort(nums.begin(), nums.end());

  vi ans(N);

  for (int i=0;i<N;i++) {
    pii p = nums[i];

    ans[p.second] = (p.first+1)/2;
    W -= ans[p.second];
  }

  int i = N-1;
  while (W > 0) {
    pii p = nums[i];
    int cup = p.second, capacity = p.first - ans[cup];

    int amountToPour = min(capacity, W);
    ans[cup] += amountToPour;
    W -= amountToPour;
    i--;
  }

  for (int i=0;i<N;i++) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}

int main() {
  solve();
  return 0;
}
