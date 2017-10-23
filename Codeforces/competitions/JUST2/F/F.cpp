#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  int N; cin >> N;
  vi nums(N);
  for (int i=0;i<N;i++) cin >> nums[i];
  sort(nums.begin(), nums.end());
  int M; cin >> M;
  for (int i=0;i<M;i++) {
    int num; cin >> num;
    auto it = lower_bound(nums.begin(), nums.end(), num);
    if (it == nums.end()) {
      cout << "Dr. Samer cannot take any offer :(." << endl;
    } else {
      cout << *it << endl;
    }
  }
  return 0;
}
