#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;t++) {
    int N;
    cin >> N;
    int speed = 0;

    while(N--){
      int c;
      cin >> c;
      speed = max(speed, c);
    }

    printf("Case %d: %d\n", t, speed);
  }
  return 0;
}
