#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M, C;
  int t= 1;
  while (cin >> N >> M >> C, N || M || C) {
    vector<bool> isOn(25, false);
    vector<int> consumption(25);
    printf("Sequence %d\n", t++);
    for (int i=1;i<=N;i++) {
      cin >> consumption[i];
    }

    bool fuseBlown = false;
    int totalConsumption = 0, maxConsumption =0;
    for (int i=1;i<=M;i++) {
      int device;
      cin >> device;
      if (!isOn[device]) {
        totalConsumption += consumption[device];
        isOn[device] = !isOn[device];
      } else {
        totalConsumption -= consumption[device];
        isOn[device] = !isOn[device];
      }

      maxConsumption = max(maxConsumption, totalConsumption);

      if (totalConsumption > C) {
        fuseBlown = true;
      }
    }

    if (fuseBlown) {
      cout << "Fuse was blown.";
    } else {
      cout << "Fuse was not blown.";
    }
    cout << endl;

    if (!fuseBlown) {
      cout << "Maximal power consumption was " << maxConsumption << " amperes." << endl;
    }
    cout << endl;
  }
  return 0;
}
