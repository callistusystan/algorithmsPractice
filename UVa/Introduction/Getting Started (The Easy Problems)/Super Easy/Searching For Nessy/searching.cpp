#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int n,m;
    cin >> n >> m;

    int colNeeded, rowNeeded;
    colNeeded = ceil((n-2.0)/3);
    rowNeeded = ceil((m-2.0)/3);

    cout << colNeeded*rowNeeded << endl;
  }
  return 0;
}
