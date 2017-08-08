#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int T = 1;

void solve(int N) {
  cout << "Case " << T++ << ":" << endl;
  vi nums(N);
  for (int i=0;i<N;i++) cin >> nums[i];

  int Q; cin >> Q;
  for (int i=0;i<Q;i++) {
    int M; cin >> M;
    int diff = abs(nums[0] + nums[1] - M);
    int ans = nums[0] + nums[1];
    for (int j=0;j<N-1;j++) {
      for (int k=j+1;k<N;k++) {
        int curDiff = abs(nums[j] + nums[k] - M);
        if (curDiff < diff) {
          diff = curDiff;
          ans = nums[j] + nums[k];
        }
      }
    }

    printf("Closest sum to %d is %d.\n", M, ans);
  }
}

int main() {
  int N;
  while (cin >> N, N) {
    solve(N);
  }
  return 0;
}
