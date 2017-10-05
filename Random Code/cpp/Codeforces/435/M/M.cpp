#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int N; cin >> N;
  vi nums(N);
  for (int i=0;i<N;i++) {
    cin >> nums[i];
  }

  int d = nums[1] -nums[0];
  bool isArith = true;
  for (int i=1;i<N;i++) {
    if (nums[i] - nums[i-1] != d) {
      isArith = false;
      break;
    }
  }

  if (isArith) cout << nums[N-1] + d << endl;
  else cout << nums[N-1] << endl;
  return 0;
}
