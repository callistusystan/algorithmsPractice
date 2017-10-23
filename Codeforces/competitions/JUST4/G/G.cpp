#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

vi nums(1e6+5), amax(1e6+5), amin(1e6+5);

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int T; cin >> T;
  while (T--) {
    int N; cin >> N;
    for (int i=0;i<N;i++)
      cin >> nums[i];

    amax[0] = nums[0];
    for (int i=1;i<N;i++) {
      amax[i] = max(amax[i-1], nums[i]);
    }

    amin[N-1] = nums[N-1];
    for (int i=N-2;i>=0;i--) {
      amin[i] = min(amin[i+1], nums[i]);
    }

    int ans = 0;
    for (int i=1;i<N-1;i++) {
      if (amax[i-1] <= nums[i] && nums[i] <= amin[i+1]) ans++;
    }

    cout << ans << '\n';
  }

  return 0;
}
