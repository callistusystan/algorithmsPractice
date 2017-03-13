#include <bits/stdc++.h>

using namespace std;

int main() {
  int L;
  while (cin >> L, L) {
    char c;
    int minDistance = 2000005;
    int prevD = -1, prevR = -1;
    for (int i=0;i<L;i++) {
      cin >> c;
      if (c == 'R') {
        if (prevD != -1)
          minDistance = min(minDistance, i-prevD);
        prevR = i;
      }
      if (c == 'D') {
        if (prevR != -1)
          minDistance = min(minDistance, i-prevR);
        prevD = i;
      }
      if (c == 'Z') minDistance = 0;
    }

    cout << minDistance << endl;
  }
  return 0;
}
