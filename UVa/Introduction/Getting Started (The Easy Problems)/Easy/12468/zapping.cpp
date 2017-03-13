#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  while (cin >> a >> b, a != -1 && b != -1) {
    int goForward, goBack;
    goForward = b-a >= 0 ? b-a : b-a+100;
    goBack = a-b >= 0 ? a-b : a-b+100;
    cout << min(goForward, goBack) << endl;
  }
  return 0;
}
