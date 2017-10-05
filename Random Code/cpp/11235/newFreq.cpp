#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

vi nums(1e5+5), start(1e5+5), cnt(1e5+5);

void solve(int N) {
  int Q; cin >> Q;
  for (int i=0;i<N;i++) {
    cin >> nums[i];
    if (i == 0) start[i] = 0;
    else if (nums[i] == nums[i-1]) start[i] = start[i-1];
    else start[i] = i;

    cnt[start[i]]++;
  }

  for (int i=0;i<Q;i++) {
    int l,r; cin >> l >> r; l--;r--;
    if (nums[l] == nums[r]) {
      cout << r-l+1 <<endl;
    } else {
      int a = l;
      int ans = 1;
      while (a < r) {
        int b = min(r, start[a]+cnt[start[a]]-1);
        ans = max(ans, b-a+1);
        a = start[a]+cnt[start[a]];
      }
      cout << ans << endl;
    }
  }
}

int main() {
  int N;
  while (cin >> N, N) {
    solve(N);
  }
  return 0;
}
