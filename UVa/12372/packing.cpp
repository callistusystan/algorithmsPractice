#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    int L,W,H;
    cin >> L >> W >> H;

    printf("Case %d: %s\n", t, (L <= 20 && W <= 20 && H <= 20) ? "good" : "bad");
  }
  return 0;
}
