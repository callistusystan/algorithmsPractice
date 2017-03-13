#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  while (T--) {
    int a,b;
    cin >> a >> b;

    if (a < b)
      cout << "<";
    else if (a > b)
      cout << ">";
    else
      cout << "=";
    cout << endl;
  }
  return 0;
}
