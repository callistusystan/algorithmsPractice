#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void solve(int N) {
  vi nums(N);
  for (int i=0;i<N;i++) {
    cin >> nums[i];
  }

  int curSum, ans = 0;
  curSum = ans = 0;
  for (int i=0;i<N;i++) {
    curSum += nums[i];
    ans = max(ans, curSum);
    if (curSum < 0) curSum = 0;
  }

  if (ans == 0)
    cout << "Losing streak." << endl;
  else
    printf("The maximum winning streak is %d.\n", ans);

}

int main() {
  int N;
  while (cin >> N, N) {
    solve(N);
  }
  return 0;
}
