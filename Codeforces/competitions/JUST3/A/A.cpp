#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
  int T; cin >> T;
  while (T--) {
    int y,x; cin >> y >> x;
    cout << (y*100)/(100+x) << endl;
  }
  return 0;
}
