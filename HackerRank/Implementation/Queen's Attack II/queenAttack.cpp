// https://www.hackerrank.com/challenges/queens-attack-2

#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  int rQ, cQ;
  cin >> rQ >> cQ;

  vector<pair<int, int>> obstacles(K);
  // there are 8 distances
  int dUp=N-rQ, dRight=N-cQ, dDown=rQ-1, dLeft=cQ-1;
  int dUpRight=min(dUp, dRight), dRightDown=min(dRight,dDown), dDownLeft=min(dDown, dLeft), dLeftUp=min(dLeft, dUp);

  int rO,cO;

  for (int k=0;k<K;k++) {
    cin >> rO >> cO;

    if (cO == cQ) {
      if (rO > rQ) {
        dUp = min(dUp, rO-rQ-1);
      } else {
        dDown = min(dDown, rQ - rO-1);
      }
    } else if (rO == rQ) {
      if (cO < cQ) {
        dLeft = min(dLeft, cQ-cO-1);
      } else {
        dRight = min(dRight, cO-cQ-1);
      }
    } else if (abs(cO-cQ) == abs(rO-rQ)) {
      if (cO > cQ && rO > rQ) {
        dUpRight = min(dUpRight, abs(cO-cQ)-1);
      } else if (cO > cQ && rO < rQ) {
        dRightDown = min(dRightDown, abs(cO-cQ)-1);
      } else if (cO < cQ && rO < rQ) {
        dDownLeft = min(dDownLeft, abs(cO-cQ)-1);
      } else {
        dLeftUp = min(dLeftUp, abs(cO-cQ)-1);
      }
    }
  }
  // cout << dUp << " " << dUpRight << " " << dRight << " " << dRightDown << " " << dDown << " " << dDownLeft << " " << dLeft << " " << dLeftUp << endl;
  cout << dUp + dUpRight + dRight + dRightDown + dDown + dDownLeft + dLeft + dLeftUp << endl;

  return 0;
}
