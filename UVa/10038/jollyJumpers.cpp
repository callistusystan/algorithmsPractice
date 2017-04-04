#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  while (cin >> N) {
    vector<bool> appeared(N, false);
    appeared[0] = true;
    vector<int> nums(N);
    for (int i=0;i<N;i++) cin >> nums[i];

    bool isJolly = true;
    for (int i=1;i<N;i++) {
      int diff = abs(nums[i]-nums[i-1]);
      if (appeared[diff]) {
        isJolly = false;
        break;
      }
      appeared[diff] = true;
    }

    bool allAppeared = true;
    for (bool val : appeared) {
      if (!val) {
        allAppeared = false;
        break;
      }
    }

    if (isJolly && allAppeared) cout << "Jolly";
    else cout << "Not jolly";
    cout << endl;
  }
}
