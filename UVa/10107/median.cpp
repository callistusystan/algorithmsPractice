#include <bits/stdc++.h>

using namespace std;

int main() {
  int X;
  vector<int> nums;
  while (cin >> X) {
    nums.push_back(X);
    sort(nums.begin(), nums.end());

    int N = nums.size();
    if (N%2 == 0) {
      cout << (nums[N/2-1]+nums[N/2])/2 << endl;
    } else cout << nums[N/2] << endl;
  }
}
