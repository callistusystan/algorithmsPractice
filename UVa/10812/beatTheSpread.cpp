#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int S, D;
    cin >> S >> D;
    int a,b;
    bool isPos = false;
    for (a=S;a>=0;a--) {
      b = S-a;
      if (abs(a-b) == D) {
        isPos = true;
        break;
      }
    }
    if (isPos) cout << a << " " << b << endl;
    else cout << "impossible" << endl;
  }
  return 0;
}
