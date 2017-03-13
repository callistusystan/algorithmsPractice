#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int W;
    cin >> W;
    vector<pair<int, int>> columns(W);

    for (int i=0;i<W;i++) {
      int north, south;
      cin >> north >> south;

      columns[i] = make_pair(north, south);
    }

    int gapSize = abs(columns[0].first-columns[0].second) - 1;

    bool valid = true;
    for (int i=1;i<W;i++) {
      if (abs(columns[i].first-columns[i].second) - 1 != gapSize) {
        valid = false;
        break;
      }
    }

    if (valid) cout << "yes";
    else cout << "no";
    cout << endl;

    if (T) cout << endl;
  }
  return 0;
}
