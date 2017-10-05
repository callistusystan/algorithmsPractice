#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void naive() {
  ll N, S; cin >> N >> S;

  ll ans = -1;
  for (ll i=pow(10,N-1);i<pow(10,N);i++) {
    if ((int)(log10(i) + 1) == N) {
      vector<int> nums;
      ll s = 0;
      ll tmp = i;
      while (tmp > 0) {
        s += tmp%10;
        nums.push_back(tmp%10);
        tmp/=10;
      }
      if (s != S) continue;
      bool isPalin = true;
      for (int k=0;k<N;k++) {
        if (nums[k] != nums[N-1-k]) { isPalin = false; break; }
      }
      if (!isPalin) continue;
      if (ans == -1 || i > ans) ans = i;
    }
  }

  cout << "ans: " << ans << endl;

}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
  // while (1) naive();
	int T; cin >> T;
	while (T--) {
    ll N,S; cin >> N >> S;
    if (S > 9*N || S == 1 || (N%2 == 0 && S%2 == 1)) cout << -1 << endl;
    else {
      if (N == 1 && S == 1) cout << 1 << endl;

      ll s = 0;
      vi nums1;
      for (int i=0;i<S/9;i++) nums.push_back(9);
      if (S2%9 > 0) nums.push_back(S2%9);
      while ((int)nums.size() < N/2) nums.push_back(0);
      for (int num : nums) cout << num;

      if (N%2 == 1) {
        if (S%2==1) cout << 1;
        else cout << 0;
      }
      for (int i=(int)nums.size()-1;i>=0;i--) cout << nums[i];
      cout << endl;
    }
	}
	return 0;
}
