#include <bits/stdc++.h>

using namespace std;

int main() {
  int t=1;
  string line;
  while (ws(cin) && getline(cin, line)) {
    int N;
    cin >> N;
    cout << "Case " << t++ << ":"<< endl;
    while (N--) {
      int i,j;
      cin >> i >> j;
      bool same = true;
      char prev = line[min(i,j)];
      for (int k=min(i,j)+1;k<max(i,j)+1;k++) {
        if (line[k] != prev) {
          same = false;
          break;
        }
        prev = line[k];
      }
      if (same) cout << "Yes";
      else cout << "No";
      cout << endl;
    }
  }
  return 0;
}
