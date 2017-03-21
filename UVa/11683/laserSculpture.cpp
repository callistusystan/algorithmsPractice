#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, C;
  while (cin >> A, A) {
    cin >> C;
    vector<int> heights(C);
    for (int i=0;i<C;i++) {
      cin >> heights[i];
      heights[i]--;
    }

    bool laserOn = false;
    int count = 0;

    for (int i=A-1;i>=0;i--) {
      for (int j=0;j<C;j++) {
        if (i > heights[j]) {
          if (!laserOn) {
            laserOn = true;
            count++;
          }
        } else {
          laserOn = false;
        }
      }
      laserOn = false;
    }

    cout << count << endl;
  }
  return 0;
}
