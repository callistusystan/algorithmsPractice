#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n;
    cin >> n;

    int minVal = 100, maxVal = -1, val;
    for (int i=0;i<n;i++) {
      cin >> val;
      minVal = min(minVal, val);
      maxVal = max(maxVal, val);
    }

    cout << (maxVal-minVal)*2 << endl;
  }
  return 0;
}
