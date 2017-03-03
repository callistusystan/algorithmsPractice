#include <bits/stdc++.h>

using namespace std;

vector<long long> maximumSubstrings(1000005, -1);

int main() {
  int T;
  cin >> T;

  for (int t=1;t<=T;t++) {
    int L, R;
    cin >> L >> R;
    int maximumPair = min(L, R);

    maximumSubstrings[0] = 0;
    for (int i=1;i<=maximumPair;i++) {
      maximumSubstrings[i] = maximumSubstrings[i-1] + i;
    }
    printf("Case #%d: %lld\n", t, maximumSubstrings[maximumPair]);
  }
  return 0;
}
