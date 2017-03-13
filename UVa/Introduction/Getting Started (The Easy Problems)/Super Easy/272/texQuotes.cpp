#include <bits/stdc++.h>

using namespace std;

int main() {
  string line;
  bool isBackTick = true;
  while (getline(cin, line)) {
    int n = line.size();
    for (int i=0;i < n;i++) {
      if (line[i] == '"') {
        if (isBackTick) cout << "``";
        else cout << "''";
        isBackTick = !isBackTick;
      } else {
        cout << line[i];
      }
    }
    cout << endl;
  }
  return 0;
}
