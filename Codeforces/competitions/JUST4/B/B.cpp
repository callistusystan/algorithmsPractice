#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int mod(int a, int m) {
  int ans = a%m;
  if (ans < 0) ans += m;
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int T; cin >> T;
  while (T--) {
    int N, M; cin >> N >> M;
    vi nums(N);
    int notLost = -1;
    for (int i=0;i<N;i++) {
      cin >> nums[i];

      if (nums[i] != -1) notLost = i;
    }

    int cur = nums[notLost];
    for (int i=notLost-1;i>=0;i--) {
      cur--;
      nums[i] = mod(cur, M);
    }

    cur = nums[notLost];
    for (int i=notLost+1;i<N;i++) {
      cur++;
      nums[i] = mod(cur, M);
    }

    for (int i=0;i<N;i++) {
      if (i) cout << " ";
      cout << nums[i];
    }
    cout << endl;
  }

  return 0;
}
