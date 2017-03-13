#include <bits/stdc++.h>

using namespace std;

int main() {
  int B,N;
  vector<int> bankReserves(25);
  while (cin >> B >> N, B || N) {
    for (int i=1;i<=B;i++) cin >> bankReserves[i];

    int D,C,V;
    for (int i=0;i<N;i++) {
      cin >> D >> C >> V;
      bankReserves[D]-=V;
      bankReserves[C]+=V;
    }

    bool possible = true;

    for (int i=1;i<=B;i++) {
      if (bankReserves[i] < 0) {
        possible=false;
        break;
      }
    }

    cout << ((possible) ? "S" : "N") << endl;
  }
  return 0;
}
