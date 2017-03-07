#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  int total = 0;
  while (T--) {
    string action;
    int amount;
    cin >> action;
    if (action == "donate") {
      cin >> amount;
      total += amount;
    } else
    cout << total << endl;
  }
  return 0;
}
