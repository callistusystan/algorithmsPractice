#include <bits/stdc++.h>

using namespace std;

int main() {
  int S, B;
  while (cin >> S >> B, S || B) {
    vector<int> leftBud(100005);
    vector<int> rightBud(100005);
    for (int i=1;i<=S;i++) {
      leftBud[i] = i-1;
      rightBud[i] = i+1;
    }
    leftBud[0] =0; rightBud[0] =0;
    leftBud[1] = 0; rightBud[S] = 0;

    for (int i=0;i<B;i++) {
      int L, R;
      cin >> L >> R;

      int aliveL, aliveR;
      aliveL = leftBud[L]; aliveR = rightBud[R];

      rightBud[aliveL] = aliveR;
      leftBud[aliveR] = aliveL;

      if (aliveL == 0) cout << "*";
      else cout << aliveL;
      cout << " ";
      if (aliveR == 0) cout << "*";
      else cout << aliveR;
      cout << endl;
    }
    cout << "-" << endl;
  }
  return 0;
}
