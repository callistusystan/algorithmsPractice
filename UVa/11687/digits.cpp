#include <bits/stdc++.h>

using namespace std;

int getDigits(int n) {
  int count = 0;
  if (n==0) return 1;
  while (n > 0) {
    count ++;
    n/=10;
  }
  return count;
}

int main() {
  string line;
  while (cin >> line, line != "END") {
    if (line == "1") {
      cout << 1 << endl;
      continue;
    }
    int i = 2;
    int x = (int)line.length();
    int newX = getDigits(x);
    while (newX != x) {
      x = newX;
      newX = getDigits(x);
      i++;
    }

    cout << i << endl;
  }
  return 0;
}
