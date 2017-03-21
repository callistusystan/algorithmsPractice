#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    int N;
    cin >> N;

    int costMile = 0, costJuice = 0;
    int callDuration;
    while (N--) {
      cin >> callDuration;
      costMile += (callDuration/30 + 1)*10;
      costJuice += (callDuration/60 + 1)*15;
    }
    printf("Case %d: ", t);
    if (costMile == costJuice) {
      cout << "Mile Juice " << costMile;
    } else if (costMile < costJuice) {
      cout << "Mile " << costMile;
    } else {
      cout << "Juice " << costJuice;
    }
    cout << endl;
  }
  return 0;
}
