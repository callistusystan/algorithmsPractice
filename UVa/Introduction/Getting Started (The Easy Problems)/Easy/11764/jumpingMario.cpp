#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    int N;
    cin >> N;
    int highJumps=0, lowJumps=0;

    int curHeight, prevHeight;
    cin >> prevHeight;
    N--;

    while(N--) {
      cin >> curHeight;
      if (curHeight > prevHeight)
        highJumps++;
      else if (curHeight < prevHeight)
        lowJumps++;
      prevHeight = curHeight;
    }

    printf("Case %d: %d %d\n", t, highJumps, lowJumps);
  }
  return 0;
}
